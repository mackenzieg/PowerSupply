#ifndef CHANNELCURRENTLIMIT_H_
#define CHANNELCURRENTLIMIT_H_

#define CHANNEL_CURRENT_LIMIT_ID 4
#define CHANNEL_CURRENT_LIMIT_MAX_SIZE 32

#include "../../util/ByteBuffer.h"
#include "../Packet.h"

struct ChannelCurrentLimit {
	uint8_t channel;
	float data;
	struct Packet *packet;
};

void handleChannelCurrentLimit(struct ChannelCurrentLimit channelcurrentlimit);

void channelcurrentlimit_readPacket(void *channelcurrentlimit, ByteBuffer *buffer);

void channelcurrentlimit_writePacket(void *channelcurrentlimit, ByteBuffer *buffer);

#endif