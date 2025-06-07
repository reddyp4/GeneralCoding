Question 1:
The facilities team is in need of a temperature data logger to determine if we need to upgrade the air conditioning at our new facility. Using your favorite embedded platform (and C++), set up a sustainable project capable of being maintained by someone else and write the code necessary to measure temperature using TI’s TMP100 I2C temperature sensor and log the temperature every 10 minutes to a Microchip 24FC256 eeprom. State any assumptions you need to make, you can use whatever libraries are available for your platform of choice from the platform vendor. 
(for example I2C libraries are ok, drivers for the TMP100 are not)

As part of the review will be looking at:
• re-usability of the code you write
• comments around what your code is doing
• comments about assumptions and known issues

Design:
logger.h:
    Ring Buffer
logger.c
main.c
    Setup I2C from micro for EEPROM (micro doesnt matter)
    Setup 10min task from tick (10min=10*60*1000=600,000=Period)
    task_handler: write value(i2c_handler, location, value)
    api flow:
        main:
            Init I2C
            Init TMP100 settings for I2C
            Init EEPROM 
            Init 10min_task_handler
        logger:
            writes
        other api:
            write_temp(i2c_handler, location, time, value): Write to EEPROM
            read_temp_hist(i2c_handler, start, size): Read from EEPROM
            read_temp(): Read from TI's TMP100 I2C sensor
        