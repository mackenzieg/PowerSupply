#ifndef MAX5541_H_
#define MAX5541_H_

#include "../spi/SPI.h"

typedef struct  
{
	Slave slave;
	uint16_t lastVal;
} MAX55541Device;

MAX55541Device c1ISet;
MAX55541Device c1VSet;
MAX55541Device c2ISet;
MAX55541Device c2VSet;

void initMAX5541(void);

void setValue(MAX55541Device device, uint16_t value);

#endif