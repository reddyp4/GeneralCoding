/* literals */
#include <iostream>
using namespace std;

int main(void)
{
    int a = 20;
    int b = 0x1A;
    int c = 016;
    int d = 0b11;
    cout << "a: " << a << ", b:" << b << ", c:" << c << ", d:" << d << endl;

    int e = 124;
    unsigned int f = 124U;
    long int g = 124L;
    long long int h = 124LL;
    cout << "e: " << e << ", f:" << f << ", g:" << g << ", h:" << h << endl;

    float i = 10.5f;
    double j = 10.414f;
    float k = 2.1e15;
    double l = 200.1e-80;
    double m = 0x1A.1p2;
    cout << "i: " << i << ", j:" << j << ", k:" << k << ", l:" << l << ", m:" << m << endl;
    return 0;
}