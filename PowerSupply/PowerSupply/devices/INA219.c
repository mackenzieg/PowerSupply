#include "INA219.h"

void initINA219(uint8_t address)
{
	setCalibration(address);
}

void setCalibration(uint8_t address)
{
	calValue = 4096;
	currentDivider = 10;
	powerDivider = 2;
	
	data[0] = (uint8_t) (calValue >> 8);
	data[1] = calValue & 0xff;
	
	writeRegisterTwoWire(address, CALIBRATION_REGISTER, *data, 2);
	uint16_t config = CONFIG__VOLTAGE_32V | 
					  CONFIG_GAIN_1 |
					  CONFIG_RES_12BIT |
					  CONFIG_SAMPLE_12BIT_1S |
					  CONFIG_MODE_SBVOLT_CONTINUOUS;
					
	data[0] = (uint8_t) (config >> 8);
	data[1] = config & 0xff;
	
	writeRegisterTwoWire(address, CONFIG_REGISTER, *data, 2);
}

float getShuntVoltage(uint8_t address)
{
	readRegisterTwoWire(address, SHUNTVOLTAGE_REGISTER, *data, 2);
	return (data[0] << 8) | data[1];
}

float getCurrent(uint8_t address)
{
	data[0] = (uint8_t) (calValue >> 8);
	data[1] = calValue & 0xff;
	writeRegisterTwoWire(address, CALIBRATION_REGISTER, *data, 2);
	readRegisterTwoWire(address, CURRENT_REGISTER, *data, 2);
	uint16_t value = (data[0] << 8) | data[1];
	value = (value / currentDivider) * 1000;
	return value;
}

float getBusVoltage(uint8_t address)
{
	writeRegisterTwoWire(address, BUSVOLTAGE_REGISTER, *data, 2);
	return ((data[0] << 8) | data[1]) * 0.001;
}