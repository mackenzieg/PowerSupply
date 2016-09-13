#ifndef HANDSHAKE_H_
#define HANDSHAKE_H_

#define HANDSHAKE_ID 1
#define HANDSHAKE_MAX_SIZE 16

#include "../../util/ByteBuffer.h"
#include "../Packet.h"

struct Handshake {
	uint8_t data;
	struct Packet *packet;
};

void handleHandshake(struct Handshake handshake);

void handshake_readPacket(void *handshake, ByteBuffer *buffer);

void handshake_writePacket(void *handshake, ByteBuffer *buffer);

#endif