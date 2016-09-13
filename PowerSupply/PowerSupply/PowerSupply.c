#include "Defines.h"
#include "serial/Packet.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	sei();
	initTwoWire();
	initSPI();
	initUART();
    while(1)
    {
		
    }
}