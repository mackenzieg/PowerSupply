#include "ChannelVoltage.h"

static struct Packet channelvoltage_operation = {
	.writePacket = channelvoltage_writePacket
};

void handleChannelVoltage(struct ChannelVoltage channelvoltage)
{
	
}

void channelvoltage_readPacket(void *channelvoltage, ByteBuffer *buffer)
{
	struct ChannelVoltage *this = channelvoltage;
	buffer_get(buffer, &this->channel);
	buffer_getFloat(buffer, &this->data);
}

void channelvoltage_writePacket(void *channelvoltage, ByteBuffer *buffer)
{
	struct ChannelVoltage *this = channelvoltage;
	buffer_put(buffer, CHANNEL_VOLTAGE_MAX_SIZE);
	buffer_put(buffer, CHANNEL_VOLTAGE_ID);
	buffer_put(buffer, this->channel);
	buffer_putShort(buffer, this->data);
}