/* Product of a*b without using multiplication */
#include<iostream>
#include<bitset>

using namespace std;

/* Space: O(n), Time:O(1) */
uint16_t product1(uint8_t a, uint8_t b)
{
    uint16_t product=0;
    for(int k=0;k<b;k++)
    {
        product+=a;
    }
    return product;
}

/* Space: O(1), Time:O(1)*/
uint16_t product2(uint8_t a, uint8_t b)
{
    uint16_t product=0;
    int k=0;
    for(int k=0;k<8;k++)
    {
        if(b&(0x1<<k))
            product+=(a<<k);
    }
    return product;
}

/* Space: O(1), Time:O(1)*/
uint16_t product3(uint8_t a, uint8_t b)
{
    uint16_t product=0;
    int8_t smaller_input, larger_input;
    smaller_input = (a>=b)? b: a;
    larger_input = (a>=b) ? a: b;
    while(smaller_input>0)
    {
        if(smaller_input&0x1)
        {
            product+=(larger_input<<1);
        }
        larger_input<<=1;
        smaller_input>>=1;
    } 
    return product;
}

int main(void)
{
    uint8_t a,b;
    a=12,b=13;
    //to print uint8_t, convert to int
    cout << "a: " << int(a) << "b: " << int(b) << ", product: " << product1(a,b) << endl;
    cout << "a: " << int(a) << "b: " << int(b) << ", product: " << product2(a,b) << endl;
    cout << "a: " << int(a) << "b: " << int(b) << ", product: " << product3(a,b) << endl;
    return 0;
}