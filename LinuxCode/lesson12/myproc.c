#include <stdio.h>
#include <string.h>

int main()
{
  for(int i = 0;i < 140; i++)
  {
    printf("%d: %s\n",i,strerror(i));
  }
  
  //printf("hell uaena\n");
  return 23;
}
