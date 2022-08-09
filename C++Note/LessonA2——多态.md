# 多态

## 概念

**多种形态**

本质：不同的人做同一件事 会产生不同的效果、结果不同。

举栗子：比如**买票这个行为**，当**普通人**买票时，是全价买票；**学生**买票时，是半价买票；**军人**买票时是优
先买票。  



## 构成条件

1.必须通过基类的指针或引用调用虚函数

2.内调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写。

**指针或引用 + 三同(函数名、参数、返回值)虚函数**

> **//构成多态，穿的哪个类型的对象，调用的就是这个类型的虚函数。——跟传来的对象有关**
> **//不构成非多态，跟P的类型有关。——跟P的类型有关，跟传过来的对象无关**

```c++
//多态：多种形态
//静态的多态：函数重载 ，同一个函数有不同的行为。静态：编译时
//动态的多态：一个父类对象的引用或指针调用同一个函数，传递不同的对象。会调用不同的函数。动态：
//本质：不同的人做同一件事 会产生不同的效果、结果不同。
// 
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	//子类中满足三同(函数名、参数、返回值)的虚函数，叫做重写(覆盖)
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};
//构成多态，穿的哪个类型的对象，调用的就是这个类型的虚函数。——跟传来的对象有关
//不构成非多态，跟P的类型有关。——跟P的类型有关，跟传过来的对象无关
void Func(Person& p) //不是指针或引用则不是多态，则调用Person
{
	p.BuyTicket(); //多态
}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st); //切片传递
	return 0;
}
```

### 虚函数

虚函数的关键字：virtual

类的非静态函数，才能定义成虚函数，其他函数不能成为虚函数。

```C++
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
```

### 重写

子类中满足三同(**函数名、参数、返回值**)的**虚函数**，叫做重写(覆盖)

#### 特例

**==重写要求返回值必须相同，协变例外==**

##### 1.协变(基类与派生类虚函数返回值类型不同)  

 要求返回值是父子关系的指针或引用

```c++
class A {};
class B : public A {};

class Person {
public:
	//virtual A* BuyTicket() { cout << "买票-全价" << endl;  return nullptr; } // 多态
	virtual Person* BuyTicket() { cout << "买票-全价" << endl;  return nullptr; } // 多态
};
class Student : public Person {
public:
	//子类中满足三同(函数名、参数、返回值)的虚函数，叫做重写(覆盖)
	//virtual B* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }  // 多态
	virtual Student* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }  // 多态
};

/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继承后
基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用*/
/*void BuyTicket() { cout << "买票-半价" << endl; }*/


//构成多态，跟传的类型有关
//不构成非多态，跟P的类型有关。
void Func(Person& p)
{
	p.BuyTicket(); //多态
}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st); //切片传递
	return 0;
}
```

#### 析构函数的重写  

析构函数是虚函数，是否构成重写？ 构成

析构函数名被特殊处理了，处理成了destructor

```c++
class Person {
public:
    //有virtual 则能正常调用，没有则不能
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};

void Func(Person& p)
{
	//p.BuyTicket(); //多态
}

int main()
{
	//普通对象 析构函数是否虚函数，是否完成重写，都正确调用了
	//Person ps;
	//Student st;
			//~Student()
			//~Person()
			//~Person()
	Person* p1 = new Person; // operator new + 构造函数
	Person* p2 = new Student; //多态
    Student* p2 = new Student; // 不是多态 有没有virtual都能正确调用析构
	//析构函数 + operator delete
	//				p1->destructor();
	delete p1;	
	delete p2;
	//				p1->destructor();
    
    		//有virtual
    			//~Person()
				//~Student()
				//~Person()
    		//无virtual
    			//~Person()
				//~Person()
    
    
    
	return 0;
}
```

### 继承virtual

**父子的virtual不建议不写 ==建议全写==**

父亲写了virtual，子类没写，也够成虚函数。

```c++
class Person {
public:
	virtual Person* BuyTicket() { cout << "买票-全价" << endl;  return nullptr; } // 多态

};
class Student : public Person {
    Student* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }//私有的也算虚继承，只重写了内容
public:

	//子类没写virtual，但是他是先继承了父类的虚函数的属性，在完成重写，那么也算虚函数
	Student* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }  // 多态
};
```

本质上，子类重写的虚构函数，可以不加virtual是因为析构函数，是因为，父亲析构函数加上virtual，而子类忘记加，那么就不构成多态，没调用子类的析构函数，造成该内存泄漏。

### 为什么？

为什么多态的条件必须是基类的指针和引用：既可以传父类，也可以传子类

### C++11关键字

#### final

想让一个类不能被继承

```c++
class A final
{};
```

修饰虚函数，在父类添加，实现子类中禁止重写

```
class B
{
public:
	viraual void f() final
	{cout << "C::f()" << endl;}
};
class C :public B
{
public:
	viraual void f()
	{cout << "C::f()" << endl;}
};
```

### override

放在子类重写的虚函数的后面，检查是否完成重写

没重写就会报错

```c++
class Car{
public:
	virtual void Drive()
	{}
};
class Benz :public Car {
public:
	virtual void Drive() override
    {cout << "Benz-舒适" << endl;}
};
```

### 重载、覆盖、隐藏的对比

|            | 重载                            | 重写(覆盖)                                       | 重定义(隐藏)                                       |
| ---------- | ------------------------------- | ------------------------------------------------ | -------------------------------------------------- |
| **作用域** | 两个函数在不同作用域            | 两个函数分别在基类金额派生类的作用域             | 两个函数分别在基类和派生类的作用域                 |
| **函数**   | ==函数、参数不同== 返回值没要求 | 函数名、返回值、参数都必须相同(协变类外)==三同== | 函数名相同                                         |
| **补充**   | —                               | 两个函数必须是==虚函数==                         | 像个基类和派生类的同名函数==不构成重写就是重定义== |

## 抽象类

**包含纯虚函数的类**叫做抽象类(接口类) 抽象类不能实例化出对象。派生类继承后也不能实力出对象。只有重写纯虚函数，派生类才能实例化对象

==在虚函数的后面写上 =0==  

```c++
class Car
{
public:
	virtual void Drive() = 0;
};
```

虚函数可以实现代码，但没价值，生成解决方案 可以调用的到，但是运行会报错

### 理解

抽象——现实世界没有对应的实物

一个类型，如果一般在限时世界中，没有具体的对应实物就定义成抽象类比较好。

### 作用

纯虚函数的类，本质上强制的子类去完成虚函数得重写

override知识在语法上检查是否完成重写

## 多态的原理

### 虚函数表

```c++
// 这里常考一道笔试题：sizeof(Base)是多少？
class Base
{
public:
    virtual void Func1()
    {
        cout << "Func1()" << endl;
    }
private:
	int _b = 1;
    int
};
```

