#ifndef _I2C_BUS_H_
#define _I2C_BUS_H_

#include <stdint.h>

#define I2C_TIMEOUT_MS 20

typedef struct
{
    uint16_t address;
    void *handle;
} i2c_handle_t;

int8_t i2c_write_bytes(i2c_handle_t *dev, uint8_t reg, uint8_t *tx_buff, uint16_t len);
int8_t i2c_read_bytes(i2c_handle_t *dev, uint8_t reg, uint8_t *rx_buff, uint16_t len);
int8_t i2c_write(i2c_handle_t *dev, uint8_t *tx_buff, uint16_t len);
int8_t i2c_read(i2c_handle_t *dev, uint8_t *rx_buff, uint16_t len);

#endif // _I2C_BUS_H_