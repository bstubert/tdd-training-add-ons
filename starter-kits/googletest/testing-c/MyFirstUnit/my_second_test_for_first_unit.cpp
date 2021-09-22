// Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

#include <gtest/gtest.h>

extern "C"
{
/*!
 * Add your c-only include files here!
 */
}

class MySecondTestForFirstUnit : public testing::Test
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

TEST_F(MySecondTestForFirstUnit, test1)
{
    FAIL() << "Your test is running! Now delete this line and watch your test pass.";
    /*
     * Instantiate your class, or call the function, you want to test.
     * Then delete this comment
     */
}
