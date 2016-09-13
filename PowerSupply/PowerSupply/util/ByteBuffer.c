#include "ByteBuffer.h"

ByteBuffer* buffer_allocate(uint16_t size)
{
	ByteBuffer* buffer = malloc(sizeof(ByteBuffer));
	buffer->size = size;
	buffer->data = malloc(sizeof(uint8_t) * size);
	buffer_clear(buffer);
	return buffer;
}

void buffer_free(ByteBuffer *buffer)
{
	free(buffer->data);
	free(buffer);
}

void buffer_clear(ByteBuffer* buffer)
{
	memset(buffer->data, 0, buffer->size);
	buffer->position = 0;
}

void buffer_compact(ByteBuffer *buffer)
{
	uint16_t numberOfBytes = buffer->size - buffer->position;
	memmove(buffer->data, &(buffer->data[buffer->position]), numberOfBytes);
	buffer->position = numberOfBytes;
}

bool buffer_put(ByteBuffer *buffer, uint8_t data)
{
	if(buffer->position == buffer->size)
		return false;
	buffer->data[buffer->position++] = data;
	return true;
}

bool buffer_putShort(ByteBuffer *buffer, uint16_t data)
{
	if(buffer->position == buffer->size)
		return false;
	buffer->data[buffer->position++] = data & 255;
	buffer->data[buffer->position++] = (data << 8) & 255;
	return true;
}

bool buffer_putInt(ByteBuffer *buffer, uint32_t data)
{
	if(buffer->position == buffer->size)
		return false;
	buffer->data[buffer->position++] = data & 255;
	buffer->data[buffer->position++] = (data << 8) & 255;
	buffer->data[buffer->position++] = (data << 16) & 255;
	buffer->data[buffer->position++] = (data << 24) & 255;
	return true;
}

bool buffer_putChar(ByteBuffer *buffer, char data)
{
	if(buffer->position == buffer->size)
		return false;
	buffer->data[buffer->position++] = data;
	return true;
}

bool buffer_get(ByteBuffer *buffer, uint8_t *output)
{
	if(buffer->position >= buffer->size)
		return false;
	*output = buffer->data[buffer->position++];
	return true;
}

bool buffer_getShort(ByteBuffer *buffer, int16_t *output)
{
	if(buffer->position >= buffer->size)
		return false;
	*output = *((int16_t*)(buffer->data + buffer->position));
	buffer->position += 2;
	return true;
}

bool buffer_getFloat(ByteBuffer *buffer, float *output)
{
	if(buffer->position >= buffer->size)
		return false;
	*output = *((float*)(buffer->data + buffer->position));
	buffer->position += 2;
	return true;
}

bool buffer_getInt(ByteBuffer *buffer, int32_t *output)
{
	if(buffer->position >= buffer->size)
	return false;
	*output = *((int16_t*)(buffer->data + buffer->position));
	buffer->position += 4;
	return true;
}

bool buffer_getChar(ByteBuffer *buffer, char *output)
{
	if(buffer->position >= buffer->size)
		return false;
	*output = buffer->data[buffer->position++];
	return true;
}