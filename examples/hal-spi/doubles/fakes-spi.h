#ifndef FAKESSPI_H
#define FAKESSPI_H

#include <stdint.h>

#include "stm32f2xx_hal_def.h"

typedef struct __DMA_HandleTypeDef
{
    uint32_t               ErrorCode;                                                    /*!< DMA Error code                          */

    uint32_t               StreamBaseAddress;                                            /*!< DMA Stream Base Address                */

    uint32_t               StreamIndex;                                                  /*!< DMA Stream Index                       */

} DMA_HandleTypeDef;

#endif // FAKESSPI_H
