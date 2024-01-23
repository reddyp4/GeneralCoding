/*
Thread creation and termination
*/
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void* message_print_function (void *ptr){
    char* message;
    message = (char *) ptr;
    printf("Message: %s, ptr value:%d\n",message,ptr);
}

int main()
{
    pthread_t thread1,thread2;
    int iret1, iret2;
    char *message1 = "Thread1";
    char *message2 = "Thread2";
    printf("Entering main: \n");

    /* Create independent threads each of which execute a function */
    iret1 = pthread_create(&thread1,NULL,message_print_function,(void*) message1);
    iret2 = pthread_create(&thread2,NULL,message_print_function,(void*) message2);

    /* Wait till threads are complete before main continues */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread1 returns: %d\n", iret1);
    printf("Thread1 returns: %d\n", iret2);
    return 1;
}
