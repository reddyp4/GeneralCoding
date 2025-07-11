/*
Steering Problem
  
A controls engineer has collected test data for a black box steering system to
determine the amount of voltage that needs to be applied to hold the vehicle at a
given steering angle. The data below shows that the voltage (V)
required is a function of the steering angle (a).
  
Test Data:
a = -22,  -11, 0, 10,  20 degrees
V = -1.5, -1,  0, 1.2, 1.8 volts
  
The controls engineer would like to use this data as a feed forward term for the
steering controller. Your job is to write a function to determine
the best estimate for voltage (V) given a steering angle (a). aka. V = f(a).
 
Example output:
For a = 10; V = 1.2
For a = 5; V = 0.6
For a = 15; V = 1.5
This problem uses a unit test framework called Catch. Use the example tests at the
bottom of the file to test lookup1D, and feel free to add your own as well.
*/

// Unit testing framework
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Standard includes
#include <iostream>
#include <stdint.h>

float lookup1D(const float a,const float *a_data,const float *v_data, int size) {
  // TODO

  
}

TEST_CASE( "Steering Problem Test" ) {
  const float a_data[]  =  {-22,  -11, 0, 10,  20}; // x-axis data
  const float v_data[] =   {-1.5, -1,  0, 1.2, 1.8}; // y-axis data
  const int size = 5;
  float a, v_expected, v_test;

  SECTION( "Example 1" ) {
    // input angle
    a = 10.0;
    // expected output voltage
    v_expected = 1.2;
    // call function under test
    v_test = lookup1D(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  SECTION( "Example 2" ) {
    // input angle
    a = 15.0;
    // expected output voltage
    v_expected = 1.5;
    // call function under test
    v_test = lookup1D(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  // TODO: Add any new test sections here
}