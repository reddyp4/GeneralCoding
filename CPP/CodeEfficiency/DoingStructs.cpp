#include <cstdint>
#include <iostream>

using namespace std;

/* Size is biggest element, that is int 4 byte
rest of datatypes will have padding
*/
struct Y {
    short a;    // 2 bytes
    int b;  // 4 bytes
    char c; // 1 byte

    //int b;
    //short a;
    //char c;

    //long long a : 4;
    //short b : 8;
};

/*
Does short stradle only 2 byte boundary? Not always - depends on architecture
Remove ambiguity by uint32_t - that way a 32 bit integer is allowed to stradle the boundaries
*/
struct YY {
    int a:4;    // 4 bits = 1/2 byte
    short b:8;  // 8 bits = 1 byte
    char c:4;   // 4 bites = 1/2 byte
};

/* Flexible array members*/
// By default, 8 bytes, 8-byte boundary, 
// last datatype is ignored, but is used for boundary itself
struct Z {
    uint32_t a;
    uint16_t b;
    uint64_t c[];
};

union property {
    int a;
    float b;
    char c[20];
};

int main(void)
{
    Y y1;
    cout << "Sizeof struct" << sizeof(y1) << endl;

    YY y2;
    cout << "Sizeof struct" << sizeof(y2) << endl;

    Z z1;
    cout << "Sizeof struct" << sizeof(z1) << endl;

    property P1;
    cout << "Sizeof struct" << sizeof(P1) << endl;

    return 0;
}