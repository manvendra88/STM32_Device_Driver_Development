/*
 * stm32f42901_gpio_drivers.h
 *
 *  Created on: 09-Sep-2019
 *      Author: Manu
 */

#ifndef INC_STM32F42901_GPIO_DRIVERS_H_
#define INC_STM32F42901_GPIO_DRIVERS_H_

#include"stm32f42901.h"

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;			/*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< possible values from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;



typedef struct
{
	GPIO_RegDef_t *pGPIOx;							//Pointer to hold the base address of GPIO Peripheral, this will be initialized to GPIOA which is nothing but a MACRO of a pointer variable typecasted GPIO_Reg_Def_t :((GPIO_RegDef_t*)GPIOA_BASEADDR)
	GPIO_PinConfig_t GPIO_PinConfig;				//Pin can have many configuration items

}GPIO_Handle_t;

/*Defining function names that we will build */

/*For Init or DeInit*/
void GPIO_Init (void);
void GPIO_DeInit (void);

/* For Clock */
void GPIO_PeriClockControl (void);

/*Read or Write */
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPort(void);
void GPIO_WriteToOutputPort(void);

/*IRQ Config or Handeling*/
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);









#endif /* INC_STM32F42901_GPIO_DRIVERS_H_ */
