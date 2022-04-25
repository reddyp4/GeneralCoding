/* Rights: Patel B Reddy */
/* Date: 04/03/2022 */

#include<stdio.h>
#include<stdint.h>

#define byte    uint8_t

static byte compute_CRC(byte byteEval)
{
    uint16_t counter;
    uint8_t MSB=0;
    uint8_t newbit=0;

    const byte generator = 0x1D;
    //counter should be length of byteEval, which is byte
    // Initialize CRC register with zero
    byte crc = byteEval;
    for(counter=0;counter<8;counter++)
    {
        // Get MSB
        MSB = (crc&0x80);
        // Get new bit data value into crc
        newbit = byteEval&0x80;
        //Shift data
        byteEval = byteEval<<1;
        //Get new data into shifted crc
        crc = (crc<<1)||(newbit>>7);
        // check MSB of CRC
        if(MSB==1)
        {
            //XOR
            crc = crc^generator;
        }
        else
        {
            //Shift CRC register
            crc = crc<<1;
        }
        //Print all values
        printf("data=%x,newbit=%x,crc=%x,MSB=%x \n",byteEval,newbit,crc,MSB);
    }
}

void main()
{
    //Initiate data, assume data is 8-bits
    uint8_t data = 0x2D;
    //Calculate crc
    uint8_t crc = compute_CRC(data);
    //print crc & data
    printf("Data = %x, CRC = %x \n",data,crc);
}
