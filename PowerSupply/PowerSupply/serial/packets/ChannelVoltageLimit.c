#include "ChannelVoltageLimit.h"

static struct Packet channelvoltagelimit_operation = {
	.writePacket = channelstatus_writePacket
};

void handleChannelVoltageLimit(struct ChannelVoltageLimit channelvoltagelimit)
{
	
}

void channelvoltagelimit_readPacket(void *channelvoltagelimit, ByteBuffer *buffer)
{
	struct ChannelVoltageLimit *this = channelvoltagelimit;
	buffer_get(buffer, &this->channel);
	buffer_getFloat(buffer, &this->data);
}

void channelvoltagelimit_writePacket(void *channelvoltagelimit, ByteBuffer *buffer)
{
	struct ChannelVoltageLimit *this = channelvoltagelimit;
	buffer_put(buffer, CHANNEL_CURRENT_LIMIT_MAX_SIZE);
	buffer_put(buffer, CHANNEL_CURRENT_LIMIT_ID);
	buffer_put(buffer, this->channel);
	buffer_putShort(buffer, this->data);
}