#include "SPI.h"

void initSPI(void)
{
	DDRD |= ((1 << C1CS1) | (1 << C1CS2));
	DDRB |= ((1 << C2CS1) | (1 << C2CS2));
	PORTD |= ((1 << C1CS1) | (1 << C1CS2)); 
	PORTB |= ((1 << C2CS1) | (1 << C2CS2));
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}


void writeSPI(Slave slave, uint8_t* data, uint16_t length)
{
	toggleSPISlaveLine(slave);
	
	for (int i = 0; i < length; i++)
	{
		SPDR = data[i];
		while (!(SPSR & (1 << SPIF))) {}
	}
	
	toggleSPISlaveLine(slave);
}

void toggleSPISlaveLine(Slave slave)
{
	switch(slave)
	{
		case CHANNEL_ONE_CHIP_ONE:
		PORTD ^= (1 << C1CS1);
		break;
		case CHANNEL_ONE_CHIP_TWO:
		PORTD ^= (1 << C1CS2);
		break;
		case CHANNEL_TWO_CHIP_ONE:
		PORTB ^= (1 << C2CS1);
		break;
		case CHANNEL_TWO_CHIP_TWO:
		PORTB ^= (1 << C2CS2);
		break;
	}
}