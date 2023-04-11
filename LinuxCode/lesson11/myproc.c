#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int g_unval;
int g_val = 100;

int main(int argc,char* argv[],char* env[])
//int main()
{
  const char *s = "hello world";
  printf("代码区code addr:%p\n",main);
  printf("字符常量string rdonly addr:%p\n",s);
  printf("初始化空间init addr:%p\n",&g_val);
  printf("未初始化空间uninit addr:%p\n",&g_unval);
//堆区
  char * heap = (char*)malloc(10);
  char * heap1 = (char*)malloc(10);
  char * heap2 = (char*)malloc(10);
  char * heap3 = (char*)malloc(10);
  char * heap4 = (char*)malloc(10);
  printf("堆heap addr: %p\n",heap);
  printf("heap addr1: %p\n",heap1);
  printf("heap addr2: %p\n",heap2);
  printf("heap addr3: %p\n",heap3);
  printf("heap addr4: %p\n",heap4);

  printf("栈stack addr:%p\n",&s);
  printf("stack addr:%p\n",&heap);
  int a = 10;
  int b = 20;
  printf("stack addr:%p\n",&a);
  printf("stack addr:%p\n",&b);
  for(int i = 0 ;argv[i];i++)
  {
    printf("argv[%d]:%p\n",i,argv[i]);
  }
  for(int i =0 ;env[i];i++)
  {
    printf("环境变量env[%d]：%p\n",i,env[i]);
  }
}


//int g_val = 100;
//
//int main()
//{
//    //数据是各自私有一份(写时拷贝)
//    if(fork() == 0){
//        //child
//        int cnt = 5;
//        while(cnt){
//            printf("I am child, times: %d, g_val = %d, &g_val = %p\n", cnt, g_val, &g_val);
//            cnt--;
//            sleep(1);
//            if(cnt == 3){
//                printf("##################child更改数据#########################\n");
//                g_val = 200;
//                printf("##################child更改数据done#####################\n");
//            }
//        }
//    }
//    else{
//        //parent
//        while(1){
//            printf("I am father, g_val = %d, &g_val = %p\n", g_val, &g_val);
//            sleep(1);
//        }
//    }
//    return 0;
//}
//




//int g_unval;
//int g_val = 100;
//
////int main(int argc,char* argv[],char* env[])
//int main()
//{
//  const char *s = "hello world";
//  printf("code addr:%p\n",main);
//  printf("string rdonly addr:%p\n",s);
//  printf("uninit addr:%p\n",&g_unval);
//  printf("init addr:%p\n",&g_val);
////堆区
//  char * heap = (char*)malloc(10);
//  char * heap1 = (char*)malloc(10);
//  char * heap2 = (char*)malloc(10);
//  char * heap3 = (char*)malloc(10);
//  char * heap4 = (char*)malloc(10);
//  printf("heap addr: %p\n",heap);
//  printf("heap addr1: %p\n",heap1);
//  printf("heap addr2: %p\n",heap2);
//  printf("heap addr3: %p\n",heap3);
//  printf("heap addr4: %p\n",heap4);
//
//  printf("stack addr:%p\n",&s);
//  printf("stack addr:%p\n",&heap);
//  int a = 10;
//  int b = 20;
//  printf("stack addr:%p\n",&a);
//  printf("stack addr:%p\n",&b);
//


 // printf("I am process pid: %d,ppid: %d\n",getpid(),getppid());













//      printf("PATH:%s\n",getenv("PATH"));
//      printf("HOME:%s\n",getenv("HOME"));
//    extern char **environ;
//    for(int i =0;environ[i];i++){
//
//    printf("%d -> %s\n",i,environ[i]);
//    }
//
//  for(int i = 0;env[i];++i)
//  {
//    printf("%d -> %s\n",i,env[i]);
//  }

//  if(argc != 2) {
//    printf("Usage:%s -[a|h]\n",argv[0]);
//    return 1;
//  }
//  //定制多样的命令，显示不同的内容
//  if(strcmp(argv[1],"-h") == 0)
//  {
//    printf("hello linux\n");
//  }
//  else if(strcmp(argv[1],"-a") == 0)
//  {
//    printf("hello all!\n");
//  }
//  else{
//    printf("hello world!\n");
//  }
   // for(int i = 0;i<argc;i++)
   // {
   //   printf("argv[%d] -> %s\n",i,argv[i]);
   // }
//  int cnt = 5;
//  while(cnt)
//  {
//   // printf("I am a process. pid: %d .ppif: %d\n",getpid(),getppid());
//    sleep(1);
//    printf("I am a cmd -> process!\n");
//    --cnt;
//  }
//  return 0;
//}
