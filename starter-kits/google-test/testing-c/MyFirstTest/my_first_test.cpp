// Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

#include <gtest/gtest.h>

using namespace testing;

/*!
 * For each test marked TEST_F (e.g., MyFirstTest.test1), GoogleTest performs the following steps:
 *   - It creates a new MyFirstTest object by calling its constructor.
 *   - It calls the function SetUp().
 *   - It calls the test (e.g., MyFirstTest.test1)
 *   - It calls the function TearDown().
 *   - It destroys the MyFirstTest object by calling its destructor.
 * We have a fresh MyFirstTest object for each test. Hence, we can either use the MyFirstTest
 * constructor or the SetUp() function for test setup. Similarly, we can either use the
 * MyFirstTest destructor or the TearDown() function for test teardown.
 */
class MyFirstTest : public testing::Test
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

TEST_F(MyFirstTest, test1)
{
    FAIL() << "Your test is running! Now delete this line and watch your test pass.";
    /*
     * Instantiate your class, or call the function, you want to test.
     * Then delete this comment
     */
}
