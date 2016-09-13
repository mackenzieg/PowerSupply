#ifndef SPI_H_
#define SPI_H_

#include "../Defines.h"
#include <avr/io.h>

#define C1CS1 PD5 
#define C1CS2 PD4 
#define C2CS1 PB4 
#define C2CS2 PB3 

typedef enum {
	CHANNEL_ONE_CHIP_ONE,
	CHANNEL_ONE_CHIP_TWO,
	CHANNEL_TWO_CHIP_ONE,
	CHANNEL_TWO_CHIP_TWO,
} Slave;

void initSPI(void);
void writeSPI(Slave slave, uint8_t* data, uint16_t length);

#endif