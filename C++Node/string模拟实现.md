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
