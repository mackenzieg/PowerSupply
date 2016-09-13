#include "ChannelCurrentLimit.h"

static struct Packet channelcurrentlimit_operation = {
	.writePacket = channelstatus_writePacket
};

void handleChannelCurrentLimit(struct ChannelCurrentLimit channelcurrentlimit)
{
	
}

void channelcurrentlimit_readPacket(void *channelcurrentlimit, ByteBuffer *buffer)
{
	struct ChannelCurrentLimit *this = channelcurrentlimit;
	buffer_get(buffer, &this->channel);
	buffer_getFloat(buffer, &this->data);
}

void channelcurrentlimit_writePacket(void *channelcurrentlimit, ByteBuffer *buffer)
{
	struct ChannelCurrentLimit *this = channelcurrentlimit;
	buffer_put(buffer, CHANNEL_CURRENT_LIMIT_MAX_SIZE);
	buffer_put(buffer, CHANNEL_CURRENT_LIMIT_ID);
	buffer_put(buffer, this->channel);
	buffer_putShort(buffer, this->data);
} 