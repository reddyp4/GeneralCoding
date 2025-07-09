/*
8-byte chunks
uint8_t memWritePage -> page to write to
uint8_t writeBuffer[8]; = data of 8bytes 
uint16_t performMemWrite;   0x1234, starts writes 

*/

/*
512 = 8*64 
513= 8*64+1


*/

void pageWrite(int startAddr,int *data, int length)
{
    uint8_t addr,dataptr;       //dataptr moves in chunks of 8bytes 
    if(length<=0)   return;
    dataptr=0;  //needs to go to length
    //loop for updating the start addr
    for(int i=0;i<length/8;i++) //0 to 511
    {
        //addr to be written into
        dataptr=i*8;
        memWritePage=startAddr+dataptr;
        writeBuffer=data+dataptr;
        //
        performMemWrite = 0x1234;
        while(flag);
        performMemWrite = 0x0;
    }
    for(int i=0;i<(length-dataptr);i++) //512 to 512
    {
        //=startAddr+dataptr;
        memcpy(data,dest,1);
    }



}