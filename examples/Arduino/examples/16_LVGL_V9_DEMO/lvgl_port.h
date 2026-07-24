#pragma once

#include <stdint.h>

#include "esp_err.h"
#include "esp_lcd_types.h"
#include "lvgl.h"
#include "rgb_lcd_port.h"
#include "touch.h"

#define LVGL_PORT_TICK_PERIOD_MS    (2)
#define LVGL_PORT_TASK_MAX_DELAY_MS (500)
#define LVGL_PORT_TASK_MIN_DELAY_MS (2)
#define LVGL_PORT_TASK_STACK_SIZE   (8 * 1024)
#define LVGL_PORT_TASK_PRIORITY     (2)
#define LVGL_PORT_TASK_CORE         (1)

esp_err_t lvgl_port_init(esp_lcd_panel_handle_t lcd_handle, esp_lcd_touch_handle_t tp_handle);
bool lvgl_port_lock(int timeout_ms);
void lvgl_port_unlock(void);
bool lvgl_port_notify_rgb_vsync(void);
