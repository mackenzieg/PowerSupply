#ifndef CHANNELVOLTAGELIMIT_H_
#define CHANNELVOLTAGELIMIT_H_

#define CHANNEL_VOLTAGE_LIMIT_ID 1
#define CHANNEL_VOLTAGE_LIMIT_SIZE 32

#include "../../util/ByteBuffer.h"
#include "../Packet.h"

struct ChannelVoltageLimit {
	uint8_t channel;
	float data;
	struct Packet *packet;
};

void handleChannelVoltageLimit(struct ChannelVoltageLimit channelvoltagelimit);

void channelvoltagelimit_readPacket(void *channelvoltagelimit, ByteBuffer *buffer);

void channelvoltagelimite_writePacket(void *channelvoltagelimit, ByteBuffer *buffer);

#endif