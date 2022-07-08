# UAENA.4_Linux进程控制

## 创建进程

### fork函数初识

```c++
#include <unistd.h>
pid_t fork(void);
返回值：自进程中返回0，父进程返回子进程id，出错返回-1
```

> ![image-20220708211937371](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20220708211937371.png)

**创建进程是有成本的(时间 + 空间)**

## 进程终止

### 进程退出场景

- 代码运行完毕，结果正确
- 代码运行完毕，结果不正确
- 代码异常终止  

为什么main都要return 0;？

退出码：0表示success(成功)

```c++
return 0;
```

