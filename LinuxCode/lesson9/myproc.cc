#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;
int main()
{
    pid_t id = fork();
    if(id ==0 ) {
      //child
      while(true){
        cout << "I am chile,running!"<<endl;
        sleep(2);
      }
    }
    else{
      //parent
      cout << "father do nothing!" << endl;
      sleep(10);
      exit(1);
    }
//    while(true)
//    {
//      std::cout << "hello world!" << std::endl;
//    }
//    pid_t id = fork();
//    if(id == 0)
//    {
//      //child
//      while(true){
//        std::cout << "I am child,pid: "<< getpid() << ", ppid: " << getppid() << std::endl;
//        sleep(1);
//      }
//    }
//    else if(id>0){
//      //parent
//      while(true){
//        std::cout << "I am child,pid: "<< getpid() << ", ppid: " << getppid() << std::endl;
//        sleep(2);
//    }
//    }
//    else
//    {
//      //TODU
//    }
//    sleep(1);
    return 0;
}
