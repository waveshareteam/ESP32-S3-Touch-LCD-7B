#ifndef _RGB_LCD_H_
#define _RGB_LCD_H_
#pragma once
#include "esp_err.h"
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "driver/gpio.h"
#include "io_extension.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_lcd_touch.h"
#include "esp_lcd_touch_gt911.h"
#include "esp_lv_adapter.h"
#define EXAMPLE_LCD_H_RES               (1024)
#define EXAMPLE_LCD_V_RES               (600)
#define EXAMPLE_LCD_PIXEL_CLOCK_HZ      (24 * 1000 * 1000)
#define EXAMPLE_LCD_BIT_PER_PIXEL       (16)
#define EXAMPLE_RGB_BIT_PER_PIXEL       (16)
#define EXAMPLE_RGB_DATA_WIDTH          (16)
#define EXAMPLE_LCD_RGB_BUFFER_NUMS     (2)
#define EXAMPLE_RGB_BOUNCE_BUFFER_SIZE  (EXAMPLE_LCD_H_RES * 20)
#define EXAMPLE_LCD_IO_RGB_DISP         (-1)
#define EXAMPLE_LCD_IO_RGB_VSYNC        (GPIO_NUM_3)
#define EXAMPLE_LCD_IO_RGB_HSYNC        (GPIO_NUM_46)
#define EXAMPLE_LCD_IO_RGB_DE           (GPIO_NUM_5)
#define EXAMPLE_LCD_IO_RGB_PCLK         (GPIO_NUM_7)
#define EXAMPLE_LCD_IO_RGB_DATA0        (GPIO_NUM_14)
#define EXAMPLE_LCD_IO_RGB_DATA1        (GPIO_NUM_38)
#define EXAMPLE_LCD_IO_RGB_DATA2        (GPIO_NUM_18)
#define EXAMPLE_LCD_IO_RGB_DATA3        (GPIO_NUM_17)
#define EXAMPLE_LCD_IO_RGB_DATA4        (GPIO_NUM_10)
#define EXAMPLE_LCD_IO_RGB_DATA5        (GPIO_NUM_39)
#define EXAMPLE_LCD_IO_RGB_DATA6        (GPIO_NUM_0)
#define EXAMPLE_LCD_IO_RGB_DATA7        (GPIO_NUM_45)
#define EXAMPLE_LCD_IO_RGB_DATA8        (GPIO_NUM_48)
#define EXAMPLE_LCD_IO_RGB_DATA9        (GPIO_NUM_47)
#define EXAMPLE_LCD_IO_RGB_DATA10       (GPIO_NUM_21)
#define EXAMPLE_LCD_IO_RGB_DATA11       (GPIO_NUM_1)
#define EXAMPLE_LCD_IO_RGB_DATA12       (GPIO_NUM_2)
#define EXAMPLE_LCD_IO_RGB_DATA13       (GPIO_NUM_42)
#define EXAMPLE_LCD_IO_RGB_DATA14       (GPIO_NUM_41)
#define EXAMPLE_LCD_IO_RGB_DATA15       (GPIO_NUM_40)
#define EXAMPLE_LCD_IO_RST              (-1)
#define EXAMPLE_PIN_NUM_BK_LIGHT        (-1)
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL   (1)
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL  (!EXAMPLE_LCD_BK_LIGHT_ON_LEVEL)

#define EXAMPLE_TOUCH_RST_GPIO          (-1)
#define EXAMPLE_TOUCH_INT_GPIO          (GPIO_NUM_4)
esp_err_t waveshare_esp32_s3_rgb_lcd_init(esp_lv_adapter_tear_avoid_mode_t tear_mode,
                                          esp_lv_adapter_rotation_t rotation,
                                          esp_lcd_panel_handle_t *panel_handle,
                                          esp_lcd_touch_handle_t *touch_handle);
void wavesahre_rgb_lcd_bl_on(void);
void wavesahre_rgb_lcd_bl_off(void);
void wavesahre_rgb_lcd_display_window(int16_t Xstart, int16_t Ystart, int16_t Xend, int16_t Yend, uint8_t *Image);
void wavesahre_rgb_lcd_display(uint8_t *Image);
void waveshare_get_frame_buffer(void **buf1, void **buf2);
void waveahre_rgb_lcd_set_pclk(uint32_t freq_hz);
void waveshare_rgb_lcd_restart(void);
#endif


