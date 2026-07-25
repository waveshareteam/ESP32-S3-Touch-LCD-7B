/*
* Ported LVGL 8.4 and display the official demo interface.
*/
#include <esp_log.h>

#include "esp_lv_adapter_arduino.h"
#include <demos/lv_demos.h>

static const char *TAG = "lvgl8_demo";

void setup() {
    static esp_lcd_panel_handle_t panel_handle = NULL; // Declare a handle for the LCD panel
    static esp_lcd_touch_handle_t tp_handle = NULL;    // Declare a handle for the touch panel

    // Initialize the GT911 touch screen controller
    tp_handle = touch_gt911_init();  
    
    // Initialize the Waveshare ESP32-S3 RGB LCD hardware
    panel_handle = waveshare_esp32_s3_rgb_lcd_init(); 

    // Turn on the LCD backlight
    wavesahre_rgb_lcd_bl_on();   

    // Initialize LVGL with the panel and touch handles
    ESP_ERROR_CHECK(esp_lv_adapter_init(panel_handle, tp_handle));

    ESP_LOGI(TAG, "Display LVGL demos");

    // Lock the mutex because LVGL APIs are not thread-safe
    if (esp_lv_adapter_lock(-1)) {
        // Uncomment and run the desired demo functions here
        // lv_demo_stress();  // Stress test demo
        // lv_demo_benchmark(); // Benchmark demo
        // lv_demo_music();     // Music demo
        lv_demo_widgets();    // Widgets demo
        
        // Release the mutex after the demo execution
        esp_lv_adapter_unlock();
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
