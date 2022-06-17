# BIT.3_Linux进程概念

## vim指令

### vim报错：E325: ATTENTION

![QQ截图20220616231248](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206170058633.jpg)

### 1. 不退出vim查看man手册

```c++
!man fork
```

### 2. 不退出vim 编译运行代码

```
!make
./myproc
```

## 理解fork创建子进程

### 1. 理解

fork本身是创建进程 -> 系统多了一个进程 -> 子进程用父进程的代码，数据时写时拷贝的

**因为进程之间不会会想影响**

**不管是fork前后的代码 fork都汇继承**

### 2. fork之后，父子谁先运行？？ 

不确定，调度器决定

## Linux进程状态

### 1. 进程的状态信息在哪里？

`task_struct(PCB)`

### 2. 进程状态的意义：

方便OS 快速判断进程，完成特定的功能，比如调度，本只是一种分类！

### 3. 具体状态：

进程，在运行的时候，有可能因为运行需要，可以会在不同的队列里

在不同的队列里，所处的状态是不一样的！

例如：

​			运行时在`run_queue`

​			等待时在`wait_queue`

> ​			![image-20220617134756856](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171347909.png)

- #### R(running)：运行状态

  一定占有`CPU`吗？ 不一定！！！ 只要在`PCB`中的队列中，都是`R`状态

  

- #### S、D:等待状态

  当我们完成某种任务的时候，任务条件不具备，需要进程进行某种等待，`S`、`D`

  这些进程也存在 等待`wait_queue`队列中

  - ##### S(sleeping)：休眠睡眠

    可中断睡眠

  - ##### D(disk sleep)：深度睡眠

    进程处于D状态，不可被杀掉，OS也不行
  
    - ###### 如何结束
  
      进程运行完成、重启OS
  
  - ##### 程序为什么会出现卡死?，卡死后`Windows`提示是否等待或关闭是为什么？
  
    > >  因为：程序可能在等待某种资源，例如网易云音乐正在播放音乐，拔掉网线后，网易云音乐进程一直在等待网卡中的数据，由于没网，进程处于等待状态，而进程等待时不能能一直占用`CPU`，所以出现了卡死的现象，其实就是进程在`S`、`D`（等待）状态！
    >>
  
  - ##### **结论：**
  
     		我们把，从运行状态的`task_struct(run_queue)`,放到等待队列中，就叫做`挂起等待`(阻塞)
    		从等待队列，放到运行队列，被`CPU`调度就叫做`唤醒程序`

- #### T(stopped)：暂停

- #### t(tracing stop)：追踪状态(暂停) 

  打断点就是最终状态，代码被暂停

- #### X(dead)：死亡状态(基本查不到 很少见 瞬间就没了)

  回收进程资源 = 进程相关的内核数据结构 + 你的代码和数据

- #### Z(zombie)：僵尸状态(先进入Z状态 -> 由Z转为X)

  - ##### 为什么要有僵尸状态？

    为了辨别退出死亡原因 -> 进程退出的信息 -> 数据 -> task_struct

### 4. 验证状态：

- #### R

  > 死循环运行时 ，进程就是`R`运行状态   没有`IO`就不会等待所以 一直`R`

  > ![image-20220617115928693](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171159763.png)

- #### S

  > 当程序在死循环打印时，进程是s状态 ，也会有R状态

  > ![image-20220617120457864](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171204923.png)

  ##### 为什么呢？

  > ![image-20220617121122827](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171211861.png)

  因为`cout`是在进行打印，显示器和外设都很慢，`IO`等待外设就绪是需要花费时间的！所以基本都是 因为外设慢 (在cpu看来) ，所以等待外设就绪 就是`S`状态  但是外设不一定都在等待，也有可能在运行`R`！

- #### T

  可以看到第一次查询时`S`后有`+`号  意思是在前台运行

  暂停 STOP(暂停后`T`后面没有`+`号)

  > ![image-20220617122228107](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171222182.png)

  继续CONT(此时`S`后面的`+`号也没有了，这时进程就变成了后天运行，左面的死循环用`ctrl+c`不能结束了)

  > ![image-20220617122430501](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171224578.png)

  干掉进程KILL(此时后台进程只能用命令杀死)

  > ![image-20220617122854666](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171228736.png)

  - 前台运行

    ```c++
    ./myproc
    ```

    前台运行时，可以用`ctrl+c`结束进程，但是不能输入其他命令了

  - 后台运行

    ```c++
    ./myproc &
    ```

    后天运行是，可以继续输入命令，但是`ctrl+c`不能杀掉进程，可以选择`kill`杀掉进程

  - 杀掉进程

    ```c++
    kill -9 pid
    ```

  - 查看pid

    ```c++
    ps axj | grep myproc 
    ```

    第二列是pid

    ```
    显示头部名称+进程ps ajx | head -1 && ps axj | grep "myproc"
     PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
    18857 20701 20701 18857 pts/0    20701 S+    1001   0:00 ./myproc
    ```

- #### Z

  如果没有人`检测或者回收`进程(父进程)，该进程进入`Z`状态，

  如何检测和回收？ 后面讲

  如何看到这种状态？

  - 检测状态代码

    ```c++
    [wx@VM-16-12-centos lesson9]$ while :; do ps axj | head -1 && ps ajx | grep myproc | grep -v grep; sleep 1; echo "#####################"; done
     PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
    #####################
    ```

  - 查看`Z`状态

    让父子同时运行 ，杀掉子进程，父进程进行`sleep`，此时子进程状态就是`Z`

    > ![image-20220617131108909](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171311992.png)

  - 进程代码

    ```c++
    #include <iostream>
    #include <unistd.h>
    
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
          sleep(50);
        }
    }
    ```

  - 结束命令

    ```c++
    kill -9 pid
    ```
### 5. 僵尸进程：
  - 进程演示

    父子同时运行 ，杀掉子进程，父进程进行`sleep`，此时子进程状态就是`Z`，子进程是`僵尸进程`

    > ![image-20220617131108909](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171311992.png)

  - 进程代码

    ```c++
    #include <iostream>
    #include <unistd.h>
    
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
          sleep(50);
        }
    }
### 6. 孤儿进程：

- 进程演示

  父子同时运行，父亲挂了，子还活着，此时子是`孤儿进程`

  由1号进程领养，1号是操作系统`OS`

> ![image-20220617132851510](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206171331411.png)

- 进程代码

    ```c++
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
    }
    ```

