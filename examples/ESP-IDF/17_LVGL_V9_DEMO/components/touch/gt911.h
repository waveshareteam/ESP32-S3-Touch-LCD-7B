#pragma once

#include "esp_lcd_touch.h"

#define ESP_LCD_TOUCH_IO_I2C_GT911_ADDRESS          (0x5D)
#define ESP_LCD_TOUCH_IO_I2C_GT911_ADDRESS_BACKUP   (0x14)

#define EXAMPLE_PIN_NUM_TOUCH_RST       (-1)
#define EXAMPLE_PIN_NUM_TOUCH_INT       (GPIO_NUM_4)

typedef struct {
    uint8_t dev_addr;
} esp_lcd_touch_io_gt911_config_t;

esp_err_t esp_lcd_touch_new_i2c_gt911(const esp_lcd_panel_io_handle_t io,
                                      const esp_lcd_touch_config_t *config,
                                      esp_lcd_touch_handle_t *out_touch);

esp_lcd_touch_handle_t touch_gt911_init(void);

#define ESP_LCD_TOUCH_IO_I2C_GT911_CONFIG()           \
    {                                                 \
        .dev_addr = ESP_LCD_TOUCH_IO_I2C_GT911_ADDRESS,   \
        .scl_speed_hz = EXAMPLE_I2C_MASTER_FREQUENCY,     \
        .control_phase_bytes = 1,                         \
        .dc_bit_offset = 0,                               \
        .lcd_cmd_bits = 16,                               \
        .flags =                                          \
        {                                                 \
            .disable_control_phase = 1,                   \
        }                                                 \
    }
