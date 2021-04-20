/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f4xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 *
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/************************************************************************************************
 INCLUDES
 ************************************************************************************************/
#include "can.h"
#include "canopen_object_dict.h"
#include "usbd_cdc_if.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/************************************************************************************************
 VARIABLES
 ************************************************************************************************/
//extern CAN_RxHeaderTypeDef can_rx_header;
//extern uint8_t can_rx_data[8];
//extern CanDataFrameInit can_rx_frame_template;
//extern CanDataFrameInit can_frame_template;
//uint8_t DataToSend[80];
//extern CanDataFrameInit *p_can_frame_template;
	bool_t day_state;
	bool_t emcy_state;
	bool_t reverse_state;
	bool_t daylight_state;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern PCD_HandleTypeDef hpcd_USB_OTG_HS;
extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim14;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line1 interrupt.
  */
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */

  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  /* USER CODE BEGIN EXTI1_IRQn 1 */

	/************************************************************************************************
	 OPTO-INPUTS INTERRUPT HANDLING
	 ************************************************************************************************/
	/* opto input 1 - long lights */
	OptoInputsRisingFalling(OPTO_INPUT1_GPIO_Port, OPTO_INPUT1_Pin, 0x01);

  /* USER CODE END EXTI1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line2 interrupt.
  */
void EXTI2_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI2_IRQn 0 */

  /* USER CODE END EXTI2_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
  /* USER CODE BEGIN EXTI2_IRQn 1 */

	/************************************************************************************************
	 OPTO-INPUTS INTERRUPT HANDLING
	 ************************************************************************************************/
	/* opto input 2 - long lights */
	OptoInputsRisingFalling(OPTO_INPUT2_GPIO_Port, OPTO_INPUT2_Pin, 0x01);

  /* USER CODE END EXTI2_IRQn 1 */
}

/**
  * @brief This function handles EXTI line3 interrupt.
  */
void EXTI3_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI3_IRQn 0 */

  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
  /* USER CODE BEGIN EXTI3_IRQn 1 */

	/************************************************************************************************
	 OPTO-INPUTS INTERRUPT HANDLING
	 ************************************************************************************************/
	/* opto input 3 - right indicator */
	OptoInputsRisingFalling(OPTO_INPUT3_GPIO_Port, OPTO_INPUT3_Pin, 0x02);

  /* USER CODE END EXTI3_IRQn 1 */
}

/**
  * @brief This function handles EXTI line4 interrupt.
  */
void EXTI4_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_IRQn 0 */

  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  /* USER CODE BEGIN EXTI4_IRQn 1 */

	/************************************************************************************************
	 OPTO-INPUTS INTERRUPT HANDLING
	 ************************************************************************************************/
	/* opto input - left indicator4 */
	OptoInputsRisingFalling(OPTO_INPUT4_GPIO_Port, OPTO_INPUT4_Pin, 0x03);

  /* USER CODE END EXTI4_IRQn 1 */
}

/**
  * @brief This function handles CAN1 TX interrupts.
  */
void CAN1_TX_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_TX_IRQn 0 */

  /* USER CODE END CAN1_TX_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_TX_IRQn 1 */

	/************************************************************************************************
	 CAN_HIGH_SPEED TX INTERRUPT HANDLING
	 ************************************************************************************************/
	UsbTransfer(&can_frame_template);

  /* USER CODE END CAN1_TX_IRQn 1 */
}

/**
  * @brief This function handles CAN1 RX0 interrupts.
  */
void CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX0_IRQn 0 */

  /* USER CODE END CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX0_IRQn 1 */

	/************************************************************************************************
	 CAN_HIGH_SPEED RX INTERRUPT HANDLING
	 ************************************************************************************************/
	CanSaveReceivedData(CAN_HIGH_SPEED, &can_rx_frame_template);
//	CanTransfer(CAN_LOW_SPEED, lights_controller.node_id, dashboard.node_id);
	UsbTransfer(&can_rx_frame_template);

  /* USER CODE END CAN1_RX0_IRQn 1 */
}

/**
  * @brief This function handles CAN1 RX1 interrupt.
  */
void CAN1_RX1_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX1_IRQn 0 */

  /* USER CODE END CAN1_RX1_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX1_IRQn 1 */

  /* USER CODE END CAN1_RX1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

	/************************************************************************************************
	 OPTO-INPUTS INTERRUPT HANDLING
	 ************************************************************************************************/
//	/* lights */
//	day_state = HAL_GPIO_ReadPin(OPTO_INPUT5_GPIO_Port, OPTO_INPUT5_Pin);
//	emcy_state = HAL_GPIO_ReadPin(OPTO_INPUT6_GPIO_Port, OPTO_INPUT6_Pin);
//	reverse_state = HAL_GPIO_ReadPin(OPTO_INPUT7_GPIO_Port, OPTO_INPUT7_Pin);
//	daylight_state = HAL_GPIO_ReadPin(OPTO_INPUT8_GPIO_Port, OPTO_INPUT8_Pin);
//
//	CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id+1,
//				&can_frame_template, 6, SDO_UPLOAD, 0x08, day_state, emcy_state, reverse_state, daylight_state, 0, 0);

//

	/* opto input 5 - only front lights, those only on a day */
	if (HAL_GPIO_ReadPin(OPTO_INPUT5_GPIO_Port, OPTO_INPUT5_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 3, SDO_UPLOAD, 0x08, 1, 0, 0, 0, 0, 0);

	} else if (HAL_GPIO_ReadPin(OPTO_INPUT5_GPIO_Port, OPTO_INPUT5_Pin)
			== GPIO_PIN_RESET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 3, SDO_UPLOAD, 0x08, 0, 0, 0, 0, 0, 0);
	}
