/*****************************************************************************
 * | File         :   usart.h
 * | Author       :   Waveshare team
 * | Function     :   USART driver code for UART communication
 * | Info         :
 * |                 Header file for UART communication functions. 
 * |                 Provides initialization, data transmission, and reception
 * |                 functionality using ESP32's UART driver.
 * ----------------
 * | This version :   V1.0
 * | Date         :   2024-11-26
 * | Info         :   Basic version for USART communication.
 *
 ******************************************************************************/

#ifndef __USART_H
#define __USART_H

#pragma once

#include <stdio.h>          // Standard input/output library for printf, etc.
#include <string.h>         // String manipulation functions like strlen, strcpy, etc.
#include "driver/uart.h"    // ESP32 UART driver functions and definitions
#include "esp_log.h"        // ESP32 logging library for debugging and error logging
#include "gpio.h"           // GPIO header for configuring UART pins

/* UART Pin Definitions */
#define ECHO_TEST_RTS (UART_PIN_NO_CHANGE)  // No RTS (Request to Send) pin used
#define ECHO_TEST_CTS (UART_PIN_NO_CHANGE)  // No CTS (Clear to Send) pin used

/* UART Configuration Parameters */
#define ECHO_UART_PORT_NUM      (UART_NUM_1)    // Use UART port 1
#define BUF_SIZE    (1024)  // Buffer size for UART data (in bytes)
#define TIME_OUT    (100)   // Timeout value for UART operations (in milliseconds)

/* Function Prototypes */

/**
 * @brief Initialize UART communication with a specified baud rate.
 * 
 * Configures the UART interface with the specified baud rate, data bits, 
 * stop bits, parity, and initializes the necessary pins for TX, RX, RTS, and CTS.
 * 
 * @param Txd     UART TX pin number.
 * @param Rxd     UART RX pin number.
 * @param Baudrate Desired baud rate for UART communication (e.g., 115200).
 */
void DEV_UART_Init(uint8_t Txd, uint8_t Rxd, uint32_t Baudrate);

/**
 * @brief Write a byte of data to UART.
 * 
 * Sends a byte (or string) of data to the UART TX pin. The data is transmitted
 * asynchronously via the UART interface.
 * 
 * @param pData Pointer to the data byte (or string) to be transmitted.
 */
void UART_Write_Byte(uint8_t *pData);

/**
 * @brief Read a specified number of bytes from UART.
 * 
 * Reads data from the UART RX pin and stores it in the provided buffer. 
 * The function will wait for the specified amount of data to arrive or 
 * until the timeout occurs.
 * 
 * @param pData Pointer to the buffer where received data will be stored.
 * @param Len   The number of bytes to read from UART.
 * @return      The number of bytes successfully read.
 */
int UART_Read_Byte(uint8_t *pData, uint32_t Len);

/**
 * @brief Set the baud rate for UART communication.
 * 
 * Changes the baud rate of the UART communication dynamically.
 * 
 * @param Baudrate The new baud rate for UART communication (e.g., 9600, 115200).
 */
void UART_Set_Baudrate(uint32_t Baudrate);

/**
 * @brief Get the number of bytes available in the UART receive buffer.
 * 
 * Returns the number of bytes currently available for reading in the UART
 * receive buffer.
 * 
 * @return The number of bytes available in the UART buffer for reading.
 */
int UART_Get_Date_Len();

#endif  // __USART_H
