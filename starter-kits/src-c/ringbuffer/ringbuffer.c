#include <stdlib.h>
#include "ringbuffer.h"

struct ringbuffer_instance_t {
    uint32_t capacity;
};

ringbuffer_t ringbuffer_create(uint32_t capacity)
{
    ringbuffer_t inst = calloc(1, sizeof(struct ringbuffer_instance_t));
    inst->capacity = capacity;
    return inst;
}

uint32_t ringbuffer_capacity(ringbuffer_t this)
{
    return this->capacity;
}

void ringbuffer_destroy(ringbuffer_t instance)
{
    if (instance)
    {
        free(instance);
    }
}
