
idf_component_register(SRCS "gt911.c"
                        INCLUDE_DIRS "."
                        REQUIRES driver esp_lcd esp_lcd_touch i2c gpio io_extension rgb_lcd_port
                    )
