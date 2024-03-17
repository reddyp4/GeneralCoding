/* spi_hw.c:    Patel B Reddy */


#define SPI_FPGA_FREQUENCY  (5000000)   //5MHz
#define SPI_DBGR_FREQUENCY  (25000000)  //25MHz
#define SPI_EXT_FLASH_FREQUENCY (5000000)   //5MHz

/* Parameters for each SPI Module (multiple modules on chip) */
typedef struct spi_handle_t
{
    uint32_t base;      //base pointer
    uint32_t gpio_cs;   //gpio pin number for chip select for each spi
    uint32_t frequency; //spi clock frequency
    uint32_t mode;      //clock phase and polarity
    uint32_t master;    //defines who the master is
    uint32_t data_size; //transfer data width over spi
    uint32_t mosi;      //mosi pin configuration
    uint32_t miso;      //miso pin configuration
    uint32_t sck;       //serial clock configuration
    uint32_t cs;        //chip select configuration
    uint32_t fifo_tx_irq;   //'0' for no irq, '1' otherwise
    uint32_t fifo_rx_irq;   //'0' for no irq, '1' otherwise
    uint32_t fifo_tx_irq_lvl;   //TX FIFO IRQ LEVEL (0-16) TI
    uint32_t fifo_rx_irq_lvl;   //RX FIFO IRQ LEVEL (0-16) TI
    uint16_t rx_fifo_reset;     //Reset the RX FIFO
} spi_handle_t;

