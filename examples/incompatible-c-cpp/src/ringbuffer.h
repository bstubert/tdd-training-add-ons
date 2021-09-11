#pragma once

#include <stdint.h>

// With both typedefs uncommented, we have valid C code but invalid C++.
// The C++ compiler spits out the following error messages:
//     ringbuffer.h:12:16: error: typedef 'ringbuffer_instance_t' cannot be referenced with a struct specifier
//     ringbuffer.h:11:14: note: declared here
// With the first typedef commented out, the C++ compiler is happy, too. Then, we have both valid C
// and valid C++.
typedef void ringbuffer_instance_t;
typedef struct ringbuffer_instance_t* ringbuffer_t;

ringbuffer_t ringbuffer_create(uint32_t capacity);

// Using "this" as the parameter name is valid C but not valid C++, because "this" is a C++
// keyword. Replace "this" by "instance" in the header file and in the source file.
// ringbuffer.h:19:43: error: invalid parameter name: 'this' is a keyword
uint32_t ringbuffer_capacity(ringbuffer_t this);

void ringbuffer_destroy(ringbuffer_t instance);