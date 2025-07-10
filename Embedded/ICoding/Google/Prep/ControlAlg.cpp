/*
/* The details of the control algorithm are highly confidential and so not exposed. 
The following function is available to call, but
the control engineers have not optimized the control loop and so advise that it takes 
significant processor time to run. The return
value of the control loop is the control output value.
This function should be called every 1 second.
*/
uint16_t RunControlLoop(uint8_t upper_pressure, uint8_t lower_pressure);
void callback(){
    cond = 1;
    pthread_cond_signal(&condvar);
 }
 
 void consume (voidarg){
   pthread_mutex_lock(&m);
   while(cond) 
     pthread_cond_wait(&condvar, &m);
   val = RunControlLoop( upper_pressure, lower_pressure);
   pythread_mutex_unlock(&m);
   cond = 0;
 }