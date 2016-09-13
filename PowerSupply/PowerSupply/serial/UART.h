#ifndef UART_H_
#define UART_H_

#include "Packet.h"
#include "../util/ByteBuffer.h"

/*
	Packets come in the format:
	Header:
		int packetid
		int packetlength
	Body:
		type data
		
	Packet ids:
	Tx:
		Handshake = 1
		ChannelCurrent = 2
		Error = 42
*/

#include <avr/io.h>
#include "../Defines.h"
#include "avr/interrupt.h"

#define BAUD 19200
#define BRC ((F_CPU/16/BAUD) - 1)

ByteBuffer *readBuffer;
uint16_t readPos = 0;
uint16_t readLength = 0;
uint8_t readId = 0;

ByteBuffer *writeBuffer;
uint16_t writePos = 0;
uint16_t writeLength = 0;


void initUART();

void writeUART(ByteBuffer *buffer);


#endif