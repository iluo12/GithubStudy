# string

## 模板：



### 泛型编程

#### 函数模板

```c++
模板关键字：tmplate<calss T> //T可以随意改
template<class T> //template<typename T> 模板参数列表 - 参数类型
void Swap(T& x1, T& x2) //函数参数列表 - 参数对象
{
	T x = x1;
	x1 = x2;
	x2 = x;
}
传入不同的类型 会调用不同的实例化函数
多个类型：
    template<class T1,class>
```

#### 模板实例化

调用Swap时 会实例化出不同类型的函数
**实例化**：是指在面向对象的编程中，把用类创建对象的过程称为实例化。 是将一个抽象的概念类，具体到该类实物的过程。 实例化过程中一般由类名对象名= new 类名（参数1，参数2...参数n）构成。

#### 函数模板的实例化

```c
template<class T>
T Add(const T& left, const T& right)//做返回值 和
{
    return left + right;
}
int main()
{
    int a1 = 10, a2 = 20;
    double d1 = 10.1, d2 = 20.2;
    cout << Add(a1, a2) << endl;
    cout << Add(d1, d2) << endl;
    
    cout << Add((double)a1, d2) << endl;
    
    //显示实例化
    cout << Add<int>(d1, d2) << endl; //指定类型
    cout << Add<double>(d1, d2) << endl; 
    
    return 0;
}
结果：
30
30.3
30.2
30
30.3
```

**如果函数模板 和 普通函数 同时存在，优先使用普通函数**

### 类模板

一个栈类型 只能是 int 或 double 或...
定义对象只能满足 int栈 或者double栈
想要存储多个类型 则需要建多个不同类型的 类

```c
template<class T>
class Stack
{
privvate:
    T* _a;
    int _top;
    int _capacity;
}
int main()
{
    Stack<int> st1;//存储int
    Stack<double> st2;//存储double
}
```

## STL:

**S标准T模板L库**
Vue - 前端贡献：尤雨溪

#### 书籍推荐 

《STL源码剖析》《effcrive C++》 继承多态学完看 《高质量C++》现在看

## string

### c++文档：

https://cplusplus.com/

### string

编码 - 值 -- 符号建立映射
ASCII码表 - 表示英文编码表
unicode - 表示全世界文字编码表 utf-8
gbk - 中文编码表



### 常用的string

- 赋值

|       default (1) | `string(); `                                                 |
| ----------------: | ------------------------------------------------------------ |
|          copy (2) | `string (const string& str); `                               |
|     substring (3) | `string (const string& str, size_t pos, size_t len = npos); ` |
| from c-string (4) | `string (const char* s);`                                    |

- [**size**](https://cplusplus.com/reference/string/string/size/)：计算长度

  Return length of string (public member function )

- [**capacity**](https://cplusplus.com/reference/string/string/capacity/)：计算空间大小 不算\0 所以是15

  Return size of allocated storage (public member function )

- [**clear**](https://cplusplus.com/reference/string/string/clear/)：清除string内容

  Clear string (public member function )

- [**reserve**](https://cplusplus.com/reference/string/string/reserve/)

  Request a change in capacity (public member function )

- [**operator[ ]**](https://cplusplus.com/reference/string/string/operator[]/):出错断言assert

  Get character of string (public member function )

  ```
        char& operator[] (size_t pos);
  const char& operator[] (size_t pos) const;
  这里的引用返回时为了 修改返回对象
  ```

  ```c++
  读取
  s1[i] = s1.operator[]  的重载
  ```

  > ![image-20220619201146602](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206192011736.png)

  ```
  修改
  s1[i]+=1;
  ```

  > ![image-20220619201539923](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/image/202206192015956.png)

  

- [**at**](https://m.cplusplus.com/reference/string/string/at/)：出错抛异常

  Get character in string (public member function)

- [**operator+=**](https://m.cplusplus.com/reference/string/string/operator+=/)：尾插字符或字符串

  Append to string (public member function)

  ```c++
  string s1;
  s1 += ':';
  s1 += "hello world";
  cout << s1 << endl;
  ```

- [**append**](https://m.cplusplus.com/reference/string/string/append/)：插入字符串 不常用

  Append to string (public member function)

- [**push_back**](https://m.cplusplus.com/reference/string/string/push_back/)：插入字符串 不常用

  Append character to string (public member function)

```c++
string s1;
s1.push_back('a');
s1.append("bcde");
cout << s1 << endl;
```



