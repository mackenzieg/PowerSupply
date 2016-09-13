#include "MAX5541.h"

void initMAX5541(void)
{
	c1ISet.slave = CHANNEL_ONE_CHIP_ONE;
	c1VSet.slave = CHANNEL_ONE_CHIP_TWO;
	c2ISet.slave = CHANNEL_TWO_CHIP_ONE;
	c2VSet.slave = CHANNEL_TWO_CHIP_TWO;
	c1ISet.lastVal = 0;
	c1VSet.lastVal = 0;
	c2ISet.lastVal = 0;
	c2VSet.lastVal = 0;
}

void setValue(MAX55541Device device, uint16_t value)
{
	uint8_t data[] = {
		(uint8_t) (value >> 8),
		value & 0xff
	};
	writeSPI(device.slave, data , 2);
	device.lastVal = value;
}
