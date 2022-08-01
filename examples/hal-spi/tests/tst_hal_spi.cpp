#include <memory>

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
        m_handle = std::make_unique<SPI_HandleTypeDef>();
        m_handle->Instance               = SPIx;
        m_handle->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
        m_handle->Init.Direction         = SPI_DIRECTION_2LINES;
        m_handle->Init.CLKPhase          = SPI_PHASE_1EDGE;
        m_handle->Init.CLKPolarity       = SPI_POLARITY_HIGH;
        m_handle->Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
        m_handle->Init.CRCPolynomial     = 7;
        m_handle->Init.DataSize          = SPI_DATASIZE_8BIT;
        m_handle->Init.FirstBit          = SPI_FIRSTBIT_MSB;
        m_handle->Init.NSS               = SPI_NSS_SOFT;
        m_handle->Init.TIMode            = SPI_TIMODE_DISABLE;
        EXPECT_TRUE(m_handle);
    }

    // This function is called after the execution of each TEST.
    void TearDown() override
    {
    }

    std::unique_ptr<SPI_HandleTypeDef> m_handle;
};


TEST_F(TestHalSpi, init)
{
    EXPECT_EQ(HAL_SPI_Init(m_handle.get()), HAL_OK);
    EXPECT_EQ(READ_REG(m_handle->Instance->CR1), 570);
    EXPECT_EQ(READ_REG(m_handle->Instance->CR2), 0);
}
