#pragma once

#include <stdint.h>

// With both typedefs uncommented, we have valid C code but invalid C++.
// The C++ compiler spits out the following error messages:
//     ringbuffer.h:14:16: error: typedef 'ringbuffer_instance_t' cannot be referenced with a struct specifier
//       typedef struct ringbuffer_instance_t* ringbuffer_t;
//     ringbuffer.h:13:14: note: declared here
//       typedef void ringbuffer_instance_t;
// With the first typedef commented out, the C++ compiler is happy, too. Then, we have both valid C
// and valid C++.
typedef void ringbuffer_instance_t;
typedef struct ringbuffer_instance_t* ringbuffer_t;

ringbuffer_t ringbuffer_create(uint32_t capacity);
uint32_t ringbuffer_capacity(ringbuffer_t instance);
