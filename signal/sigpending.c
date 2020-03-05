#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void printped(sigset_t set)
{
  int i=1,j;
  for(i=1;i<32;i++)
   { 
     if(sigismember(&set,i)==1)
     putchar('1');
  
   else 
    putchar('0');
 }
printf("\n");

}
int main()
{

  sigset_t set,ped;
  int i;
  
  sigemptyset(&set);//清空
  sigaddset(&set, SIGINT);
  sigaddset(&set, SIGQUIT);
  sigaddset(&set, SIGKILL);
  sigaddset(&set, SIGSEGV);//加入信号集
  sigfillset(&set);//置1....这样才能所有的都加入
  i = sigprocmask(SIG_BLOCK,&set,NULL);
  if(i==-1)
  perror("sigprocmask error!\n");
  
  while(1)
   {
     sigpending(&set);//读取未决信号集
     printped(set); 
     sleep(1);
   }
  
  

  return 0;
}
