#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>



/* 
struct itimerval  {
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
/*****************开始5s后打印，以后每隔3s打印，这里就是it_interval来设置******************/

void myfunc(int signo)
{
	printf("hello world\n");

}

int main()
{
   struct itimerval new;
   struct itimerval old;

   int i;
   int j = 0;
   signal(SIGALRM,myfunc);//注册信号捕捉函数，成功执行回调函数
   new.it_value.tv_sec = 5;//最开始闹钟时间
   new.it_value.tv_usec = 0;
   new.it_interval.tv_sec = 3;//中断后两个闹钟时间间隔
   new.it_interval.tv_usec = 0;
   if(setitimer(ITIMER_REAL,&new,&old) == -1)
   {
   perror("setitimer() error\n");
   return -1;
   }
   while(1);

     return 0;
}
