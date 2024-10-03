    // 5) State Machine (20 points)
    //
    //    Complete the function below to implement the state machine shown in the
    //    diagram below for an electronic gumball vending machine.
    //     * The initial state of the state machine should be IDLE
    //     * The function should output the current state of the state machine
    //     * Unexpected or invalid input should not cause a state transition
    //     * GENERIC_FAULT may be received in any state and should put the machine
    //       into the FAULT state
    
    typedef enum
    {
        IDLE,
        READY,
        VENDING,
        FAULT
    } state_E;
    
    typedef enum
    {
        COIN,
        COIN_RETURN,
        BUTTON,
        VEND_COMPLETE,
        GENERIC_FAULT
    } input_E;


    state_E currState = IDLE;//set default current state to be IDLE
    state_E stateMachine(input_E input)
    {
        state_E retVal = currState;
        switch(input)
        {	
            case GENERIC_FAULT:
                    retVal = FAULT;;
                    currState = retVal;
                    break;
            case COIN:
                if (currState = IDLE) {
                    retVal = READY;
                    currState = retVal;
                }
                break;
            case COIN_RETURN:
                if (currState = READY) {
                    retVal = IDLE;
                    currState = retVal;
                }
            case BUTTON:
                if (currState = READY) {
                    retVal = VENDING;
                    currState = retVal;
                }
                break;
            case VEND_COMPLETE:
                if (currState == VENDING) {
                    retVal = IDLE;
                    currState = retVal;
                }
                break;
            default: 
                break;
        }
        
        return retVal;
    }