/*write a function that counts the number of one bits in a number*/

    0000 0000 0000 0001. - moves to left
    1111 1101 0000 0001
int counter(uint8_t *number,int size)    {
    int count=0;
    for(int j=0;j<(int)(size/8);j++)
    {
        for(int i=0;i<8;i++)   
        //count+=(int)((number&&(0x1<<i))!=0);
            if(((*number)&&(0x1<<i))!=0)   count++;
        number++;
    }
    return count;
}
