/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "timer.h"
#include "uart.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
//TODO: we should be able to remove this
// typedef struct uart_type{
//     char        rxbuf[MAX_ELEMENTS];            // Ring buffer for serial receiver
//     char        rxchar;                         // Supported mainly for calibration routine 
//     uint8_t     producer_index;                 // Use this to point to where the next received data byte shall go
//     uint8_t     consumer_index;                 // Use this as the consumer of data in the buffer
//     uint8_t     data_index;                     // Location where message data starts
//     uint8_t     data_end;                       // Location where message data ends    
//     uint8_t     msg_state;                      // Keep track of what state we are in
//     uint8_t     msg_len;                        // Keep track of the message length field
//     uint8_t     byte_counter;                   // Additional variable for tracking number of bytes that are needing to be processed
//     uint8_t     len_verify;                     // Used to validate length byte received
//     uint8_t     msg_id;                         // Store the ID of the message

//     bool        errorflag;                      // Currently used to indicate out-of-bounds range request on power 10 lookup table
//     bool        validmsg;                       // Flag to mark that a valid message has been received
//     bool        inmenu;                         // This flag will indicate if we're in the menu
// } uart_type;


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define SW_VER_STR                  "0.0.1"             // SW Version String

// #define DEFAULT_FUSE_CURRENT_MA     50                  // Default fuse current in mA 
// #define CHECK_VALUE_FUSE_CURRENT_MA 300
// #define GOOD_FUSE_MV_THRESHOLD      80                  // Voltage threshold in mA
// #define FUSE_100MS_TICKS_TIMEOUT    30                  // Number of 100ms counts before shutting active fuses off

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOD
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOD
#define HLTH_LED_Pin GPIO_PIN_0
#define HLTH_LED_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
