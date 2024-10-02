    // 4) Memory dump (10 points)
    //    The following memory dump was taken while debugging an issue.
    //
    // Memory Dump:
    // Address:  Byte:
    // 0x1000    0xA0
    // 0x1001    0x0A
    // 0x1002    0xBA
    // 0x1003    0x48
    // 0x1004    0x2C
    // 0x1005    0xB7
    // 0x1006    0x3B
    // 0x1007    0x82
    // 0x1008    0x9C
    // 0x1009    0xE5
    // 0x100A    0x17
    // 0x100B    0x40
    // 0x100C    0xEF
    // 0x100D    0x47
    // 0x100E    0x0F
    // 0x100F    0x98
    // 0x1010    0x6F
    // 0x1011    0xD5
    // 0x1012    0x70
    // 0x1013    0x9E
    // 0x1014    0x94
    // 0x1015    0x99
    // 0x1016    0x4A
    // 0x1017    0xBA
    // 0x1018    0xCA
    // 0x1019    0xB2
    // 0x101A    0x32
    // 0x101B    0xE6
    // 0x101C    0x8E
    // 0x101D    0xB9
    // 0x101E    0xC5
    // 0x101F    0x2E
    // 0x1020    0xC3
    //
    // System is 32-bit, little-endian.
    // A variable called myPacket is of type packet_S (typedef below).
    // (Default compiler options; unpacked, naturally aligned.) -->This means no padding(-Colin)
    // The address of myPacket is 0x1010.
    //
    typedef struct
    {
        uint8_t count;
        uint16_t data[2]; -->Should be no padding in between elements, thus 2bytes*2(-Colin)
        uint32_t timestamp;
    } packet_S;
    
    // a) What are the values of each member of myPacket?
    count = 0x6F
    data = 0x9994, 0xBA4A
    timestamp = 0xE632B2CA

    // b) If the system was big-endian, what would the values of each member of
    //    myPacket be?
    count = 0x6F
    data = 0x9499, 0x4ABA
    timestamp = 0xCAB232E6
