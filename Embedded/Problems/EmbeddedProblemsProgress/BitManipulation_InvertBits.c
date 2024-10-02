// 2) Bit Manipulation (5 points)
// Write a function that inverts (0 -> 1 or 1 -> 0) the most significant and
// least significant bits of the data value pointed to by b.

void flip_bits(uint8_t *b)
{
    *b=(*b)^0x81;
}