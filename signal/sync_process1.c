#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
//父子交替数数1,2,3,4,5.。。。
int n = 0, flag = 0;

void child_test(int signo)
{
 
  printf("i am child ,id = %d ,______ %d\n",getpid(),n);
 n+=2;
  flag = 1;
  sleep(1);
}

void parent_test(int signo)
{
 
  printf("i am parent ,id = %d ,______ %d\n",getpid(),n);
  n+=2;
  flag = 1;
  sleep(1);
}

int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid == -1)
   {
    perror("fork()...error\n");
   }

   if(pid==0)
   {
     n = 2;
     signal(SIGUSR1,child_test);
     
     while(1){
     if(flag == 1)
      {
       kill(getppid(),SIGUSR2);//给父进程发
       flag = 0;
      }
     }
   }
   else if(pid>0)
  {
     n = 1;
     sleep(1);//确保子程序也注册好
     signal(SIGUSR2,parent_test);//注册
     parent_test(0);//触发程序启动
     while(1){
     if(flag == 1)
      {
       kill(pid,SIGUSR1);//给子进程发
       flag = 0;
      }
     }
 
  }

    return 0;
}
