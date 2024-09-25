/* Basic SPI driver */


typedef struct {
    uint8_t slave_select;   /* select slave */
    uint8_t cpol;           /* Polarity */
    uint8_t cpha;           /* */
    uint8_t channel;        /* quad spi 1-4 */
    uint8_t datasize;       /* data size */
    uint8_t tx_watermark;   /* check CRC of tx */
    uint8_t rx_watermark;   
} spi_master_t;

enum {
    SPI_SUCCESS,
    SPI_FAIL
} spi_err;

/* Common functions */
static spi_err spi_init (spi_master *spi)
{
    spi->slave_select = INIT_VALUE;
}

static spi_err spi_rw (spi_master *spi, uint8_t rbuf, const uint8_t *wrbuf)
{
    /* Select the slave */
    write(spi->slave_select, LOW);
    /* Write to wrbuf */
    for (int i=0; i<8; ++i)
    {
        /* Send rbuf, 8b in one byte */
        write(spi->MOSI, bitRead(rbuf, i));
        write(spi->CLK, HIGH);
        read(wrbuf, i, read(spi->MISO));
        write(CLK, LOW);
    }
    write(spi->slave_select,HIGH);
    return spi_err_check(wrbuf);
    /* Read from the buffer */
}

static spi_err spi_close(spi_master* spi)
{
    /**/
}