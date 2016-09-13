#include "UART.h"

void initUART()
{
	UBRR0H = (BRC >> 8);
	UBRR0L = BRC;
	
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 <<RXCIE0) | (1 << TXCIE0);
	UCSR0C = (1 << UCSZ01) | (1 < UCSZ00);
	
	while(!(UCSR0A & (1 << UDRE0))) {}
		
}

ISR(USART0_RX_vect)
{
	if(readPos == 0)
	{
		readLength = UDR0;
		if(readLength > 1)
			return;
	} 
	else if(readPos == 1)
	{
		uint8_t id = UDR0;
		switch(id)
		{
			case HANDSHAKE_ID:
			readBuffer = buffer_allocate(HANDSHAKE_MAX_SIZE);
			break;
			
			case CHANNEL_CURRENT_ID:
			readBuffer = buffer_allocate(CHANNEL_CURRENT_MAX_SIZE);
			break;
			
			case CHANNEL_STATUS_ID:
			readBuffer = buffer_allocate(CHANNEL_STATUS_MAX_SIZE);
			
			default:
			readPos = 0;
			readLength = 0;
			return;
			break;
		}
	} 
	else 
	{
		buffer_put(readBuffer, UDR0);
		if(readLength != 0 && readPos != 0 && readLength == readPos)
		{
			uint8_t actualId = 0;
			buffer_get(readBuffer, &actualId);
			if (actualId != readId)
			{
				readReset();
				return;
			}
			
			switch(actualId)
			{
				case HANDSHAKE_ID:
				{
				struct Handshake handshake = {.data = 0, .packet = &handshake_readPacket};
				handshake.packet->readPacket(&handshake, readBuffer);
				handleHandshake(handshake);
				break;
				}				
				
				case CHANNEL_CURRENT_ID:
				{
				struct ChannelCurrent channelcurrent = {.channel = 0, .data = 0, .packet = &channelcurrent_readPacket};
				channelcurrent.packet->readPacket(&channelcurrent, readBuffer);
				handleChannelCurrent(channelcurrent);
				break;
				}				
				
				case CHANNEL_STATUS_ID:
				{
				struct ChannelStatus channelstatus = {.data = 0, .packet = &channelstatus_readPacket};
				channelstatus.packet->readPacket(&channelstatus, readBuffer);
				handleChannelStatus(channelstatus);
				}		
				
				case CHANNEL_CURRENT_LIMIT_ID:
				{
				struct ChannelCurrentLimit channelcurrentlimit = {.channel = 0, .data = 0, .packet = &channelcurrentlimit_readPacket};
				channelcurrentlimit.packet->readPacket(&channelcurrentlimit, readBuffer);
				handleChannelCurrentLimit(channelcurrentlimit);
				}	
				
				case CHANNEL_VOLTAGE_LIMIT_ID:
				{
				struct ChannelVoltageLimit channelvoltagelimit = {.channel = 0, .data = 0, .packet = &channelcurrentlimit_readPacket};
				channelvoltagelimit.packet->readPacket(&channelvoltagelimit, readBuffer);
				handleChannelVoltageLimit(channelvoltagelimit);
				}				
								
				default:
				readPos = 0;
				readLength = 0;
				return;
				break;
			}
			readReset();
			return;
		}
	}		
	readPos++;
}

void writeUART(ByteBuffer *buffer)
{
	if(!(readPos == 0 && readLength == 0 && readId == 0))
		while(readPos != 0) {}
			
	writeBuffer = buffer;
	writePos = 0;
	buffer_get(buffer, &writeLength);
	
	UDR0 = 0;
}

ISR(USART0_TX_vect)
{
	buffer_get(writeBuffer, &UDR0);
	if(writeLength == writePos)
		writeReset();
}

void writeReset()
{
	writePos = 0;
	writeLength = 0;
	buffer_free(writeBuffer);
}

void readReset()
{
	readPos = 0;
	readLength = 0;
	readId = 0;
	buffer_free(readBuffer);
}