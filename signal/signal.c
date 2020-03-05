#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void print(int a)
{
  printf("__________\n");

  return ;
}
int main()
{
  while(1)
{
  signal(SIGQUIT,print);

} 


  return 0;
}
