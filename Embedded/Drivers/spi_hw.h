/* This is a header for a general purpose gpio driver */

/* Double inclusion guard */
#ifndef SPI_HW_H
#define SPI_HW_H

#include<stdbool.h>
#include<stdint.h>
#include<hw_types.h>

/* enumeration for different modules */
typedef enum spi_id
{
    SPI_FPGA=0,
    SPI_FLASH,
    SPI_DEBUGGER,
    SPI_COUNT
} spi_device_id;

/* SPI enum for time slicing, if any */
typedef enum spi_bus
{
    FPGA_TRANSMIT_CYCLE=0,
    FPGA_RECEIVE_CYCLE,
    SPI_DBGR_TRANSMIT_CYCLE,
    SPI_UNUSED
} spi_bus;

/* spi functions */
void spi_init();
void spi_configure_bus();
void spi_cs(spi_device_id target, bool enable);
void spi_receive(spi_device_id dev, uint8_t *data, int length);
void spi_transmit(spi_device_id dev, uint8_t *data, int length);


#endif