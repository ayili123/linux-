#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void myalarm(int signo)
{
   

}

//方法一
int mysleep(int seconds)
{
   int j,ret; 
   signal(SIGALRM,myalarm); //注册闹钟函数该做的事，捕获   sigaction()这样更精确
   alarm(seconds);
 
    ret = pause();

   j = alarm(0);
   
   return j;//返回s数
}


//方法二
int mysleep2(int seconds)
{
  struct sigaction new,old;
  int ret;
  new.sa_handler = myalarm;
  sigemptyset(&new.sa_mask);
  new.sa_flags = 0;
  sigaction(SIGALRM,&new,&old);//信号注册
  alarm(seconds);
  pause();
  sigaction(SIGALRM,&old,NULL);//恢复默认状态
  ret = alarm(0);
  return ret;


}

int main()
{
  
  while(1)
  {

  printf("00000000\n");
  mysleep2(1);
  }
  

  return 0;
}
