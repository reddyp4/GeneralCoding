/* Convert big endian to little endian and vice versa */
#include<stdio.h>
#include<stdint.h>

/*0x12345678 to 0x78563412*/
void change_endian(char* input, char* output, uint64_t size)
{
    for(char i=0;i<size;i++)
    {
        *(output+i)=*(input+size-1-i);
    }
}

int main()
{
    char input[4]={0x12,0x34,0x56,0x78};
    char output[4];
    change_endian(input,output,4);
    for(int i=0;i<4;i++)
    {
        printf("Input:%x,Output=%x\n",input[i],output[i]);
    }
    return 1;
}