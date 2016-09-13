#include "ChannelStatus.h"

static struct Packet channelstatus_operation = {
	.writePacket = channelstatus_writePacket
};

void handleChannelStatus(struct ChannelStatus channelstatus)
{
	
}

void channelstatus_readPacket(void *channelstatus, ByteBuffer *buffer)
{
	struct ChannelStatus *this = channelstatus;
	buffer_getChar(buffer, &this->data);
}

void channelstatus_writePacket(void *channelstatus, ByteBuffer *buffer)
{
	struct Handshake *this = channelstatus;
	buffer_put(buffer, CHANNEL_STATUS_MAX_SIZE);
	buffer_put(buffer, CHANNEL_STATUS_ID);
	buffer_put(buffer, this->data);
}