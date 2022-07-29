#include <gtest/gtest.h>

/*!
 * For C: Add your C-only include files in the extern-C section.
 * For C++: Remove the extern-C section and just add your C++-ony include files here.
 */
extern "C"
{
}

class TestFullDuplexSpi : public testing::Test
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

TEST_F(TestFullDuplexSpi, init)
{
    FAIL() << "Your test is running! Now delete this line and watch your test pass.";
     /*
      * Instantiate the class or call the function you want to test.
      * Then delete this comment.
      */
}
