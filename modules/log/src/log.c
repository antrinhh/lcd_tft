#include "log.h"
#include "usart.h"
#include <stdint.h>

int _write(int file, char *ptr, int len)
{
    (void)file;
    HAL_StatusTypeDef ret = HAL_UART_Transmit(&huart4, (uint8_t *)ptr, sizeof(*ptr), HAL_MAX_DELAY);
    if (ret != HAL_OK)
    {
        return ret;
    }
    return len;
}

void log_info(const char *fmt, ...)
{
    printf("[I] ");

    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

    printf("\r\n");
}