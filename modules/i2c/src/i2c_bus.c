#include "i2c.h"
#include "i2c_bus.h"

int8_t i2c_write_bytes(i2c_handle_t *dev, uint8_t reg, uint8_t *tx_buff, uint16_t len)
{
    if (!tx_buff || !dev || !dev->handle)
        return -1;

    uint16_t address = (dev->address << 1);
    I2C_HandleTypeDef *i2c = (I2C_HandleTypeDef *)dev->handle;
    HAL_StatusTypeDef ret = HAL_I2C_Mem_Write(i2c, address, reg, I2C_MEMADD_SIZE_8BIT, tx_buff, len, I2C_TIMEOUT_MS);
    if (ret != HAL_OK)
    {
        return -1;
    }
    return 0;
}

int8_t i2c_read_bytes(i2c_handle_t *dev, uint8_t reg, uint8_t *rx_buff, uint16_t len)
{
    if (!rx_buff || !dev || !dev->handle)
        return -1;

    uint16_t address = (dev->address << 1);
    I2C_HandleTypeDef *i2c = (I2C_HandleTypeDef *)dev->handle;
    HAL_StatusTypeDef ret = HAL_I2C_Mem_Read(i2c, address, reg, I2C_MEMADD_SIZE_8BIT, rx_buff, len, I2C_TIMEOUT_MS);
    if (ret != HAL_OK)
    {
        return -1;
    }
    return 0;
}

int8_t i2c_write(i2c_handle_t *dev, uint8_t *tx_buff, uint16_t len)
{
    if (!tx_buff || !dev || !dev->handle)
        return -1;

    uint16_t address = (dev->address << 1);
    I2C_HandleTypeDef *i2c = (I2C_HandleTypeDef *)dev->handle;
    HAL_StatusTypeDef ret = HAL_I2C_Master_Transmit(i2c, address, tx_buff, len, I2C_TIMEOUT_MS);
    if (ret != HAL_OK)
    {
        return -1;
    }
    return 0;
}

int8_t i2c_read(i2c_handle_t *dev, uint8_t *rx_buff, uint16_t len)
{
    if (!rx_buff || !dev || !dev->handle)
        return -1;

    uint16_t address = (dev->address << 1);
    I2C_HandleTypeDef *i2c = (I2C_HandleTypeDef *)dev->handle;
    HAL_StatusTypeDef ret = HAL_I2C_Master_Receive(i2c, address, rx_buff, len, I2C_TIMEOUT_MS);
    if (ret != HAL_OK)
    {
        return -1;
    }
    return 0;
}