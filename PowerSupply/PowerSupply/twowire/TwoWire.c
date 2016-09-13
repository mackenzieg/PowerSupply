#include <avr/io.h>
#include <util/twi.h>

#include "TwoWire.h"

#define F_SCL 400000
#define PRESCALAR 1
#define TWBR_VAL ((((F_CPU / F_SCL) / PRESCALAR) - 16 ) / 2)

void initTwoWire(void)
{
	TWBR = (uint8_t) TWBR_VAL;
}

bool startTwoWire(uint8_t address)
{
	TWCR = 0;
	TWCR = (1 << TWINT) | (TWSTA << 1) | (1 << TWEN); // 0b10100100
	while(!(TWCR & (1 << TWINT))) {}
	
	if ((TWSR & 0b11111000) != TW_START)
		return false;
	
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1 << TWINT))) {}
	
	// Check if device acknowledged read/write mode
	uint8_t rwac = TW_STATUS & 0b11111000;
	
	if ((rwac != TW_MT_SLA_ACK) && (rwac != TW_MR_SLA_ACK))
		return false;
		
	return true;
}

void stopTwoWire(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

bool writeTwoWire(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1 << TWINT))) {}
	
	if ((TWSR & 0b11111000) != TW_MT_DATA_ACK)
		return false;
		
	return true;
}

uint8_t readACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) || (1 << TWEA);
	while (!(TWCR & (1 << TWINT))) {}
	return TWDR;
}

uint8_t readNACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT))) {}
	return TWDR;
}

bool transmitTwoWire(uint8_t address, uint8_t* data, uint16_t length)
{
	if(!startTwoWire(address | 0b00000000))
		return false;
	for (uint16_t i = 0; i < length; i++)
	{
		if(writeTwoWire(data[i]))
			return false;
	}
	stopTwoWire();
	return true;
}

bool receiveTwoWire(uint8_t address, uint8_t* data, uint16_t length)
{
	if(!startTwoWire(address | 0b00000001))
		return false;
	for(uint16_t i = 0; i < (length - 1); i++)
	{
		data[i] = readACK();
	}
	data[(length - 1)] = readNACK();
	stopTwoWire();
	return true;
}

bool writeRegisterTwoWire(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length)
{
	if(!startTwoWire(devaddr | 0b00000000))
		return false;
	writeTwoWire(regaddr);
	for (uint16_t i = 0; i < length; i++)
	{
		if(writeTwoWire(data[i]))
			return false;
	}
	stopTwoWire();
	return true;
}

bool readRegisterTwoWire(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length)
{
	if(!startTwoWire(devaddr | 0b00000001))
		return false;
	writeTwoWire(regaddr);
	for(uint16_t i = 0; i < (length - 1); i++)
	{
		data[i] = readACK();
	}
	data[(length - 1)] = readNACK();
	stopTwoWire();
	return true;
}