//	} else {
//		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id
//				&can_frame_template, 3, SDO_UPLOAD, 0x05, 0, 0, 0, 0, 0, 0);
//	}

	/* opto input 6 - emergency lights */
	if (HAL_GPIO_ReadPin(OPTO_INPUT6_GPIO_Port, OPTO_INPUT6_Pin)
			== GPIO_PIN_SET) {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 3, SDO_UPLOAD, 0x06, 1, 0, 0, 0, 0, 0);
//				&can_frame_template, 5, SDO_UPLOAD, 0x06, 0, 0x06, 1, 0, 0, 0);

//	} else if (HAL_GPIO_ReadPin(OPTO_INPUT6_GPIO_Port, OPTO_INPUT6_Pin)
//			== GPIO_PIN_RESET) {
//		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
//				&can_frame_template, 3, SDO_UPLOAD, 0x06, 0, 0, 0, 0, 0, 0);
	} else {
		CanSendSdo(CAN_LOW_SPEED, lights_controller.node_id,
				&can_frame_template, 3, SDO_UPLOAD, 0x06, 0, 0, 0, 0, 0, 0);
//				&can_frame_template, 3, SDO_UPLOAD, 0x06, 0, 0x06, 1, 0, 0, 0);
	}

	/* opto input 7 - reverse lights */
//	OptoInputsRisingFalling(OPTO_INPUT7_GPIO_Port, OPTO_INPUT7_Pin, 0x07);
	/* opto input 8 - day lights */
	OptoInputsRisingFalling(OPTO_INPUT8_GPIO_Port, OPTO_INPUT8_Pin, 0x08);
	/* opto input 9 - on/off */

	/* opto input 10 - keys */

	/* opto input 11 - forward */

	/* opto input 12 - day lights */

	/* opto input 13 - sport */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt and TIM10 global interrupt.
  */
void TIM1_UP_TIM10_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 0 */
  HAL_TIM_IRQHandler(&htim10);
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */

	/************************************************************************************************
	 TIMER 10Hz INTERRUPT HANDLING
	 ************************************************************************************************/
//	CanSendSync(CAN_HIGH_SPEED, &can_frame_template);
//	CanSendNmt(CAN_HIGH_SPEED, OPERATIONAL_STATE, lights_controller.node_id, &can_frame_template);
//	CanSendNmt(CAN_HIGH_SPEED, OPERATIONAL_STATE, dashboard.node_id, &can_frame_template);
//	CanSendSync(CAN_LOW_SPEED, &can_frame_template);
//	CanSendTpdo(CAN_LOW_SPEED, lights_controller.node_id, 2, 0x01,
//			&can_frame_template);
	HAL_GPIO_TogglePin(LED_D4_GPIO_Port, LED_D4_Pin);

  /* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

	/************************************************************************************************
	 OPTO-INPUTS INTERRUPT HANDLING
	 ************************************************************************************************/

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/**
  * @brief This function handles TIM8 trigger and commutation interrupts and TIM14 global interrupt.
  */
void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
  /* USER CODE BEGIN TIM8_TRG_COM_TIM14_IRQn 0 */

  /* USER CODE END TIM8_TRG_COM_TIM14_IRQn 0 */
  HAL_TIM_IRQHandler(&htim14);
  /* USER CODE BEGIN TIM8_TRG_COM_TIM14_IRQn 1 */

  /* USER CODE END TIM8_TRG_COM_TIM14_IRQn 1 */
}

/**
  * @brief This function handles CAN2 TX interrupts.
  */
void CAN2_TX_IRQHandler(void)
{
  /* USER CODE BEGIN CAN2_TX_IRQn 0 */

  /* USER CODE END CAN2_TX_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan2);
  /* USER CODE BEGIN CAN2_TX_IRQn 1 */

	/************************************************************************************************
	 CAN_LOW_SPEED TX INTERRUPT HANDLING
	 ************************************************************************************************/
	UsbTransfer(&can_frame_template);

  /* USER CODE END CAN2_TX_IRQn 1 */
}

/**
  * @brief This function handles CAN2 RX0 interrupts.
  */
void CAN2_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN CAN2_RX0_IRQn 0 */

  /* USER CODE END CAN2_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan2);
  /* USER CODE BEGIN CAN2_RX0_IRQn 1 */

  /* USER CODE END CAN2_RX0_IRQn 1 */
}

/**
  * @brief This function handles CAN2 RX1 interrupt.
  */
void CAN2_RX1_IRQHandler(void)
{
  /* USER CODE BEGIN CAN2_RX1_IRQn 0 */

  /* USER CODE END CAN2_RX1_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan2);
  /* USER CODE BEGIN CAN2_RX1_IRQn 1 */

  /* USER CODE END CAN2_RX1_IRQn 1 */
}

/**
  * @brief This function handles USB On The Go HS global interrupt.
  */
void OTG_HS_IRQHandler(void)
{
  /* USER CODE BEGIN OTG_HS_IRQn 0 */

  /* USER CODE END OTG_HS_IRQn 0 */
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_HS);
  /* USER CODE BEGIN OTG_HS_IRQn 1 */
//HAL_GPIO_TogglePin(LED_D6_GPIO_Port, LED_D6_Pin);
  /* USER CODE END OTG_HS_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
