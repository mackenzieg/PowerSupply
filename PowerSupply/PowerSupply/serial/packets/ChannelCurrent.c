#include "ChannelCurrent.h"

static struct Packet channelcurrent_operation = {
	.writePacket = channelcurrent_writePacket
};

void handleChannelCurrent(struct ChannelCurrent channelcurrent)
{
	
}

void channelcurrent_readPacket(void *channelcurrent, ByteBuffer *buffer)
{
	struct ChannelCurrent *this = channelcurrent;
	buffer_get(buffer, &this->channel);
	buffer_getFloat(buffer, &this->data);
}

void channelcurrent_writePacket(void *channelcurrent, ByteBuffer *buffer)
{
	struct ChannelCurrent *this = channelcurrent;
	buffer_put(buffer, CHANNEL_CURRENT_MAX_SIZE);
	buffer_put(buffer, CHANNEL_CURRENT_ID);
	buffer_put(buffer, this->channel);
	buffer_putShort(buffer, this->data);
}