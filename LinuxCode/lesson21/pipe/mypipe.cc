#include <iostream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <cerrno>
#include <sys/types.h>
#include <assert.h>

int main()
{
    //让不同的进程看到同一份资源
    //在任何一种进程通讯中，一定要 先 保证不同的进程之间看到同一份资源
    int pipefd[2] = {0};
    //1.创建管道
    int n = pipe(pipefd);
    if(n < 0)
    {
        std::cout << "pipe error," << errno << ":" << strerror(errno) <<std::endl;
    }
    std::cout << "pipefd[0]:" << pipefd[0] <<std::endl;//读端 0->嘴巴->读书
    std::cout << "pipefd[1]:" << pipefd[1] <<std::endl;//写端 1->笔->写东西
    
    //2.创建子进程
    pir_t id = fork();
    assert(id != -1);  //意料之外用if  意料之中用assert

    if(id == 0)//子进程
    {
        //3.关闭不需要的fd，让父进程读取，子进程写入
        close(pipefd[0]);

        //4.开始通信 -- 结合某种场景
        std::string namestr = "hello,我是子进程";
        int cnt = 1;
        char buffer[1024];
        while(true)
        {
            snprintf(buffer,sizeof buffer,"%s,计数器：%d,我的PID:%d\n",namestr.c_str(),cnt++,getpid());
            write(pipefd[1],buffer,strlen(buffer));
            sleep(1);
        }

        exit(0);    
    }

    //父进程
    //3.关闭不需要的fd，让父进程读取，子进程写入
    close(pipefd[1]);





    //4.开始通信 -- 结合某种场景
    char buffer[1024];
    while(true)
    {
        int n = read(pipefd[0],buffer,sizeof(buffer) - 1);
        if(n > 0)
        {
            buffer[n] = '\0';
            std::cout << "我是父进程，child give me message" << buffer << std::endl;
        }
    }


    close(pipefd[0]);
    return 0;
}