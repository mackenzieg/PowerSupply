#ifndef BYTEBUFFER_H_
#define BYTEBUFFER_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
//https://github.com/hawstan/ByteBuffer/blob/master/ByteBuffer.h

typedef struct {
	uint16_t size;
	uint8_t *data;
	uint16_t position;
} ByteBuffer;

ByteBuffer* buffer_allocate(uint16_t size);

void buffer_free(ByteBuffer *buffer);

void buffer_clear(ByteBuffer *buffer);

void buffer_compact(ByteBuffer *buffer);

bool buffer_put(ByteBuffer *buffer, uint8_t data);

bool buffer_putShort(ByteBuffer *buffer, uint16_t data);

bool buffer_putInt(ByteBuffer *buffer, uint32_t data);

bool buffer_putChar(ByteBuffer *buffer, char data);

bool buffer_get(ByteBuffer *buffer, uint8_t *output);

bool buffer_getShort(ByteBuffer *buffer, int16_t *output);

bool buffer_getFloat(ByteBuffer *buffer, float *output);

bool buffer_getInt(ByteBuffer *buffer, int32_t *output);

bool buffer_getChar(ByteBuffer *buffer, char *output);

#endif