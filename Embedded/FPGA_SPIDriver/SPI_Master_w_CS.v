///////////////////////////////////////////////////////////////////////////////
// SPI (Serial Peripheral Interface) Master 
// With single chip-select (AKA Slave Select) capability
//
// Supports arbitrary length byte transfer.
// 
// Instantiates a SPI master and adds single CLKS_PER_HALF_BIT
// If multiple CS signals are needed, will need to use different 
// module, OR multiplex the CS from this at a higher level. 
//
// i_Clk must be at least 2x faster than i_SPI_Clk
// 
// SPI_MODE, can be 0, 1, 2, or 3. See above. 
// Can be figured in one of 4 modes: 
// Mode | Clock Polarity (CPOL/CKP) | Clock Phase (CPHA)
// 0    |             0             |         0
// 1    |             0             |         1
// 2    |             1             |         0
// 3    |             1             |         1
// 
// CLKS_PER_HALF_BIT - Set frequency of o_SPI_Clk. o_SPI_Clk is
// derived from i_Clk. Set to integer number of clocks for each 
// half-bit of SPI data. E.g. 100 MHz i_Clk, CLKS_PER_HALF_BIT = 2
// would create o_SPI_CLK of 25 MHz. Must be >= 2. 
//
// MAX_BYTES_PER_CS - Set ti the maximum number of bytes that will be sent
// during a single CS-low pulse. 
// 
// CS_INACTIVE_CLKS - Sets the amount of time in clock cycles to 
// hold the state of the Chip-select high (inactive) before next
// command is allowed on the line. Useful if chip requires some 
// time when CS is high between transfer. 
/////////////////////////////////////////////////////////////////////////////////

module SPI_Master_with_single_CS
#(  parameter SPI_MODE = 0,
    parameter CLKS_PER_HALF_BIT = 2,
    parameter MAX_BYTES_PER_CS = 2,
    parameter CS_INACTIVE_CLKS = 1)
  (
        //Control/Data Signals 
        input i_Rst_L,  //FPGA Reset
        input i_Clk,    //FPGA Clock

        // TX (MOSI) Signals
        input [$clog2(MAX_BYTES_PER_CS+1)-1:0] i_TX_Count,  // # bytes per CS low
        input [7:0] i_TX_Byte,          // Byte to transmit on MOSI
        input       i_TX_DV,            // Data valid pulse with i_TX_Byte
        output reg  o_TX_Ready,         // Transmit Ready for next byte 

        // RX (MISO) Signals 
        output reg [$clog2(MAX_BYTES_PER_CS+1)-1:0] i_RX_Count,  // # bytes per CS low
        output reg  o_RX_DV,            // Data valid pulse (1 clock cycle)
        output reg [7:0]    o_RX_Byte,  // Byte received on MISO 

        // SPI Interface 
        output o_SPI_Clk,
        input  i_SPI_MISO,
        output o_SPI_MOSI
        output o_SPI_CS_n
  )

  localparam IDLE         = 2'b00;
  localparam TRANSFER     = 2'b01;
  localparam CS_INACTIVE  = 2'b10;

  reg [1:0] r_SM_CS;
  reg r_CS_n;
  reg [$clog2(CS_INACTIVE_CLKS+1)-1:0] r_CS_Inactive_Count;
  reg [$clog2(MAX_BYTES_PER_CS+1)-1:0] r_TX_Bit_Count;
  wire w_Master_Ready;

  // Purpose: Keep track of i_RX_Count
  always @(posedge i_Clk)

  // Purpose: Keep tract of i_RX_Count
  always @(posedge i_Clk)
  begin
    

endmodule