#include <stdio.h>
#include <unistd.h>
int main()
{
  int count =10;
  while(count)
  {
    printf("%2d\r",count);
    fflush(stdout);
    count--;
    sleep(1);
  }
  // printf("hello bit!\n");
  //printf("hello bit!");
  //fflush(stdout);
  //sleep(5);

  return 0;
}
