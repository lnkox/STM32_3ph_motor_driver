/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "stm32f1xx_it.h"

/* USER CODE BEGIN 0 */
#include "sintable.h"

int sinpos1=0,sinpos2=SINTABLESIZE*0.3,sinpos3=SINTABLESIZE*0.6;
char mode=0;
char direct=0;
char cur_freq=0;// curent work frequency
char freq=0;// set frequency
int accel_cnt=0;// Acceleration counter
int brake_cnt=0;// Brake counter 
int slow_cnt=0; // slow timer count
int n_table=0; // number sinus table
int relay_on=0; // relay_state
int ERR=0; // error type
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

/******************************************************************************/
/*            Cortex-M3 Processor Interruption and Exception Handlers         */ 
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
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
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
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

/**
* @brief This function handles Prefetch fault, memory access fault.
*/
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
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
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
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

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles DMA1 channel1 global interrupt.
*/
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc1);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
* @brief This function handles TIM1 break interrupt.
*/
void TIM1_BRK_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_IRQn 0 */

  /* USER CODE END TIM1_BRK_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_BRK_IRQn 1 */
	ERR=ERR_OVER_CURRENT;
  /* USER CODE END TIM1_BRK_IRQn 1 */
}

/**
* @brief This function handles TIM3 global interrupt.
*/
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */
	if (ERR>0)
	{
		stop_pwm();
		BRK_RES(0);
		RELAY(0); 
		relay_on=0; 
		cur_freq=0;
		mode=0;
		ERROR_LED(1);
		NORMAL_LED(0);
		RUN_LED(0);
	}
	else
	{	
		if (adc_value[0]>VOLT_MAX) {ERR=ERR_OVER_VOLTAGE;stop_pwm();return;} // check voltage >VOLT_MAX: ERROR=ERR_OVER_VOLTAGE 
		if (adc_value[0]<VOLT_MIN && relay_on==1) {ERR=ERR_LOW_VOLTAGE; stop_pwm(); return;} // check voltage <VOLT_MIN and relay=ON: ERROR=ERR_LOW_VOLTAGE 
		if (adc_value[0]>VOLT_RELAY_ON) {relay_on=1; RELAY(1);} // check voltage >VOLT_RELAY_ON: ON relay 
		if (adc_value[0]>VOLT_BRKRES_ON ) {BRK_RES(1);} // check voltage >VOLT_BRKRES_ON : ON brake resistor
		if (adc_value[0]<VOLT_BRKRES_OFF ) {BRK_RES(0);} // check voltage <VOLT_BRKRES_OFF: OFF brake resistor
		if (relay_on==1)
		{	
			NORMAL_LED(1);
			if (mode>0)
			{ 
				
					if(cur_freq<freq || cur_freq>freq)
					{
							accel_cnt++;
							if (accel_cnt>ACCELERATION) 
							{
									accel_cnt=0; 
									if (cur_freq<freq) {cur_freq++;} else {cur_freq--;}
									TIM4->ARR =(8000000/(SINTABLESIZE*cur_freq))-1;
									//TIM4->ARR=53333;
									n_table=cur_freq-1;
									if (n_table>49) n_table=49;
							}
					}
			} 
			else
			{  
				char rev_b=REVERSE_BUT;
				char for_b=FORWARD_BUT;
				if(rev_b==1) {mode=1;direct=DIRECTION_REVERSE;run_pwm();}
				if(for_b==1) {mode=1;direct=DIRECTION_FORWARD;run_pwm();} 
				RUN_LED(0);
			}
		}
		else
		{
			NORMAL_LED(0);
		}
	}
	char stop_b=STOP_BUT;
	if(stop_b==1)
	{ 
			if (mode==0)
			{
					ERR=0;  
					ERROR_LED(0);
			}
			else
			{
				 mode=2; 
			}    
	}  
	if (mode==2)
	{
		BRAKE_LED(1);
		freq=1;
		if (cur_freq==1)  brake_cnt++;
		if (brake_cnt>BRAKE_PERIOD) {brake_cnt=0;mode=0;BRAKE_LED(0);}
	}
			
	
	slow_cnt++;
	if (slow_cnt>250) 
	{
		slow_cnt=0;
		freq=adc_value[3]/68+1; //set frequency by adc
		if (adc_value[1]>TEMR_MAX) {ERR=ERR_OVER_TEMP;} //check temperature>TEMR_MAX: ERR=ERR_OVER_TEMP
		if (adc_value[1]>TEMR_FAN_ON ) FAN(1); //check temperature>TEMR_FAN_ON : FAN=ON
		if (adc_value[1]<TEMR_FAN_OFF ) FAN(0); //check temperature<TEMR_FAN_OFF : FAN=OFF
	}
	
	
	

  /* USER CODE END TIM3_IRQn 1 */
}

/**
* @brief This function handles TIM4 global interrupt.
*/
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */
	if (mode>0 ) 
        {
					
						sinpos1++;
						sinpos2++;
						sinpos3++;
						if (sinpos1==SINTABLESIZE) {sinpos1=0;HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12); }
						if (sinpos2==SINTABLESIZE) sinpos2=0;
						if (sinpos3==SINTABLESIZE) sinpos3=0;	
						TIM1->CCR1=SINTABLE [n_table][sinpos1];

            if (direct == DIRECTION_FORWARD)
            {
							TIM1->CCR2=SINTABLE [n_table][sinpos2];
							TIM1->CCR3=SINTABLE [n_table][sinpos3];
            }
            else
            {
							TIM1->CCR2=SINTABLE [n_table][sinpos3];
							TIM1->CCR3=SINTABLE [n_table][sinpos2];
            }  
        }
        else
        {
					stop_pwm();
        } 
	

  /* USER CODE END TIM4_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
