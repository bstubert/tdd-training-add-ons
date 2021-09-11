// Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

#include <gtest/gtest.h>

extern "C"
{
/*!
 * Add your c-only include files here!
 */
#include "ringbuffer.h"
}

// The ringbuffer example is taken from Nick Miller's post "Practical Design Patterns:
// Opaque Pointers and Objects in C" (https://interrupt.memfault.com/blog/opaque-pointers).
class TestIncompatibleCCpp : public testing::Test
{
protected:
    // This function is called before the execution of each TEST.
    void SetUp() override
    {
    }

    // This function is called after the execution of each TEST.
    void TearDown() override
    {
    }
};

TEST_F(TestIncompatibleCCpp, capacity)
{
    ringbuffer_t rb = ringbuffer_create(5);
    EXPECT_EQ(ringbuffer_capacity(rb), 5);
}
