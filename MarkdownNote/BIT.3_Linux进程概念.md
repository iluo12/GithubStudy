## 冯诺依曼体系结构
**1.输入设备**(外设)：(毫秒，秒)键盘、磁盘、网卡、显卡、话筒、摄像头等
**2.输出设备**(外设)：(毫秒，秒)显示器、磁盘、网卡、显卡、音响等
**3.存储器(内存)**：(微妙) 这里 计算机的速度由内存决定
**4.运算器&控制器(CPU)**：(纳秒)
**木桶效应**：木桶能盛多少水由最短的板子决定
```c
输入设备  -input->  存储器  -output->  输出设备

input+output = IO {本地IO(磁盘)、网络IO(网卡)}
```
```
flowchart LR
    输入设备:input --> 存储器 --> outpu:输出设备
```
```
stateDiagram-v2
    state if_state <>
    [*] --> CPU
```
**任何外设，在数据层面，基本有限和内存打交道！ CPU，在数据层面上，也直接和内存打交道**
解释QQ聊天
我：键盘输入(外设)-> 内存接收(qq软件控制) -> CPU处理(加密或添加网络传输条件)->内存接收->网卡输出-> {网络} -> 
朋友： {网络}-> 网卡接收 -> 输入给内存 -> CPU处理 -> 内存接收 -> 输出到显示器(外设)
## 操作系统
**启动操作系统**才有意义 ：将软件数据与代码，加载到内存
#### 1.操作系统OS 是什么？
> 是一款软件，专门针对于软硬件资源进行管理工作的软件

#### 2.操作系统OS 为什么？
> 对下(方式)：管理好软硬件资源。 对上(目的)：给用户提供稳定的，高效的，安全的运行环境。

#### 3.操作系统OS 怎么办？
> 管理！ ->  决策 、执行 
> 对被管理对象：先描述 再组织
#### 4.如何管理进程？
> 先描述：描述进程的结构体 - PCB进程控制块 (描述进程的结构体) 
> 再组织：

# 推荐书籍《操作系统精髓设计与原理》 《现在操作系统》

### 操作系统(Operator System)
用户&emsp;&emsp;&emsp;&emsp;：操作指令、开发操作、操作管理
用户接口&emsp;&emsp;：shell外壳、lib库、不分指令
系统调用接口：
操作系统&emsp;&emsp;：内存管理、进程管理、文件管理、驱动管理
驱动程序&emsp;&emsp;：网卡驱动、硬盘驱动、其他驱动
底层硬件&emsp;&emsp;：网卡、硬盘、其他
### 进程
书上：加载到内存的程序，叫进程

### 为什么要有PCB ？因为要管理 
系统中存在大量的进程！
操作系统要管理进程！：杀掉进程
如何管理进程？：先描述，再组织

先描述：任何进程在形成之时，操作系要为该进程创建`PCB` `进程控制块` -> `struct PCB{//进程的所有属性}`



