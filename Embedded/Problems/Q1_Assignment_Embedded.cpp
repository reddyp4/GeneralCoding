/*
A device indicates the result of an operation in 32 bits at a particular address. Based on the result, the format of these 32 bits varies. For one result, the format is 1 byte:1 byte:1 byte:1 byte and for another result, the format is 1 byte:4 bits:1 byte:4 bits:1 byte. How do you represent this information in one C variable pointing to that address? Consider the following:



Unions and bitfields
How to determine which format - typically indicated elsewhere.
Typical use cases
*/

enum
{
    one=0u,
    two,
    optionsn
} format_type;

union my_Union{
    char a[4];
    struct {
        uint32_t a:8;
        uint32_t b:4;
        uint32_t c:8;
        uint32_t d:4;
        uint32_t e;
    } my_str;
};

