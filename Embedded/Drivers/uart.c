/* UART driver: 
*/

isr()
{
    if (reg & TX_EMPTY)
        signal(tx_thread);
    if(reg & RX_FULL)
        signal(rx_thread);
}

//multiple thread calling
uint32_t tx_thread(int handle, uint8_t buffer, uint32_t size)
{
    int count = 0;

    if(reg & TX_FULL)
        cond_wait(tx_thread);
    
    /* transmit while 1) control register is not set 2) TX is not full 3) count is reached */
    while(!(reg & TX_FULL) && (count<size) )
    {
        *wr_reg = buffer[count];
        count++;
    }

    return count;
}