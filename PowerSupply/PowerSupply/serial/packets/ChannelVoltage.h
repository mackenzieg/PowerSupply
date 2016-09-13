#ifndef CHANNELVOLTAGE_H_
#define CHANNELVOLTAGE_H_

#define CHANNEL_VOLTAGE_ID 5
#define CHANNEL_VOLTAGE_MAX_SIZE 32

#include "../../util/ByteBuffer.h"
#include "../Packet.h"

struct ChannelVoltage {
	uint8_t channel;
	float data;
	struct Packet *packet;
};

void handleChannelVoltage(struct ChannelVoltage channelvoltage);

void channelvoltage_readPacket(void *channelvoltage, ByteBuffer *buffer);

void channelvoltage_writePacket(void *channelvoltage, ByteBuffer *buffer);

#endif