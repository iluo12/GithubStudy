#include <iostream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <cerrno>
#include <sys/types.h>
#include <assert.h>
#include <sys/wait.h>

int main()
{
    //在任何进程通信中，先保证不同的进程看到同一份资源
    int pipefd[2] = {0};
    //1.创建管道
    int n = pipe(pipefd);//返回0 成功，错误返回-1
    if(n < 0)
    {
        //如果出现错误，会设置全局变量errno，根据errno打印错误信息
        std::cout << "pipe error" << errno << ":" << strerror(errno) << std::endl;
    }
    std:: cout << "pipefd[0]:" << pipefd[0] <<std::endl; //读
    std:: cout << "pipefd[1]:" << pipefd[1] <<std::endl; //写
    
    //2.创建子进程
    pid_t id = fork();
    assert(id != -1);//意料之外用if  意料之中用assert

    //第一步通信，读写
    // if(id == 0)
    // {
    //     //子进程 
    //     //关闭不需要的 fd 父读，子写  读0 写1  子写则关闭0
    //     close(pipefd[0]);
    //     const std::string namestr = "hello,我是子进程";
    //     int cnt = 1;
    //     char buffer[1024];
    //     while(true)
    //     {   
    //         //将代码写到buffer里，多少字节，写什么。
    //         snprintf(buffer,sizeof buffer,"%s,计数器：%d,我的PID: %d\n",namestr.c_str(),cnt++,getpid());
    //         //往那里写(管道)，写什么，写多少
    //         write(pipefd[1],buffer,strlen(buffer));
    //         sleep(10);
    //     }
    //     close(pipefd[1]);
    //     exit(0);
    // }

    //第二次通信一直写，写满了
    //第三次通信，写一次，关闭写端

    if(id == 0)
    {
        close(pipefd[0]);
        int cnt = 0;

        while(true)
        {   
            char x = 'X';
            write(pipefd[1],&x,1);
            std::cout << " Cnt: " << cnt++ << std::endl;
            sleep(1);
            //break;
        }
        close(pipefd[1]);
        exit(0);
    }

    //父进程 

    //3.关闭不需要的fd，让父进程读取，子进程写入
    close(pipefd[1]); //父亲读0 则关闭1
 
    //4.开始通信 -- 结合某种场景
    char buffer[1024];//保存读取到的数据
    int cnt = 0;
    while(true)
    {
        //sleep(10);
        //read （从哪里读[管道读端]，存到哪里，存的位置大小
        int n = read(pipefd[0],buffer,sizeof(buffer) - 1); //减一是因为给字符串留一个位置放 \n

        if(n > 0) // > 0则成功了
        {
            buffer[n] = '\0';
            std::cout << "我是父进程,child give me message: " << buffer << std::endl;
        }
        else if(n == 0 ) // ==0则是另一方退出了
        {
            std::cout << "我是父进程，读到了文件结尾" << std::endl;
            break;
        }
        else{
            std::cout << "我是父进程,读异常了" << std::endl;
            break;
        }
        sleep(1);
        if(cnt++ > 5) break;
    }
    close(pipefd[0]);

    int status = 0;
    waitpid(id,&status,0);
    std::cout << "sig:" << (status & 0x7f) << std::endl;

    sleep(100);
    
    return 0;
}