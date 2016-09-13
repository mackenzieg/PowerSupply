#include "Handshake.h"

static struct Packet handshake_operation = {
	.writePacket = handshake_writePacket
};

void handleHandshake(struct Handshake handshake)
{
	
}

void handshake_readPacket(void *handshake, ByteBuffer *buffer)
{
	struct Handshake *this = handshake;
	buffer_get(buffer, &this->data);
}

void handshake_writePacket(void *handshake, ByteBuffer *buffer)
{
	struct Handshake *this = handshake;
	buffer_put(buffer, HANDSHAKE_MAX_SIZE);
	buffer_put(buffer, HANDSHAKE_ID);
	buffer_put(buffer, this->data);
}