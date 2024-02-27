/*
Implement the function detect_bit_flip(). This function will be called multiple times and
the pattern passes in could vary during each call.
Return TRUE when detect there is at least 1 bit flips from 0 to 1 from the previous pattern.
Otherwise return FALSE
*/

#include <stddef.h>
#include <stdio.h>
#include <printf.h>
#include <stdbool.h>
#include <stdint.h>

bool detect_bit_flip(uint8_t pattern)
{
    // Implement the function here:   
    // store the previous pattern
    // detect atleast one bit flip from 0 to 1 (and not 1 to 0)
    // 1) initialization part
    // 2) prev0, new1 => return true toggling captured ^, and prev bit was 0, and with 0xFF=0
    // 10 -> 11 -> toggle = 01 -> 10&(~01) = true
    // 11 -> 10, toggle 01, 01&(00) = False
    static int initVar = 0;
    static uint8_t prevVal = 0x0;
    if(initVar==0)
    {
      prevVal=pattern;
      initVar=1;
      return false;
    }
    else {
      uint8_t toggled = prevVal^pattern;
      if(toggled)
      {
        //printf("%d\n",(toggled & (~prevVal)));
        if(toggled & (~prevVal))
        {
          //printf("Came here!");
          prevVal = pattern;
          return true;
        }
      }
    }
    prevVal = pattern;
    return false;
}


int main() {
  uint8_t pattern = 0b00000000;
  
  // test case 1: initial call shall return 0;  
  bool functionReturn = detect_bit_flip(pattern);
  printf("Expected result is false, your result is %s\n", functionReturn ? "true" : "false"); 

  // test case 2: there is a bit flip:
  pattern = 0b00000010;
  functionReturn = detect_bit_flip(pattern);
  printf("Expected result is true, your result is %s\n", functionReturn ? "true" : "false");  

  // test case 2: another bit is flipped to 1.
  pattern = 0b00100010;
  functionReturn = detect_bit_flip(pattern);
  printf("Expected result is true, your result is %s\n", functionReturn ? "true" : "false");
    
  // test case 3: one of the flipped bit get reset to 0.
  pattern = 0b00100000;
  functionReturn = detect_bit_flip(pattern);
  printf("Expected result is false, your result is %s\n", functionReturn ? "true" : "false");
    
  // test case 4: one of the flipped bit get reset to 0 and some bits are set to 1.
  pattern = 0b11000111;
  functionReturn = detect_bit_flip(pattern);
  printf("Expected result is true, your result is %s\n", functionReturn ? "true" : "false"); 

  return 0;
}