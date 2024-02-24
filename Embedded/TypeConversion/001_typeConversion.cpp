
/* C++ is more strict for typecasting */
Entry *temp = const_cast<Entry*>(new);




//Getting the 16bits
int x = 0x0A0B0C0D;
short y = x & 0xFFFF;
printf("short value = 0x%d\n",y);   
option-1: short y = (short)x;
option2: x&0xFFFF
option3: short y = *(short*)&x;