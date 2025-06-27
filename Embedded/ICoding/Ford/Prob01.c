/* Ford Embedded C Software Engineer Interview */
#include <stdio.h>
#include <stdint.h>

/* You are free to use these macros and assume they are correct */
#define MAX(a,b)          ((a) > (b) ? (a) : (b)) /* returns the greater of a or b */
#define MIN(a,b)          ((a) < (b) ? (a) : (b)) /* returns the lesser of a or b */
#define CLIP(a,b,c)       ((a) > (b) ? (a) : ((b) > (c) ? (c) : (b))) /* input b is clipped to a on the lower end and c at the upper end */
#define INT_MIN           (-2147483648)
#define INT_MAX           (2147483647)
#define UINT_MAX          (4294967295U)
#define EPSILON           (0.001F)
/* end macros */

#define MOTOR_TEMPERATURE_NORMAL (0U)
#define MOTOR_TEMPERATURE_HOT    (1U)

const float motor_temperature_threshold_hot = 110.0f;
const float motor_torque_max_norm = 300.0f;
const float motor_torque_max_hot  = 200.0f;

unsigned int motor_temperature_state = 0U;

int motor_temperature_display = 0;

float motor_torque_max     = 0.0f;
float motor_torque_request = 0.0f;

void  motor_executive (void);
void determine_motor_torque_request (void);
void  determine_temperature_state (unsigned int *state, float temperature, float hot_thresh);
float  get_motor_torque_max (void);

float get_motor_temperature    (void);
float get_motor_power_request  (void);
float get_motor_speed_positive (void);

float motor_temperature=0.0f;
float motor_power_request=0.0f;
float motor_speed_positive = 0.0f;  

void setConditions(float motor_temp,float motor_power,float motor_speed);

int main ()
{
    //Set initial conditions for normal state
    setConditions(100.0f,100.0f,100.0f);
    motor_executive();
    //if(motor_temperature_state==MOTOR_TEMPERATURE_NORMAL)
    printf("state:%1ud\n",motor_temperature_state);
    //move the state
    setConditions(200.0f,100.0f,100.0f);
    motor_executive();
    printf("state:%1ud\n",motor_temperature_state);
    return 0;
}

void setConditions(float motor_temp,float motor_power,float motor_speed)
{
    motor_temperature = motor_temp;
    motor_power_request = motor_power;
    motor_speed_positive = motor_speed;
}

void motor_executive (void)
{
    //Get temperature
    float mot_temperature = get_motor_temperature();
    
    motor_temperature_display = mot_temperature;    //not used
    
    //determine state based on threshhold and current state
    determine_temperature_state(&motor_temperature_state,
                                mot_temperature,
                                motor_temperature_threshold_hot);

    //now determine torque limits
    motor_torque_max = get_motor_torque_max();

    //setting the torque request
    determine_motor_torque_request();
}

void determine_temperature_state (unsigned int *state, float temperature, float hot_thresh)
{
    switch (*state)
    {
        case MOTOR_TEMPERATURE_NORMAL:
        {
            if (temperature >= hot_thresh)
            {
                *state = MOTOR_TEMPERATURE_HOT;
            }
        }
        break;

        case MOTOR_TEMPERATURE_HOT:
        {
            if (temperature < hot_thresh)
            {
                *state = MOTOR_TEMPERATURE_NORMAL;
            }
        }
        break;
    }
}

float get_motor_torque_max (void)
{
    float max_torque;
    
    if (motor_temperature_state == MOTOR_TEMPERATURE_HOT)   //HOT STATE
    {
        max_torque = motor_torque_max_hot;
    }
    else
    {
        max_torque = motor_torque_max_norm;
    }

    return max_torque;
}

void determine_motor_torque_request (void)
{
    float mot_pwr_req, mot_spd_pos;

    
    mot_pwr_req  = get_motor_power_request();
    mot_spd_pos  = get_motor_speed_positive();

    if(mot_spd_pos!=0.0f)
        motor_torque_request = mot_pwr_req / mot_spd_pos;
    else
        motor_torque_request = 0.0f;

    motor_torque_request = MAX(motor_torque_request, motor_torque_max);
}


/* You may assume these helper functions contains unit-tested code that outputs a value as indicated */
float get_motor_temperature (void)
{
    /* This function outputs  the motor temperature as a float in the range of -100000.0 to 100000.0 */
    /* ... */
    //motor_temperature=100.0f;
    return motor_temperature;
}

float get_motor_power_request (void)
{
    /* This function outputs  the motor power request as a float in the range of -100000.0 to 100000.0 */
    
    /* ... */
    //motor_power_request = 100.0f;
    return motor_power_request;
}

float get_motor_speed_positive (void)
{
    /* This function outputs the motor speed as a float in the range of 0.0 to 100000.0 */
    //float motor_speed_positive;
    /* ... */
    //motor_speed_positive = 1000.0f;
    return motor_speed_positive;
}