/*
How do you multiply without using multiply or divide instructions for a multiplier constant of 10, 31, 132?

2*10 = 20
2*31 = 
2*132 = 

y = 2^x + z

8*10 = 8*8 + 8*2
10 = 2^3 + 2
132 = 2^7+6=2^7+2^2+2

*/
int multiplyBy10(int a)
{
    int i,a1,a2;
    a1=a;
    for(i=0;i<3;i++)
        a1=a1<<1U;
    a2=a<<1U;
    return (a1+a2);
}

//31 = 32-1=2^5-1, 8*31=8*31-8
int multiplyBy31(int a)
{
    int i,a1,a2;
    a1=a;
    for(i=0;i<5;i++)
        a1=a1<<1U;
    a2=a;
    return (a1-a2);
}

//132= 2^7+6=2^7+2^2=128+4
int multiplyBy132(int a)
{
    int i,a1,a2,a3;
    a1=a<<7U;
    a2=a<<2U;
    a3=a<<1U;
    printf("%d,%d,%d\n",a1,a2,a3);
    return (a1+a2);
}
