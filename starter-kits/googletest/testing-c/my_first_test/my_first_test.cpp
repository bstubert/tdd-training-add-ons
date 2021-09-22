// Copyright (C) 2021, Burkhard Stubert (DBA Embedded Use)

#include <gtest/gtest.h>

extern "C"
{
/*!
 * Add your c-only include files here!
 */
}

/*!
 * For each test marked TEST_F (e.g., my_first_test.test1), GoogleTest performs
 * the following steps:
 *   - It creates a new my_first_test object by calling its constructor.
 *   - It calls the function SetUp().
 *   - It calls the test (e.g., my_first_test.test1)
 *   - It calls the function TearDown().
 *   - It destroys the my_first_test object by calling its destructor.
 * We have a fresh my_first_test object for each test. Hence, we can either use
 * the my_first_test constructor or the SetUp() function for test setup. Similarly,
 * we can either use the my_first_test destructor or the TearDown() function
 * for test teardown.
 */
class my_first_test : public testing::Test
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

TEST_F(my_first_test, test1)
{
    FAIL() << "Your test is running! Now delete this line and watch your test pass.";
    /*
     * Instantiate your class, or call the function, you want to test.
     * Then delete this comment
     */
}
