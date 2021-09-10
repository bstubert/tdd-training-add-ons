#pragma once

#include <stdint.h>

typedef struct ringbuffer_instance_t* ringbuffer_t;

ringbuffer_t ringbuffer_create(uint32_t capacity);
uint32_t ringbuffer_capacity(ringbuffer_t instance);
