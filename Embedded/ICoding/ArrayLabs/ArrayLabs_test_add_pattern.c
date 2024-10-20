/* int add(int a, int b), w/o addition */
/* a=2, b=3, 0b10, 0b11 */
/* +1, ^0x1, else +0x1 */

/* 10
   11

  101
  
  Bit1  Bit2  prev-carryon  total    next-carry
  0     0     0             0           0
  0     0     1             1           0
  1     0     0             1           1
  1     1     0             0           1
  1     1     1             1           1
  */

/* int here 16bits */
int add(int a, int b)
{
    int carryon=0;
    for(int i=0;i<16;i++)
    {
        //          bit1            bit2        carryon
        bit_a_b = (a&(0x1<<i)) ^ (b&(0x1<<i)) ^ (carryon);
        carryon = ((a&(0x1<<i)) & (b&(0x1<<i))) | ((b&(0x1<<i)) ^ (carryon)) | ((a&(0x1<<i))|(carryon));

        sum |= bit_a_b;
    }
    return sum;
}

int sub(int a, int b)
{
    //return (a,-b);
    //if b is highest
    int comp_2_b = add(~b,1);  //2s complement = invert b and add 1
    return(add(a,comp_2_b));
}

// packet = 0x5A followed by data, location is 5 bytes
ID = 0x5A;
bool packet_recognize(uint8_t *packet, uint8_t* data)  //packet is 128 bits- 16bytes
{
    //loop
    uint8_t current;
    bool found=FALSE;
    for(int i=0;i<120;i++)
    {
        current=packet>>i;
        if(current==(uint8_t)(packet&0xFF))
        {
            found=TRUE;
            memcpy(packet+i+8,data++,1);   //src, dst, length in bytes
        }
    }
    return found;
}

