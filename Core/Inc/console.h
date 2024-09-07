/**
  ******************************************************************************
  * @file           : console.h
  * @brief          : Header file for command line interface 
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Clinton Guenther
  * All rights reserved.
  *
  ******************************************************************************
  */
#ifndef INC_CONSOLE_H_
#define INC_CONSOLE_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>      // Mostly needed for sscanf()
#include "main.h"
#include "uart.h"


// extern uart_type        uart; 

extern UART_HandleTypeDef huart1;

//TODO: need to uncomment these functions.  

// TODO: Update all comment BLOCKS!!
// TODO: Reference console.c

/**
* @brief Main implementation of command-line interface 
* @param: Void passed in
* @retval None
*/
// void MainMenu(uart_type * uart);


// /**
// * @brief Get unsigned (u8) number from user
// * @param: Void passed in
// * @retval uint8_t
// */
// uint8_t getNumber_u8 (uart_type * uart);

// /**
// * @brief Get float number from user
// * @param: Void passed in
// * @retval User-defined float value
// */
// float getNumber_float (uart_type * uart);

#endif
/* END OF FILE */
