/*
Thread creation and termination
*/
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void* message_print_function (void *ptr){
    char* message;
    message = (char *) ptr;
    printf("%s\n",message);
    print(ptr);
}

int main()
{
    pthread_t thread1,thread2;
    printf("Entering main: \n");
    return 1;
}