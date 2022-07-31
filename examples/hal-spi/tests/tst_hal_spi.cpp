#include <gtest/gtest.h>

/*!
 * For C: Add your C-only include files in the extern-C section.
 */
extern "C"
{
#include "stm32f2xx_hal_conf.h"
}

#define SPIx SPI3

class TestHalSpi : public testing::Test
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


TEST_F(TestHalSpi, init)
{
    SPI_HandleTypeDef handle;
    handle.Instance               = SPIx;
    handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
    handle.Init.Direction         = SPI_DIRECTION_2LINES;
    handle.Init.CLKPhase          = SPI_PHASE_1EDGE;
    handle.Init.CLKPolarity       = SPI_POLARITY_HIGH;
    handle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
    handle.Init.CRCPolynomial     = 7;
    handle.Init.DataSize          = SPI_DATASIZE_8BIT;
    handle.Init.FirstBit          = SPI_FIRSTBIT_MSB;
    handle.Init.NSS               = SPI_NSS_SOFT;
    handle.Init.TIMode            = SPI_TIMODE_DISABLE;
    EXPECT_EQ(HAL_SPI_Init(&handle), HAL_OK);
}
