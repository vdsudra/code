#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// A normal C function that is executed as a thread when its name
// // is specified in pthread_create()
 void *myThreadFun(void *vargp)
 {
    while(i<10)
    {
    sleep(1);
    printf("\n%d",i++);
    }
    return NULL;
  }
              
int main()
{
   pthread_t tid;
   volatile int i;
   printf("Before Thread\n");
   pthread_create(&tid, NULL, myThreadFun, NULL);
   pthread_join(tid, NULL);
   printf("After Thread\n");
   exit(0);
}
