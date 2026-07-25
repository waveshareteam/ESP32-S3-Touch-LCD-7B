/*****************************************************************************
 * | File         :   usart.c
 * | Author       :   Waveshare team
 * | Function     :   Hardware underlying interface
 * | Info         :
 * |                 USART driver code for UART communication.
 * ----------------
 * | This version :   V1.0
 * | Date         :   2024-11-26
 * | Info         :   Basic version
 *
 ******************************************************************************/

#include "usart.h"  // Include USART driver header for UART functions

/**
 * @brief Initialize UART communication with a given baud rate.
 * 
 * This function configures the UART parameters such as baud rate, data bits,
 * parity, stop bits, and flow control. It also installs the UART driver and 
 * sets up the necessary pins for communication.
 * 
 * @param Baudrate The baud rate for UART communication (e.g., 115200).
 */
void DEV_UART_Init(uint8_t Txd,uint8_t Rxd,uint32_t Baudrate)
{
    // Define UART configuration structure
    uart_config_t uart_config = {
        .baud_rate = Baudrate,  // Set the baud rate for communication
        .data_bits = UART_DATA_8_BITS,     // Set 8 data bits per frame
        .parity    = UART_PARITY_DISABLE,  // No parity check
        .stop_bits = UART_STOP_BITS_1,     // 1 stop bit
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE, // Disable hardware flow control
        .source_clk = UART_SCLK_DEFAULT,   // Default clock source for UART
    };
    
    // Install the UART driver with a buffer size and no interrupt handler
    ESP_ERROR_CHECK(uart_driver_install(ECHO_UART_PORT_NUM, BUF_SIZE * 2, 0, 0, NULL, 0));
    
    // Configure the UART with the defined settings
    ESP_ERROR_CHECK(uart_param_config(ECHO_UART_PORT_NUM, &uart_config));
    
    // Set the UART pin configuration (TX, RX, RTS, CTS)
    ESP_ERROR_CHECK(uart_set_pin(ECHO_UART_PORT_NUM, Txd, Rxd, ECHO_TEST_RTS, ECHO_TEST_CTS));
}

/**
 * @brief Write a byte of data to UART.
 * 
 * This function writes data to the UART transmission buffer. The data is sent
 * to the specified UART port.
 * 
 * @param pData Pointer to the data (byte) to be transmitted.
 */
void UART_Write_Byte(uint8_t *pData)
{
    // Write the byte data to the UART transmission buffer
    uart_write_bytes(ECHO_UART_PORT_NUM, (const char*)pData, strlen((const char*)pData));
}

/**
 * @brief Read a specified number of bytes from UART.
 * 
 * This function reads data from the UART receive buffer into the provided buffer.
 * 
 * @param pData Pointer to the buffer where received data will be stored.
 * @param Len   The number of bytes to read from UART.
 * @return      The number of bytes successfully read from UART.
 */
int UART_Read_Byte(uint8_t *pData, uint32_t Len)
{
    // Read the specified number of bytes from UART into the buffer
    return uart_read_bytes(ECHO_UART_PORT_NUM, pData, Len, TIME_OUT);
}

/**
 * @brief Set the UART baud rate.
 * 
 * This function changes the baud rate of the UART communication to the specified value.
 * 
 * @param Baudrate The new baud rate to set for UART communication.
 */
void UART_Set_Baudrate(uint32_t Baudrate)
{
    // Set the UART baud rate to the specified value
    ESP_ERROR_CHECK(uart_set_baudrate(ECHO_UART_PORT_NUM, Baudrate));
}

/**
 * @brief Get the number of bytes available in the UART buffer.
 * 
 * This function checks how many bytes are currently buffered in the UART receive buffer.
 * 
 * @return The number of bytes available to read in the UART buffer.
 */
int UART_Get_Date_Len()
{
    int len = 0;
    
    // Get the number of bytes in the UART receive buffer
    uart_get_buffered_data_len(ECHO_UART_PORT_NUM, (size_t*)&len);   
    
    return len;
}
