#include "rgb_lcd_port.h"

#include "gpio.h"
#include "i2c.h"

const char *TAG = "example";
static esp_lcd_panel_handle_t panel_handle = NULL;
esp_err_t waveshare_esp32_s3_rgb_lcd_init(esp_lv_adapter_tear_avoid_mode_t tear_mode,
                                          esp_lv_adapter_rotation_t rotation,
                                          esp_lcd_panel_handle_t *out_panel_handle,
                                          esp_lcd_touch_handle_t *out_touch_handle)
{
    if ((out_panel_handle == NULL) || (out_touch_handle == NULL)) {
        return ESP_ERR_INVALID_ARG;
    }

    *out_panel_handle = NULL;
    *out_touch_handle = NULL;

    const uint8_t num_fbs = esp_lv_adapter_get_required_frame_buffer_count(tear_mode, rotation);

    ESP_LOGI(TAG, "Install RGB LCD panel driver");
    esp_lcd_rgb_panel_config_t panel_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .timings = {
            .pclk_hz = EXAMPLE_LCD_PIXEL_CLOCK_HZ,
            .h_res = EXAMPLE_LCD_H_RES,
            .v_res = EXAMPLE_LCD_V_RES,
            .hsync_pulse_width = 162,
            .hsync_back_porch = 152,
            .hsync_front_porch = 48,
            .vsync_pulse_width = 45,
            .vsync_back_porch = 13,
            .vsync_front_porch = 3,
            .flags = {
                .pclk_active_neg = 1,
            },
        },
        .data_width = EXAMPLE_RGB_DATA_WIDTH,
        .bits_per_pixel = EXAMPLE_RGB_BIT_PER_PIXEL,
        .num_fbs = num_fbs,
        .bounce_buffer_size_px = EXAMPLE_RGB_BOUNCE_BUFFER_SIZE,
        .sram_trans_align = 4,
        .psram_trans_align = 64,
        .hsync_gpio_num = EXAMPLE_LCD_IO_RGB_HSYNC,
        .vsync_gpio_num = EXAMPLE_LCD_IO_RGB_VSYNC,
        .de_gpio_num = EXAMPLE_LCD_IO_RGB_DE,
        .pclk_gpio_num = EXAMPLE_LCD_IO_RGB_PCLK,
        .disp_gpio_num = EXAMPLE_LCD_IO_RGB_DISP,
        .data_gpio_nums = {
            EXAMPLE_LCD_IO_RGB_DATA0, EXAMPLE_LCD_IO_RGB_DATA1, EXAMPLE_LCD_IO_RGB_DATA2, EXAMPLE_LCD_IO_RGB_DATA3,
            EXAMPLE_LCD_IO_RGB_DATA4, EXAMPLE_LCD_IO_RGB_DATA5, EXAMPLE_LCD_IO_RGB_DATA6, EXAMPLE_LCD_IO_RGB_DATA7,
            EXAMPLE_LCD_IO_RGB_DATA8, EXAMPLE_LCD_IO_RGB_DATA9, EXAMPLE_LCD_IO_RGB_DATA10, EXAMPLE_LCD_IO_RGB_DATA11,
            EXAMPLE_LCD_IO_RGB_DATA12, EXAMPLE_LCD_IO_RGB_DATA13, EXAMPLE_LCD_IO_RGB_DATA14, EXAMPLE_LCD_IO_RGB_DATA15,
        },
        .flags = {
            .fb_in_psram = 1,
        },
    };
    ESP_ERROR_CHECK(esp_lcd_new_rgb_panel(&panel_config, &panel_handle));
    ESP_LOGI(TAG, "Initialize RGB LCD panel");
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
    *out_panel_handle = panel_handle;

    DEV_I2C_Port port = DEV_I2C_Init();
    IO_EXTENSION_Init();
    DEV_GPIO_Mode(EXAMPLE_TOUCH_INT_GPIO, GPIO_MODE_INPUT_OUTPUT);
    IO_EXTENSION_Output(IO_EXTENSION_IO_1, 0);
    vTaskDelay(pdMS_TO_TICKS(100));
    DEV_Digital_Write(EXAMPLE_TOUCH_INT_GPIO, 0);
    vTaskDelay(pdMS_TO_TICKS(100));
    IO_EXTENSION_Output(IO_EXTENSION_IO_1, 1);
    vTaskDelay(pdMS_TO_TICKS(200));

    esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    esp_lcd_panel_io_i2c_config_t tp_io_config = ESP_LCD_TOUCH_IO_I2C_GT911_CONFIG();
    tp_io_config.scl_speed_hz = EXAMPLE_I2C_MASTER_FREQUENCY;
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i2c(port.bus, &tp_io_config, &tp_io_handle));

    const esp_lcd_touch_config_t tp_cfg = {
        .x_max = EXAMPLE_LCD_H_RES,
        .y_max = EXAMPLE_LCD_V_RES,
        .rst_gpio_num = EXAMPLE_TOUCH_RST_GPIO,
        .int_gpio_num = EXAMPLE_TOUCH_INT_GPIO,
        .levels = {
            .reset = 0,
            .interrupt = 0,
        },
        .flags = {
            .swap_xy = 0,
            .mirror_x = 0,
            .mirror_y = 0,
        },
    };
    ESP_ERROR_CHECK(esp_lcd_touch_new_i2c_gt911(tp_io_handle, &tp_cfg, out_touch_handle));
    return ESP_OK;
}

void wavesahre_rgb_lcd_display_window(int16_t Xstart, int16_t Ystart, int16_t Xend, int16_t Yend, uint8_t *Image)
{
    esp_lcd_panel_draw_bitmap(panel_handle, Xstart, Ystart, Xend, Yend, Image);
}

void wavesahre_rgb_lcd_display(uint8_t *Image)
{
    esp_lcd_panel_draw_bitmap(panel_handle, 0, 0, EXAMPLE_LCD_H_RES, EXAMPLE_LCD_V_RES, Image);
}

void waveshare_get_frame_buffer(void **buf1, void **buf2)
{
    ESP_ERROR_CHECK(esp_lcd_rgb_panel_get_frame_buffer(panel_handle, 2, buf1, buf2));
}

void waveahre_rgb_lcd_set_pclk(uint32_t freq_hz)
{
    esp_lcd_rgb_panel_set_pclk(panel_handle, freq_hz);
}

void waveshare_rgb_lcd_restart(void)
{
    esp_lcd_rgb_panel_restart(panel_handle);
}

void wavesahre_rgb_lcd_bl_on(void)
{
    IO_EXTENSION_Output(IO_EXTENSION_IO_2, 1);
}

void wavesahre_rgb_lcd_bl_off(void)
{
    IO_EXTENSION_Output(IO_EXTENSION_IO_2, 0);
}
