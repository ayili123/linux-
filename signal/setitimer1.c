#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>



/* struct itimerval  {
        struct timeval{
            it_value.tv_sec;
            it_value.tv_usec;
        } it_interval;

        struct timeval {
            it_value.tv_sec;
            it_value.tv_usec;
        } it_value;

    } it, oldit;

*/
int main()
{
   struct itimerval new;
   struct itimerval old;

   int i,j;
   new.it_value.tv_sec = 1;//最开始闹钟时间
   new.it_value.tv_usec = 0;
   new.it_interval.tv_sec = 0;//中断后两个闹钟时间间隔
   new.it_interval.tv_usec = 0;
   i = setitimer(ITIMER_REAL,&new,&old);
   if(i == -1)
   {
   perror("setitimer() error\n");
   exit(1);
   }
   while(1)
  {
   printf("%d\n",j++);
  }
     return 0;
}
