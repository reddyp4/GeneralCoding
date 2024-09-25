The following is a sample ISR implementation (SPI_isr). It is assumed that a maximum of 8 devices may be tied to a single ISR. The Interrupt Source Register is used to find out which devices caused the interrupt.



Each device has a status register that contains the header information of the packet received from the device interface. Each Device also has a HW FIFO where the payload data is stored. The ISR is expected to copy the header into a ring buffer shared with the main thread and signal the arrival of a packet, so that the main thread can perform  further processing.



Identify all the potential issues in this code.



1  #include    <stdtype.h>

2  #include    <os.h>

3  #include    <devices.h>

4  #include    <interrupts.h>

 

6  #define OK  0

7  #define ERROR   1

 

9   #define NUM_SLAVES  8

10 #define COUNTMASK   0xFFFF0000

 

11 // Define the Memory Map Address of the slave devices registers and FIFOs

12 const   uint8 const * InterruptSourceReg;

13 const   uint8 const * DeviceStatuReg[NUM_SLAVES] = {{0xE0040000, 0xE0040100, 0xE0040200, 0xE0040300, 0xE0040400, 0xE0040500, 0xE0040600, 0xE0040700 };

14 const   uint8 COUNTMASK  *DevFIFO_StartAddr[NUM_SLAVES]  = {0xE004004, 0xE0040104, 0xE0040204, 0xE0040304, 0xE0040404, 0xE0040504, 0xE0040604, 0xE0040704 };      

 

16 // Structure for packet header

17 typedef struct  header {

18    uint8   ProtocolId;

19    uint8   SrcAddress;

20    uint8   PktType;

21    uint8   PktSeqNum;

22    uint8   PktDataLen;

23    uint8   PiggyBackAck;

24    uint8   chksum;

25 }   header_t;

 

26 header_t pkt_hdr_queue[NUM_PKTS];   // The ring buffer for incoming pkt headers

27 uint8   numPendingPkts = 0;         // Keeps track of pending packets to be consumed

 

28 // Helper functions for queueing and de-queueing pkt headers from a ringbuf

29 void    enqueue_hdr(header_t    *hdr);

30 header_t *hdr = dequeue_hdr();

 

32 // Main ISR for the device

33 int retval SPI_isr(int slaveID) {

34    uint8   rxHeaderBuf[NUM_SLAVES][sizeof(header_t)];

35    uint8   source;

36    uint8   mask = 0x1;

37   // Find out the interrupt source

38   for (i = 0; i < NUM_SLAVE; i++) {

39        if ((*InterruptSourceReg) & (mask)) {

40            source = i+1;

41            break;

42        }

43        mask = mask < 1;

44    }

45    if (i >= NUM_SLAVE) // No slave has registered an interrupt; Ignore spurious int

46        return -1;

 

48    // We know the source; let us extract the size of pkt

49    dataCOunt = DeviceStatusReg[source] & (COUNT_MASK);

50    if (dataCount < sizeof(header_t))   {   // Incomplete pkt

51        return ERROR;

52    }   

 

54    // Redaout the header from FIFO and enqueue it

 

56    for (int i = 0; i < sizeof(header_t); i++) {

57        memcpy((void *)rxHeaderBuf[source], const void * DevFIFO_StartAddr[source], sizeof(header_t));

58    }

59    // This is a shared global; must acquire a lock

60    OSgetLock(lock_t    m1);

61    numPendingPkts++;

62    OsFreeLock(m1);

63    // Send Signal event to Thread with pkt info for copying the payload

64    retval = OSPostSignal(mainTask, ev_pkt_arrival);

65    return  retval;

66 }   // End ISR

