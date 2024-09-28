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


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define SW_VER_STR                  "0.0.7"             // SW Version String


/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

typedef enum
{
  IDLE,
  LEFT_TURN,
  RIGHT_TURN
}state;

typedef struct button_state {
  uint8_t left_turn_debounce_counter;
  uint8_t right_turn_debounce_counter;
  uint8_t quick_flash_counts;

  
  bool  left_turn_active;
  bool  right_turn_active;
  bool  no_turn_active;

} button_state;


/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void init_button_states ( void ); 

void check_button_states( void ); 

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOD
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOD
#define HLTH_LED_Pin GPIO_PIN_0
#define HLTH_LED_GPIO_Port GPIOC
#define LEFT_TURN_GPI_Pin GPIO_PIN_5
#define LEFT_TURN_GPI_GPIO_Port GPIOC
#define RT_nLT_TTL_Pin GPIO_PIN_12
#define RT_nLT_TTL_GPIO_Port GPIOB
#define EN_LIGHTS_TTL_Pin GPIO_PIN_13
#define EN_LIGHTS_TTL_GPIO_Port GPIOB
#define SW_FLASHER_TTL_Pin GPIO_PIN_14
#define SW_FLASHER_TTL_GPIO_Port GPIOB
#define TAILLIGHT_FLASHER_TTL_Pin GPIO_PIN_15
#define TAILLIGHT_FLASHER_TTL_GPIO_Port GPIOB
#define RIGHT_TURN_GPI_Pin GPIO_PIN_6
#define RIGHT_TURN_GPI_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

#define BUTTON_DEBOUNCE_MSX10   20    // 20*10 = 200 ms of debounce time

/**
 * Maximum number of times the turn signal will rapidly 
 * blink before going into a normal blink pattern 
 */
#define MAX_NUM_OF_QUICK_FLASHES  10   

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
