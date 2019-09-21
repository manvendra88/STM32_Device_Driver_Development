#include"stm32f407xx.h"


/*Configuration structure for SPIx peripheral */
typedef struct {

	uint8_t SPI_DeviceMode;
	uint8_t	SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;

}SPI_Config_t;

/*Handle Structure for SPIx peripheral */
typedef struct {
	
	SPI_RegDef_t 	*pSPIx;   			//To hold the address of SPIx x=1,2,3
	SPI_Config_t 	SPIConfig;

} SPI_Handle_t;


/****************************************SPI API*********************************************/

/*
 * Peripheral Clock setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);


/*
 * Data Send and Receive
 */

//Blocking : Non-Interrupt based, and Non-Blocking : Interrupt Based 









/*
Init or De-init
*/


