/*
Consider the simple bootloader code described below. It starts with switching from privileged mode to user mode before jumping to the bootloader_function. The bootloader_function sets up the initialized and uninitialized static/global data variables before calling main() which is the application entry point.



Is this a sufficient condition for a simple Application code to run? Discuss the various shortcomings in it for a simple application to correctly execute. What other essential initializations need to be performed in the bootloader to address these shortcomings.




*/

/*
.set arm_mode_mask, 0b00011111

.set arm_mode_user, 0b00010000

.set arm_bit_irq,      0b10000000

.set arm_bit_firq,     0b01000000


What is happening here?
Define the labels for firq, irq


Declaring the routines in .text section 

session .text

    global routines

    global _main

    global routine_start

routines is first instruction, 
calls routine_start
routine_start: clears r0, sets the user mode, calls bootloader function

nop are interrupt vector table
only defined reset vector
Nothing to handle interrupts, hardware fault, NMI handler

routines: # 0x00000000

    0b00: b routine_start

    0b04: nop

    0b08: nop

    0b0C: nop

    0b10: nop

    0b14: nop

    0b18: nop

    0b1C: nop



routine_start:

    mrs r0, cpsr

    bic r0, r0, #arm_mode_mask

    orr r0, r0, #arm_mode_user

    msr cpsr, r0

    b bootloader_function

    wfi

    .end
*/

#include <stdint.h>

/* Copying image data to bootloader location */
void bootloader_function(void)
{
    uint32_t *i_etext = &_etext;
    for (uint32_t *i_sdata = &_sdata; i_sdata < &_edata; i_sdata++)
    {
        *i_sdata = *i_etext;
        i_etext++;
    }

    for (uint32_t *i_bss = &_sbss; i_bss < &_ebss; i_bss++)
    {
        *i_sbss = 0;
    }
    /* missing the stack setup */
    main();
    /**/
}


static int othr_number;

static int luck_number = 33;

/* This code will not run
1) no stack
2) might fail, since no interrupt handlers are setup

*/
int main(int argc, char* argv[])
{
    othr_number = luck_number;
    while (1)
    {
        othr_number++;
    }
    return 0;
}

/* BL has to do: 
1) ROM Boot:
   Core initialization - missing in code
   Configure the interface to load BL image - code copied from iedata to isdata, and initialized memory in bss to zero is good 
2) Stage-1: Initial Program Loader
    Configure DDR SDRAM AND interface for SPL - This is missing in code
3) Stage-2: Secondary Program Loader
    Configurability and management
    Initialize NW, USB interface, shell

What is missing:
1) Memory inspection
2) global routines doesnt link to any location - should we initialize this function?
3) 

*/