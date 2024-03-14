//#############################################################################
// $TI Release: F2837xS Support Library v3.10.00.00 $
// $Release Date: Tue May 26 17:16:51 IST 2020 $
// $Copyright:
// Copyright (C) 2014-2020 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"


//*****************************************************************************
//
// Defines related to clock configuration
//
//*****************************************************************************
//
// LaunchPad Configuration
//
//
#ifdef SYSCLK_200MHZ    // Check the compiler pre-defined symbol

#define DEVICE_SYSCLK_FREQ      (200000000U)

#ifdef OSC_20MHZ
#define SYSDIV_VALUE            (2)
#else // OSC 10MHz
#define SYSDIV_VALUE            (2)
#endif // ifdef OSC_20MHZ

#else   // SYSCLK 100MHz

#define DEVICE_SYSCLK_FREQ      (100000000U)

#ifdef OSC_20MHZ
#define SYSDIV_VALUE            (8)
#else // OSC 10MHz
#define SYSDIV_VALUE            (4)
#endif // ifdef OSC_20MHZ

#endif // #ifdef SYSCLK_200MHZ //


// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = (XTAL_OSC) * (IMULT + FMULT) / PLLCLK_BY_2
#define DEVICE_SETCLOCK_CFG     (SYSCTL_OSCSRC_XTAL             | \
                                 SYSCTL_IMULT(20)               | \
                                 SYSCTL_FMULT_NONE              | \
                                 SYSCTL_SYSDIV(SYSDIV_VALUE)    | \
                                 SYSCTL_PLL_ENABLE)

//
// 100MHz LSPCLK frequency based on the above DEVICE_SYSCLK_FREQ and a custom
// low speed peripheral clock divider of 2. Update the code below if a
// different LSPCLK divider is used!
//
#define DEVICE_LSPCLK_FREQ          (DEVICE_SYSCLK_FREQ / 2)

//*****************************************************************************
//
// Macro to call SysCtl_delay() to achieve a delay in microseconds. The macro
// will convert the desired delay in microseconds to the count value expected
// by the function. \b x is the number of microseconds to delay.
//
//*****************************************************************************
#define DEVICE_DELAY_US(x) SysCtl_delay(((((long double)(x)) / (1000000.0L /  \
                              (long double)DEVICE_SYSCLK_FREQ)) - 9.0L) / 5.0L)

//*****************************************************************************
//
// Defines, Globals, and Header Includes related to Flash Support
//
//*****************************************************************************
#ifdef _FLASH
#include <stddef.h>

extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsRunEnd;
extern uint16_t RamfuncsRunSize;

#define DEVICE_FLASH_WAITSTATES 3

#endif

extern uint32_t Example_PassCount;
extern uint32_t Example_Fail;

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
extern void Device_init(void);
extern void Device_enableAllPeripherals(void);
extern void Device_initGPIO(void);
extern void Device_enableUnbondedGPIOPullupsFor176Pin(void);
extern void Device_enableUnbondedGPIOPullupsFor100Pin(void);
extern void Device_enableUnbondedGPIOPullups(void);
extern void Device_configureTMXAnalogTrim(void);
extern void __error__(char *filename, uint32_t line);
extern void Example_setResultPass(void);
extern void Example_setResultFail(void);
extern void Example_done(void);

//
// End of file
//
