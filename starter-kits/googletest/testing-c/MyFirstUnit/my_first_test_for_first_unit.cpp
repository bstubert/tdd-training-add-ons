// Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

#include <gtest/gtest.h>

extern "C"
{
/*!
 * Add your c-only include files here!
 */
}

/*!
 * For each test marked TEST_F (e.g., MyFirstTestForFirstUnit.test1), GoogleTest performs
 * the following steps:
 *   - It creates a new MyFirstTestForFirstUnit object by calling its constructor.
 *   - It calls the function SetUp().
 *   - It calls the test (e.g., MyFirstTestForFirstUnit.test1)
 *   - It calls the function TearDown().
 *   - It destroys the MyFirstTestForFirstUnit object by calling its destructor.
 * We have a fresh MyFirstTestForFirstUnit object for each test. Hence, we can either use
 * the MyFirstTestForFirstUnit constructor or the SetUp() function for test setup. Similarly,
 * we can either use the MyFirstTestForFirstUnit destructor or the TearDown() function
 * for test teardown.
 */
class MyFirstTestForFirstUnit : public testing::Test
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

TEST_F(MyFirstTestForFirstUnit, test1)
{
    FAIL() << "Your test is running! Now delete this line and watch your test pass.";
    /*
     * Instantiate your class, or call the function, you want to test.
     * Then delete this comment
     */
}
