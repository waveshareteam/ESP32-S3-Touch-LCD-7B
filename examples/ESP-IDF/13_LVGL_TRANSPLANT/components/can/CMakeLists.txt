idf_component_register(SRCS "can.c" 
                        INCLUDE_DIRS "." "../i2c" "../gpio" "../io_extension"
                        REQUIRES driver 
                    )
