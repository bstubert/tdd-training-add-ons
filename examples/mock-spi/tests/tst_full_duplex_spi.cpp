#include <gtest/gtest.h>

/*!
 * For C: Add your C-only include files in the extern-C section.
 */
extern "C"
{
#include "stm32f2xx_hal_conf.h"
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
    HAL_SPI_Init(nullptr);
}
