# 继承

## 继承的概念及定义

继承机制是面向对象程序设计**使代码可以复用**的最重要的手段

| 类成员/继承方式      | public继承             | protected继承          | private继承          |
| -------------------- | ---------------------- | ---------------------- | -------------------- |
| 基类的public成员     | 派生类的public成员     | 派生类的protected成 员 | 派生类的private成 员 |
| 基类的protected成 员 | 派生类的protected成 员 | 派生类的protected成 员 | 派生类的private成 员 |
| 基类的private成员    | 在派生类中不可见       | 在派生类中不可见       | 在派生类中不可见     |

### 命名：

父类/基类

子类/派生类

### 继承关系

|           |                                   |
| --------- | --------------------------------- |
| public    | 父子 类内外都可用                 |
| protected | 父子 类内可以用，父子类外不可用   |
| private   | 父 类内可以用，父类外和其他不可用 |

### 常见的继承使用：

父类成员：公有和保护

子类继承方式：公有继承

### 不写访问限定符

struct 默认公有、class默认私有

#### 不写继承方式

struct 默认公有、class默认私有，按照 public > protected > private 取最小的使用

## 赋值兼容规则

### 切片/切割(公有继承)

**【私有继承】则不可以切割，可能存在权限的转换。**(在子类继承方式中是私有的，在父类中可能是公有，则会发生权限的放大，不支持)

#### 子 给 父 

```c++
class Person// 父
{
public:
	void print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	int _ss;
protected:
	string _name = "peter";
	int _age = 18;
private:
	int _aa;

};

struct Student :  public Person   //子类
{
public:
	void f()
	{
		print();
	}
protected:
	int _stuid;//学号
};
int main()
{
	Person p;
	Student s;

	//父类 = 子类赋值兼容 -> 切片 切割  (公有继承可用)
    //这里不是类型转换，是无法天然的支持行为 ，转换时不产生临时变量
	p = s;
	Person* ptr = &s;  //指向切片的部分
	Person& ref = s;   //指向切片的部分

	return 0;
}
```

**把 子类中继承父类 的成员  切割出来赋值给父类，至于子类中多余的成员被切割掉了  不赋值。**

#### 父 给 子

不可以，但是指针和引用可以，小心用可能会发生越界访问

```c++
class Person
{
public:
	void print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
		
	}
	int _ss;
protected:
	string _name = "peter";
	int _age = 18;
private:
	int _aa;
};
struct Student : public Person
{
public:
	void f()
    {}
protected:
	int _stuid;//学号
public:
	int _No;
};

//子类 = 父类
int main()
{
	Person p;
	Student s;
	//子类 = 父类
	//s = p;//不可以
	//但是指针和引用可以，小心用可能会发生越界访问
	Student* pptr = (Student*)&p;
	Student& rref = (Student&)p;
	
    //危险的，存在越界访问的风险
	pptr->_No = 1;

	return 0;
}
```

