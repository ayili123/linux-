#include <stdio.h>	
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	int i,p;
       abort();
       raise(SIGSEGV);
       for(i=0;i<5;i++)
      {
       pid = fork();
	if(pid == -1)
        perror("fork() error!\n");
        if(pid == 0)
	{
	break;
	}
	if(i==2)
	p = pid;
      }
	if(i<5)
	{
	while(1)
	{
	printf("I am %d child,%d\n",i,getpid());
	sleep(1);
	}
 	}else{
          sleep(1);
	kill(p,SIGKILL);
	while(1);
	}
	return 0;
}
