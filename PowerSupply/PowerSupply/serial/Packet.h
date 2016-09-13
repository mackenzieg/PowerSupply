#ifndef PACKET_H_
#define PACKET_H_

#include <stdio.h>
#include "packets/Handshake.h"
#include "packets/ChannelCurrent.h"
#include "packets/ChannelStatus.h"
#include "packets/ChannelCurrentLimit.h"
#include "packets/ChannelVoltageLimit.h"
#include "../util/ByteBuffer.h"

struct Packet {
	void (*writePacket)(void *packet, ByteBuffer *buffer);
	void (*readPacket)(void *packet, ByteBuffer *buffer);
};

#endif