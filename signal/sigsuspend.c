#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void myalarm(int signo)
{
   

}


//时序问题
int mysleep2(int seconds)
{
  struct sigaction new,old;
  sigset_t newmask,oldmask,suspmask;//信号集
  int ret;
  new.sa_handler = myalarm;
  sigemptyset(&new.sa_mask);
  new.sa_flags = 0;
  sigaction(SIGALRM,&new,&old);//信号注册

  //设置阻塞信号集2
  sigemptyset(&newmask);//清空
  sigaddset(&newmask,SIGALRM);//加入
  sigprocmask(SIG_BLOCK,&newmask,&oldmask);//信号屏蔽字 mask 函数调用
 
  
  alarm(seconds);

  suspmask = oldmask;
  sigdelset(&suspmask, SIGALRM);//确保删除SIGALRM


  sigsuspend(&suspmask);

  
    //6.恢复SIGALRM原有的处理动作，呼应前面注册
    sigaction(SIGALRM, &old, NULL);

    //7.解除对SIGALRM的阻塞，呼应前面注释2
    sigprocmask(SIG_SETMASK, &oldmask, NULL);
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
