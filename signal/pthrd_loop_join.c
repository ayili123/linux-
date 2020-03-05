#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int var =100;
void* fun(void* arg)
{
   int i = (int)arg;
   sleep(i);
   
   if(i == 2)
   {
    var = 333;
    printf("var = %d\n", var);
    pthread_exit((void *)var);
   }

   else
  {
     printf("I'm %dth pthread, pthread_id = %lu\n var = %d\n", i+1, pthread_self(), var);
     pthread_exit((void *)var);
  }

  return;


}

int main()
{

   pthread_t  tid[5];
   int i;
   int * retval[5];

   for(i = 0;i<5;i++)
    {
     pthread_create(&tid[i],NULL,fun,(void*)i);
    }
   
    for(i = 0;i<5;i++)
    {  
    pthread_join(tid[i],(void**)&retval);
    printf("-------%d 's ret = %d\n", i, (int)retval[i]);
    }
   sleep(i);
   return 0;
}
