/* Embedded Simulator 
    Src: https://www.embeddedrelated.com/showarticle/1695.php#non-blocking
*/

HAL_UART_Receive_IT(&huart2, cmd, (size_t)1);
while (1)
{
    if( cmd_received )
    {
        // Process the command by comparing it to "on" and "off".
        //    
        if( strcmp((char*)cmd, "on") == 0 ) led_is_blinking = true;
        else if( strcmp((char*)cmd, "off") == 0 )
        {
            led_is_blinking = false;
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
        }
        else
        {
            uint8_t error_msg[] = "Unknown command\n\r";
            HAL_UART_Transmit(&huart2, error_msg, strlen((char*)error_msg), HAL_MAX_DELAY);
        }
        // Reset variables to receive another command.
        //
        memset(cmd, 0, strlen((char*)cmd));
        p_current_char = cmd;
        cmd_received = false;
        HAL_UART_Receive_IT(&huart2, cmd, (size_t)1);
    }
    // Non-blocking Blinky. If it's been <interval_ms> since
    // the last time we toggled the LED (<prev_millis>), then
    // toggle the LED.
    //
    if( led_is_blinking )
    {
        if( HAL_GetTick() - prev_millis > interval_ms )
        {
            prev_millis = HAL_GetTick();
            if( HAL_GPIO_ReadPin(LED_GPIO_Port, LED_Pin) == GPIO_PIN_RESET )
            {
                HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
            }
            else
            {
                HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
            }
        }
    }
}

GOES TO
initHardware(argc, argv);
while(1)
{
    if( cmd_received )
    {
        // Process the command by comparing it to "on" and "off".
        //    
        if( strcmp((char*)cmd, "on") == 0 ) led_is_blinking = true;
        else if( strcmp((char*)cmd, "off") == 0 )
        {
            led_is_blinking = false;
            turnOffLED();
        }
        else
        {
            uint8_t error_msg[] = "Unknown command\n\r";
            send(error_msg);
        }
        // Reset variables to receive another command.
        //
        resetUART();
    }
    // Non-blocking Blinky. If it's been <interval_ms> since
    // the last time we toggled the LED (<prev_millis>), then
    // toggle the LED.
    //
    if( led_is_blinking )
    {
        if( getMillis() - prev_millis > interval_ms )
        {
            prev_millis = getMillis();
            if( ledIsOff() )
            {
                turnOnLED();
            }
            else
            {
                turnOffLED();
            }
        }
    }
}
