#ifndef CHANNELCURRENT_H_
#define CHANNELCURRENT_H_

#define CHANNEL_CURRENT_ID 2
#define CHANNEL_CURRENT_MAX_SIZE 32

#include "../../util/ByteBuffer.h"
#include "../Packet.h"

struct ChannelCurrent {
	uint8_t channel;
	float data;
	struct Packet *packet;
};

void handleChannelCurrent(struct ChannelCurrent channelcurrent);

void channelcurrent_readPacket(void *channelcurrent, ByteBuffer *buffer);

void channelcurrent_writePacket(void *channelcurrent, ByteBuffer *buffer);

#endif