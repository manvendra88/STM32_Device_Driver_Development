
#include"stm32f407xx_spi_driver.h"

/****************************************SPI API*********************************************/

/*
 * Peripheral Clock setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}else if (pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}else if (pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	}
	else
	{
		//TODO
	}
}


/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	uint32_t tempreg = 0;
	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR; 			//To make a binary number that has either one or zero at the second bit position.
	
	if ( pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//BIDI Mode bit should be cleared.
		tempreg &=  ~(1 << SPI_CR1_BIDIMODE);
	}
	else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//BIDI Mode bit should be set
		tempreg |= (1 << SPI_CR1_BIDIMODE);
	}
	else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		//BIDI Mode bit should be set
		//RXOnly Mode bit should be set
		tempreg |= (1 << SPI_CR1_BIDIMODE);
		tempreg |= (1 << SPI_CR1_RXONLY);
		
	}
	
	tempreg |= (pSPIHandle->SPIConfig.SPI_SclkSpeed <<  SPI_CR1_BR);
	tempreg |= (pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL);
	tempreg |= (pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA);
	tempreg |= (pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF);
	tempreg |= (pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM);
	
	//Now put the value of temreg in the CR1
	pSPIHandle->pSPIx->CR1 |= tempreg;
	
	
}

void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	
}

uint8_t SPI_GetFlagStatus (SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}

/*
 * Data Send and Receive (Blocking : Non-Interrupt based, and Non-Blocking : Interrupt Based)
 */

void SPI_SendData (SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
	while (Len>0)
	{
		//Wait until TXE is 1
																					//Instead of while(!(pSPIx->SR & (1<<1) ) ); we make a function //To simply check if TXE (At first bit pos of SR is 1 or not
		while (SPI_GetFlagStatus (pSPIx,SPI_TXE_FLAG) == FLAG_RESET);
		
		if((pSPIx->CR1 & (1<<SPI_CR1_DFF)))
		{
			//16-bit DFF
			//1. Load the data into the DR
			pSPIx->DR |= *((uint16_t*)pTxBuffer); //We first type-casted a pTxBuffer to 16 bit and then dereferenced it to get the value and then send to DR.
			Len--;
			Len--; 
			(uint16_t*)pTxBuffer++;
		}
		else
		{
			pSPIx->DR |= *(pTxBuffer);
			Len--;
			pTxBuffer++;

			
		}
			
	}
	
}

void SPI_ReceiveData (SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len){
}


/*
 * IRQ Configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi){
}

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){
}

void SPI_IRQHandling(SPI_Handle_t *pHandle){
}