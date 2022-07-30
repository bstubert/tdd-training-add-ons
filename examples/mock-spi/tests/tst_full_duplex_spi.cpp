#include <gtest/gtest.h>

/*!
 * For C: Add your C-only include files in the extern-C section.
 */
extern "C"
{
#include "stm32f2xx_hal_conf.h"
}

#define SPIx SPI3

class TestSpiMaster : public testing::Test
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

/*
 * The HAL_SPI_Init call crashes on __HAL_SPI_DISABLE(hspi), which is defined as
 *
 *     CLEAR_BIT((__HANDLE__)->Instance->CR1, SPI_CR1_SPE)
 *
 * The crash is triggered by
 *
 *     (__HANDLE__)->Instance->CR1
 *
 * because (__HANDLE__)->Instance points to a STM32-specific memory address. This address
 * doesn't make any sense on a x86_64 computer.
 *
 * The memory address resolves to SPI3.
 *
 *     (__HANDLE__)->Instance == handle.instance == SPIx == SPI3
 *
 * SPI3 is defined in stm32f205xx.h as
 *
 *     SPI3                  ((SPI_TypeDef *) SPI3_BASE)
 *
 * where SPI3_BASE resolves as
 *
 *     SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)
 *     APB1PERIPH_BASE       PERIPH_BASE
 *     PERIPH_BASE           0x40000000UL
 *
 * The structure is defined in the same file. It has a field
 *
 *     // SPI control register 1 (not used in I2S mode),      Address offset: 0x00
 *     __IO uint32_t CR1;
 *
 * The structure has 9 registers each of type uint32_t (4 bytes). The first field has the address
 * SPI3_BASE = 0x40003C00UL, the second at SPI3_BASE + 4, the third at SPI3_BASE + 4, etc. The
 * total size of the structure is 9 * 4 = 36 bytes.
 *
 * We double the header stm32f205xx.h, because we must make SPI3 point to an address
 * of the x86_64 computer. As stm32f2xx.h includes stm32f2xx.h and both are in the same directory,
 * we must also double stm32f2xx.h.
 *
 * In stm32f205xx.h, we instantiate a global variable and assign its address to SPI3.
 *
 *     static inline SPI_TypeDef *spi3_base()
 *     {
 *         static SPI_TypeDef spi3 = {0};
 *         return &spi3;
 *     }
 *     #define SPI3 (spi3_base());
 *
 * We comment out the original definitions of SPI3_BASE and SPI3. The init test runs without
 * crashing.
 *
 */
TEST_F(TestSpiMaster, init)
{
    SPI_HandleTypeDef handle;
    handle.Instance               = SPIx;
    handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    handle.Init.Direction         = SPI_DIRECTION_2LINES;
    handle.Init.CLKPhase          = SPI_PHASE_2EDGE;
    handle.Init.CLKPolarity       = SPI_POLARITY_LOW;
    handle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
    handle.Init.CRCPolynomial     = 7;
    handle.Init.DataSize          = SPI_DATASIZE_8BIT;
    handle.Init.FirstBit          = SPI_FIRSTBIT_MSB;
    handle.Init.NSS               = SPI_NSS_SOFT;
    handle.Init.TIMode            = SPI_TIMODE_DISABLE;
    handle.Init.Mode              = SPI_MODE_MASTER;
    EXPECT_EQ(HAL_SPI_Init(&handle), HAL_OK);
    EXPECT_EQ(handle.ErrorCode, HAL_SPI_ERROR_NONE);
    EXPECT_EQ(handle.State, HAL_SPI_STATE_READY);

    // Check result of: __HAL_SPI_DISABLE(hspi);
    EXPECT_EQ(READ_BIT(handle.Instance->CR1, SPI_CR1_SPE), 0);

    // Check result of: WRITE_REG(hspi->Instance->CR1, ...);
    //
    // Result: 797 = 0000001100011101
    //
    // Bits set to 1:
    //
    // Bit 0:     Value: CLKPhase == SPI_PHASE_2EDGE == SPI_CR1_CPHA == 0x00000001
    //            Mask: SPI_CR1_CPHA == 0x00000001
    // Bit 2, 8:  Value: Mode == SPI_MODE_MASTER == (SPI_CR1_MSTR | SPI_CR1_SSI) == 0x00000104
    //            Mask: SPI_CR1_MSTR | SPI_CR1_SSI == 0x00000104
    // Bit 3, 4:  Value: BaudRatePrescaler == SPI_BAUDRATEPRESCALER_16 == (SPI_CR1_BR_1 | SPI_CR1_BR_0) == 0x00000018
    //            Mask: SPI_CR1_BR_Msk == 0x00000038
    // Bit 9:     Value: NSS == SPI_NSS_SOFT == SPI_CR1_SSM ==  0x00000200
    //            Mask: SPI_CR1_SSM == 0x00000200
    //
    // Bits set to 0:
    //
    // Value: Direction == SPI_DIRECTION_2LINES  == (0x00000000U)
    // Value: DataSize == SPI_DATASIZE_8BIT == (0x00000000U)
    // Value: CLKPolarity == SPI_POLARITY_LOW == (0x00000000U)
    EXPECT_EQ(READ_REG(handle.Instance->CR1), 0b0000001100011101);

    // Check result of: WRITE_REG(hspi->Instance->CR2, ...);
    //
    // Result: 0
    //
    // NSS == 0x00000200; NSS >> 16U = 0; Check: When is NSS != 0?
    // Value: TIMode == SPI_TIMODE_DISABLE == (0x00000000U); Mask: SPI_CR2_FRF == 0x00000010
    //
    EXPECT_EQ(READ_REG(handle.Instance->CR2), 0);
}