### OS上 什么是PCB ？ 就是一个结构体类型
在linux系统中 ，PCB -> struct task_struct{//进程的所有的属性}
总称是PCB  在linux上叫 struct task_struct
媒婆是总称 ，王婆是媒婆中的一个

### task_struct里面有什么属性字段？
##### 查看进程
```c
显示进程ps axj | grep "myproc"
18857 20701 20701 18857 pts/0    20701 S+    1001   0:00 ./myproc
显示头部名称+进程ps ajx | head -1 && ps axj | grep "myproc"
 PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
18857 20701 20701 18857 pts/0    20701 S+    1001   0:00 ./myproc
```
曾经我们所有的启动程序需的过程，本质都是在系统上面创建进程

### 进程 VS 程序
程序是：文件 xxx.exe(可执行文件)
进程 = 程序(文件内容) + 与进程相关的数据结构(PCB(sask_struct{})) pcb由系统自动创建

# task_struct内容分类
### 一、标识符：
#### 获取进程
printf("hello bit!:pid: %d\n",getpid()); 
#### 获取父进程
printf("hello bit!:pid: %d ，ppid:%d\n",getpid(),getppid()); 
```c
hello bit!:pid: 3929,ppid:18857

[wx@VM-16-12-centos lesson8]$ ps ajx | grep 18857
18857  3929  3929 18857 pts/0     3929 S+    1001   0:00 ./myproc
20942  4441  4440 20942 pts/1     4440 S+    1001   0:00 grep --color=auto 18857
18856 18857 18857 18857 pts/0     3929 Ss    1001   0:00 -bash

ppid 是-bash
```
**在命令行上运行的命令，基本上父进程都是bash**
#### 干掉进程
kill -9 2543(pid)
### 二、状态：
#### return 0; 是什么？
是进程退出码，返回给操作系统后  让父进程拿到
`echo $?` 可以查看最近一次命令的退出码

### 三、优先级：
决定先后的问题 vs 权限
权限：能&不能
优先级：先&后  (已经能了)
### 四、程序计数器
指向 程序中下一条指令的地址
(函数栈帧)
### 五、内存指针
可以通过内存指针  找到进程的代码和数据
### 六、上下文数据
固定每个进程单词运行的时间片：每次运行10ms
完成10ms  之后从在`队列中`新排队
这样用户就感觉 多个进程在同时运行，本质是通过cpu的快速切换完成的
**进程在运行期间是有切换，进程可能存在大量的临时数据，->这哪是在CPU的寄存器中保存**
==但是CPU只有一套`寄存器`==

**当兵：保护上下文**：走的时候要告诉学校，我先去当兵了，帮我把学籍保留一下
**上学：恢复上下文**：回来的时候告诉学校，我回来了，帮我把学籍恢复 我要继续学习。
为了让你做其他事，不耽误当前，硬切当你想回来继续学时，可以接着你之前的学习内容继续学习
##### A的保护上下文
保护上下文：A-PCB 保存好自己的临时数据 再去排队
回来的时候 ：先恢复临时数据 

##### 上下文信息
进程执行时所形成的处理器 寄存器形成的 与进程墙相关的临时数据 就叫做`**上下文信息**`

### 七、I/O状态信息
进程的输入输出信息
### 八、记账信息
包括 处理器时间总和，使用的时钟数总和，时间限制，记账号等
进程被调度的记账信息   进程使用了多少秒 用来分配使用进程
### 九、其他信息

## 查看进程
```c
[wx@VM-16-12-centos lesson8]$ ls /proc
1      17859  23616  2729   30110  644        consoles     mounts
10     18     24     273    30165  646        cpuinfo      mtrr
10030  18189  24209  2731   30168  647        crypto       net
106    18423  24466  2733   30853  65         devices      pagetypeinfo
11     18680  24594  27566  31170  651        diskstats    partitions
1191   18720  24702  27575  35     653        dma          sched_debug
12     18824  25     27900  36     663        driver       schedstat
1212   18856  25041  27971  37     7          execdomains  scsi
1240   18857  25519  28     38     8          fb           self
1269   18870  25659  280    387    8867       filesystems  slabinfo
12718  18885  257    28358  3919   8868       fs           softirqs
12881  18908  26     28362  4      8869       interrupts   stat
13     19     26059  28363  408    8870       iomem        swaps
14     1912   262    28366  409    8872       ioports      sys
1466   2      263    28368  46     8874       irq          sysrq-trigger
1467   20     264    28868  48     8876       kallsyms     sysvipc
15604  208    265    28900  49     9          kcore        timer_list
15607  20939  26774  28901  51     9088       keys         timer_stats
15614  20941  269    28988  515    9089       key-users    tty
15619  20942  26932  29     52     9090       kmsg         uptime
15627  20957  26951  291    5410   923        kpagecount   version
15628  20973  26957  292    5413   987        kpageflags   vmallocinfo
15634  20992  26958  29923  5415   989        loadavg      vmstat
15696  21     27     30089  5417   acpi       locks        zoneinfo
1589   21298  27004  30096  5419   buddyinfo  mdstat
16     22     2724   30097  5421   bus        meminfo
1676   22882  2725   30104  566    cgroups    misc
1764   23     2727   30105  6      cmdline    modules
[wx@VM-16-12-centos lesson8]$ ls -d /proc -l
dr-xr-xr-x 175 root root 0 Apr 28 21:57 /proc
[wx@VM-16-12-centos lesson8]$ ls /proc/26932
attr             cwd       map_files   oom_adj        schedstat  task
autogroup        environ   maps        oom_score      sessionid  timers
auxv             exe       mem         oom_score_adj  setgroups  uid_map
cgroup           fd        mountinfo   pagemap        smaps      wchan
clear_refs       fdinfo    mounts      patch_state    stack
cmdline          gid_map   mountstats  personality    stat
comm             io        net         projid_map     statm
coredump_filter  limits    ns          root           status
cpuset           loginuid  numa_maps   sched          syscall
[wx@VM-16-12-centos lesson8]$ ls /proc/26932 -al
total 0
dr-xr-xr-x   9 wx   wx   0 Jun  8 19:31 .
dr-xr-xr-x 174 root root 0 Apr 28 21:57 ..
dr-xr-xr-x   2 wx   wx   0 Jun  8 19:33 attr
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 autogroup
-r--------   1 wx   wx   0 Jun  8 19:33 auxv
-r--r--r--   1 wx   wx   0 Jun  8 19:33 cgroup
--w-------   1 wx   wx   0 Jun  8 19:33 clear_refs
-r--r--r--   1 wx   wx   0 Jun  8 19:31 cmdline
-rw-r--r--   1 wx   wx   0 Jun  8 19:32 comm
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 coredump_filter
-r--r--r--   1 wx   wx   0 Jun  8 19:33 cpuset
lrwxrwxrwx   1 wx   wx   0 Jun  8 19:31 cwd -> /home/wx/Class_102_linux/lesson8
-r--------   1 wx   wx   0 Jun  8 19:33 environ
lrwxrwxrwx   1 wx   wx   0 Jun  8 19:31 exe -> /home/wx/Class_102_linux/lesson8/myproc
dr-x------   2 wx   wx   0 Jun  8 19:31 fd
dr-x------   2 wx   wx   0 Jun  8 19:33 fdinfo
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 gid_map
-r--------   1 wx   wx   0 Jun  8 19:33 io
-r--r--r--   1 wx   wx   0 Jun  8 19:33 limits
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 loginuid
dr-x------   2 wx   wx   0 Jun  8 19:33 map_files
-r--r--r--   1 wx   wx   0 Jun  8 19:33 maps
-rw-------   1 wx   wx   0 Jun  8 19:33 mem
-r--r--r--   1 wx   wx   0 Jun  8 19:33 mountinfo
-r--r--r--   1 wx   wx   0 Jun  8 19:33 mounts
-r--------   1 wx   wx   0 Jun  8 19:33 mountstats
dr-xr-xr-x   5 wx   wx   0 Jun  8 19:33 net
dr-x--x--x   2 wx   wx   0 Jun  8 19:33 ns
-r--r--r--   1 wx   wx   0 Jun  8 19:33 numa_maps
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 oom_adj
-r--r--r--   1 wx   wx   0 Jun  8 19:33 oom_score
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 oom_score_adj
-r--r--r--   1 wx   wx   0 Jun  8 19:33 pagemap
-r--------   1 wx   wx   0 Jun  8 19:33 patch_state
-r--r--r--   1 wx   wx   0 Jun  8 19:33 personality
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 projid_map
lrwxrwxrwx   1 wx   wx   0 Jun  8 19:31 root -> /
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 sched
-r--r--r--   1 wx   wx   0 Jun  8 19:33 schedstat
-r--r--r--   1 wx   wx   0 Jun  8 19:33 sessionid
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 setgroups
-r--r--r--   1 wx   wx   0 Jun  8 19:33 smaps
-r--r--r--   1 wx   wx   0 Jun  8 19:33 stack
-r--r--r--   1 wx   wx   0 Jun  8 19:31 stat
-r--r--r--   1 wx   wx   0 Jun  8 19:32 statm
-r--r--r--   1 wx   wx   0 Jun  8 19:31 status
-r--r--r--   1 wx   wx   0 Jun  8 19:33 syscall
dr-xr-xr-x   3 wx   wx   0 Jun  8 19:33 task
-r--r--r--   1 wx   wx   0 Jun  8 19:33 timers
-rw-r--r--   1 wx   wx   0 Jun  8 19:33 uid_map
-r--r--r--   1 wx   wx   0 Jun  8 19:33 wchan
[wx@VM-16-12-centos lesson8]$ 
```
```c
lrwxrwxrwx   1 wx   wx   0 Jun  8 19:31 cwd -> /home/wx/Class_102_linux/lesson8
-r--------   1 wx   wx   0 Jun  8 19:33 environ
lrwxrwxrwx   1 wx   wx   0 Jun  8 19:31 exe -> /home/wx/Class_102_linux/lesson8/myproc

```
exe 程序文件
cwd 当前工作目录



