// Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

#include <gtest/gtest.h>

extern "C"
{
/*!
 * Add your c-only include files here!
 */
}

/*!
 * For each test marked TEST_F (e.g., MyFirstTestForSecondUnit.test1), GoogleTest performs
 * the following steps:
 *   - It creates a new MyFirstTestForSecondUnit object by calling its constructor.
 *   - It calls the function SetUp().
 *   - It calls the test (e.g., MyFirstTestForSecondUnit.test1)
 *   - It calls the function TearDown().
 *   - It destroys the MyFirstTestForSecondUnit object by calling its destructor.
 * We have a fresh MyFirstTestForSecondUnit object for each test. Hence, we can either use
 * the MyFirstTestForSecondUnit constructor or the SetUp() function for test setup. Similarly,
 * we can either use the MyFirstTestForSecondUnit destructor or the TearDown() function
 * for test teardown.
 */
class MyFirstTestForSecondUnit : public testing::Test
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

TEST_F(MyFirstTestForSecondUnit, test1)
{
    FAIL() << "Your test is running! Now delete this line and watch your test pass.";
    /*
     * Instantiate your class, or call the function, you want to test.
     * Then delete this comment
     */
}
