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

## string 成员函数

### c++文档：

https://cplusplus.com/

### 编码补充

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

## string 迭代器



```
	//遍历+修改
	//方式1：下标+[]  
	//返回对应位置的引用  可以直接修改s1[i]
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
	}
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
```

迭代器想象成：像指针一样的类型

### end()/begin()

```c++
      iterator begin();
const_iterator begin() const;

      iterator end();
const_iterator end() const;
```

```c++
string s1("hello world");
//方式2：迭代器(iterator)
//begin()指的是第一个元素的位置  end()是最后一个元素的【下一个】
//it像指针一样指向第一个元素 ，可以解引用，可以++
string::iterator it = s1.begin();
while (it != s1.end())
{
    *it -= 1;
    ++it;
}
it = s1.begin();//重置it的位置
while (it != s1.end())
{
    cout << *it << " ";
    ++it;
}
cout << endl;
```

#### iterator begin();

范围for会替换成迭代器

```c++
//方式3：范围for   语法糖用起来很爽很甜
// C++11   linux：-std=c++11
//把s1中的值取出来 赋值给e 自动++
//for (char& e : s1) 
for (auto& e : s1) //引用  
{
    e += 1;
}
for (auto e:s1)
{
    cout << e << " ";
}
cout << endl;
```

#### const_iterator begin() const;

const 版本只能读取 不能修改

```c++
void func(const string& s1)
{
	string::const_iterator it = s1.begin();
	//auto it = s1.cbegin(); //cbegin()和cend()代表const
	while (it != s1.end())
	{
		//*it -= 1; //不能修改
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
```



### rbegin()  / rend(): 反向迭代器 

```c++
      reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
```

- **rbegin() 最后一个字符**
- **rebing()的 ++ 是向前走**
- **rend()是第一个字符的前一个**

```c++
void test_string2()
{
	string s1("hello world");
	//反向迭代器
	//rbegin() 指向最后一个字符 
	//
	//反向++ 是逆向的
	//string::reverse_iterator rit = s1.rbegin(); // string::reverse_iterator是类型
	auto rit = s1.rbegin();//代替上面那句自动推到类型
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	string cstr("hello world");
	func(cstr);
}
```

### c++11 新增const迭代器

- [**cbegin**](https://m.cplusplus.com/reference/string/string/cbegin/)

- [**cend**](https://m.cplusplus.com/reference/string/string/cend/)

- [**crbegin**](https://m.cplusplus.com/reference/string/string/crbegin/)

- [**crend**](https://m.cplusplus.com/reference/string/string/crend/)

### 迭代器的意义是什么？

> **所有的容器都可以使用迭代器这种方式去访问修改**

#### 答：

对于string，下标和[]就足够好用，确实可以不用迭代器。

#### **其他容器(数据结构)呢？**

(list、map/set 并不支持下标，只有数组才支持[]，这些是链表和二叉树并不支持下标+[])

>  **所以迭代器才是通用的方式**

## string 增容

#### 测试代码

```c++
void TestPushBack()
{
	string s;
	//s.reserve(1000);//申请至少能存储10000个字符的空间  不一定是1000 要空间对其

	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 2000; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
```

##### 结果

```c++
capacity changed: 15	//本质是16 但是没算\0  有效字符位置有15个
making s grow:
capacity changed: 31	//本质是32 但是没算\0  有效字符位置有31个
capacity changed: 47
capacity changed: 70
capacity changed: 105
capacity changed: 157
capacity changed: 235
```

 string
