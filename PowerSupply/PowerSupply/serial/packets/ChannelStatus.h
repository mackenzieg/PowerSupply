#ifndef CHANNELSTATUS_H_
#define CHANNELSTATUS_H_

#define CHANNEL_STATUS_ID 3
#define CHANNEL_STATUS_MAX_SIZE 16

#include "../../util/ByteBuffer.h"
#include "../Packet.h"

struct ChannelStatus {
	uint8_t data;
	struct Packet *packet;
};

void handleChannelStatus(struct ChannelStatus channelstatus);

void channelstatus_readPacket(void *channelstatus, ByteBuffer *buffer);

void channelstatus_writePacket(void *channelstatus, ByteBuffer *buffer);

#endif