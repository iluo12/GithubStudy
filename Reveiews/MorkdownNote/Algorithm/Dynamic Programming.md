# Dynamic Programming

==2022.7.3 / 2022年7月3日==

## 动态规划

### 第一题：Fibonacci  

斐波那锲数列

[牛客网：JZ10斐波那契数列](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

#### 题解

1. **递归**O(N^2)

   后一个数 等于前两个数相加

   说明：根据斐波那契数列的定义可知，fib(1)=1,fib(2)=1 ，fib(0) = 0;

   ```
   int Fibonacci(int n) {
       递归 O(N^2)
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        return Fibonacci(n-1) + Fibonacci(n - 2);
   }
   ```

   

2. **动态规划**O(N)

   ```c
   int* F = new int[n+1];
   F[0] = 0;
   F[1] = 1;
   for(int i = 2;i <= n;i++)
   {
   	F[i] = F[i - 1] + F[i - 2];
   }
   return F[n];
   ```

3. **动态规划**O(N),空间优化

   ```c
   if(n == 0)
       return 0;
   if(n == 1)
       return 1;
   int fn = 0;
   int fn1 = 1;
   int fn2 = 0;
   for(int i = 2;i <= n; i++)
   {
       fn = fn1 + fn2;
       //更新中间状态
       fn2 = fn1;
       fn1 = fn;
   }
   ```

   

### 第二题：字符串分割(Word Break)  

[牛客网：CC12拆分词句](https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking)

