/**
Pressure is available via memory mapped registers. The pressure reading is a 16-bit value with valid 
values in the range of 0 to 10,000.

Lower 8-bits of pressure value is at memory location 0x00001000, Upper 8-bits of pressure value is at 
memory location 0x00001001
Whenever a new pressure reading is available, the following will be called in interrupt context:
*/
  1000   0001
|byte1 | byte2|

volatile uint16_t pressure_value;

// Lower and high pressure byte
#define LPB  0x00001000
#define HPB 0x00001001

volatile uint16_t pressure_value; 

void ReadPressure(){

uint8_t high1 = 0, high2 = 0;
uint8_t low = 0;

do{
  high1 = ((volatile uint8_t) LPB;
  low = ((volatile uint8_t) HPB;
  high2 = ((volatile uint8_t) LPB;
} while( high1 != high2);

  pressure_value = ((uint16_t high1 << 8) | low);
}

/*
ChatGPT answer:   #include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> runControlLoopAsyncFlag(false);

// Function representing the control loop
uint16_t RunControlLoop(uint8_t upper_pressure, uint8_t lower_pressure) {
    // Your control algorithm implementation goes here
    // This is a placeholder, replace it with your actual implementation
    uint16_t control_output = upper_pressure + lower_pressure;
    return control_output;
}

// Function to run the control loop asynchronously
void RunControlLoopAsync() {
    while (true) {
        if (runControlLoopAsyncFlag) {
            // Reset the flag
            runControlLoopAsyncFlag.store(false);

            // Call the control loop function with some dummy parameters
            uint8_t upper_pressure = 80;
            uint8_t lower_pressure = 20;
            uint16_t control_output = RunControlLoop(upper_pressure, lower_pressure);

            // Process the control output or perform other tasks as needed
            std::cout << "Control Output: " << control_output << std::endl;
        }

        // Optional: Add a small delay to avoid continuous checking
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// ISR function
void MyISR() {
    // Set the flag to signal the control loop should run asynchronously
    runControlLoopAsyncFlag.store(true);
}

int main() {
    // Start the control loop in a separate thread
    std::thread controlLoopThread(RunControlLoopAsync);

    // Simulate ISR-triggered events (replace with actual ISR triggers)
    for (int i = 0; i < 10; ++i) {
        // Simulate ISR-triggered event
        MyISR();

        // Simulate some other main thread tasks
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Wait for the control loop thread to finish (not necessary if it's a continuous process)
    controlLoopThread.join();

    return 0;
}
*/
