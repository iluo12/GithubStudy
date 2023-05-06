# PHP笔记

## PHP规范

### 格式

`<?php     ?>`

### 注释

多行注释：`/*   */`

单行注释：`//`

## 常量和变量

### 变量

#### 格式

代码结束符：`;`

定义变量：`$anme;`

存储int：`$name = 123;`

存储字符串：`$name = 'holle world';`

#### 全局变量

必须用globa声明才可以变成全局的

但是globa之能是把外面的局部变量，在内部声明成全局

内部才能使用

#### 静态变量

**php中静态变量并不能再全局使用**

**C中静态变量可以在全局使用**

static关键字定义静态变量

静态变量出作用域不会销毁，也不能被改变

```
static $a = 123;
```

错误示范

```php
function test3()
{
    static $jing = 123;
    echo $jing;//true
}
test3();

echo $jing;//error
```

静态变量不能再函数内使用

```php
static $jing = 123;
function test3()
{
    echo $jing;//error
}
test3();
```

静态变量不能用globa声明成全局的

```php
static $jing = 123;
function test3()
{
    globa $jing;//error
    echo $jing;
}
test3();
```

C中可以

```c

	static a = 10;
	
	for (int i = 0; i <= 5; i++)
	{
		printf("%d\n", a);
	}
```



#### 引用&

`$b = &$a;` `$b`就是`$a`的别名

##### 引用传参

与C++的引用传参一样

```php
function test4(&$a)
{
    $a++;
}
$b = 1;
test4($b);
echo $b;//2
```



### 常量

#### 定义关键字

单双引号都行，变量名一般大写，不能重复，后面是内容

```
define('常量名称','内容');
define('常量名称','内容');

define('MY_NAME1','name1');
echo '<br/>';
define("MY_NAME2","name2");
echo MY_NAME1,"<br/>",MY_NAME2;
输出：
	name1
	name2
```

#### 预定义常量

**预定义常量使用的时候不区分大小写**

php规范定义了一些常量

例如：

```
__FUNCTION__
```

##### 魔术常量

**有九个魔术常量它们的值随着它们在代码中的位置改变而改变**

https://www.php.net/manual/zh/language.constants.magic.php

| 名字                   | 说明                                                         |
| :--------------------- | :----------------------------------------------------------- |
| **`__LINE__`**         | 文件中的当前行号。                                           |
| **`__FILE__`**         | 文件的完整路径和文件名。如果用在被包含文件中，则返回被包含的文件名。 |
| **`__DIR__`**          | 文件所在的目录。如果用在被包括文件中，则返回被包括的文件所在的目录。它等价于 `dirname(__FILE__)`。除非是根目录，否则目录中名不包括末尾的斜杠。 |
| **`__FUNCTION__`**     | 当前函数的名称。匿名函数则为 `{closure}`。                   |
| **`__CLASS__`**        | 当前类的名称。类名包括其被声明的作用域（例如 `Foo\Bar`）。当用在 trait 方法中时，__CLASS__ 是调用 trait 方法的类的名字。 |
| **`__TRAIT__`**        | Trait 的名字。Trait 名包括其被声明的作用域（例如 `Foo\Bar`）。 |
| **`__METHOD__`**       | 类的方法名。                                                 |
| **`__NAMESPACE__`**    | 当前命名空间的名称。                                         |
| **`ClassName::class`** | 完整的类名。                                                 |

##### 使用一下

```php
echo __file__;echo '<br/>';
echo __FILE__;echo '<br/>';
echo __line__;echo '<br/>';
echo __LINE__;echo '<br/>';

输出：
D:\phpStudy\WWW\myphp\index.php
D:\phpStudy\WWW\myphp\index.php
133
134
```



### 区别

1. 常量前面没有$
2. 常量只能用define()函数定义
3. 作用域在全局
4. 定义后不能变
5. 常量的值之能是 bool，int，float，string类型

## 运算符

### 算数运算符

`+` `-` `*` `/` `%` `++` `--`

| 列句      | 名称   | 结果               |
| --------- | ------ | ------------------ |
| `-$a`     | 取反   | $a的负值           |
| `$a + $b` | 加     | 和                 |
| `$a - $b` | 减     | 差/商              |
| `$a * $b` | 乘     | 乘积               |
| `$a / $b` | 除     | 获取商，会保留小数 |
| `$a % $b` | 取模   | 获取余数           |
| `++$a`    | 前置++ | 先加加，后使用     |
| `$a++`    | 后置++ | 先使用，后加加     |
| `--$a`    | 前置-- | 先减减，后使用     |
| `$a--`    | 后置-- | 先使用，后减减     |

#### 后置++ 演示

```php
$sum = 10;
echo ++$sum;//11
echo $sum;//11

echo '<br/>';

$sum2 = 10;
echo $sum2++;//10
echo $sum;//11
```

### 字符串运算符

`.`连接运算符

```php
$str1 = "你好";
$str2 = "世界";
echo $str1.$str2;
echo '<br/>';
echo $str1."PHP";
输出：
你好世界
你好PHP
```

### 负值运算符

`=` `+=` `-=` `*=` `/=` `%=` `.=`

说一下`.=`主要用于链接字符串

```php
$str1 = "你好";
$str2 = "世界";
$str1 .= $str2;//你好世界
$str1 += $str2;//0

$str1 = 2;
$str2 = 3;
$str1 .= $str2;//23

$str1 = 2;
$str2 = 3;
$str1 += $str2;//5
```

结论：
    .=用于字符串相加
    .=加**整数**时 会将整数看成 **字符串**

### 比较运算符

等于：`==`

全等： `===`

不等于： `!=` `<>`    (两个符号都是!=的意思)

不全等：`!==` （判断类型和内容，`$a = 11`，`$b = '11'`，也就是a不全等于b，成立

小于：`<`

小于等于：`<=`

大于：`>`

大于等于：`>=`

```php
`===`
值相等，类型也要相等
$num1 = 11;
$num2 = '11';
var_dump((int)$num2);//int(11)
var_dump($num1 == $num2);//bool(true) 自动转换类型，把$num2的字符串转换成了整数
var_dump($num1 === $num2);//bool(false)
```

### 逻辑运算符

与：and 、&&

或：or 、||

非：!

异或：xor (规则 左右不一样就是true)

逻辑运算符有截断（短路）的情况！

例如 a || b   a成立 b则不执行

例如a && b  a不成立 b也不执行

| 例子       | 名称            | 结果                                                      |
| :--------- | :-------------- | :-------------------------------------------------------- |
| $a and $b  | And（逻辑与）   | **`true`**，如果 $a 和 $b 都为 **`true`**。               |
| $a or $b   | Or（逻辑或）    | **`true`**，如果 $a 或 $b 任一为 **`true`**。             |
| $a xor $b  | Xor（逻辑异或） | **`true`**，如果 $a 或 $b 任一为 **`true`**，但不同时是。 |
| ! $a       | Not（逻辑非）   | **`true`**，如果 $a 不为 **`true`**。                     |
| `$a && $b` | And（逻辑与）   | **`true`**，如果 $a 和 $b 都为 **`true`**。               |
| $a || $b   | Or（逻辑或）    | **`true`**，如果 $a 或 $b 任一为 **`true`**。             |

### 位运算符

| 例子           | 名称                | 结果                                                     |
| :------------- | :------------------ | :------------------------------------------------------- |
| **`$a & $b`**  | And（按位与）       | 将把 $a 和 $b 中都为 1 的位设为 1。                      |
| **`$a | $b`**  | Or（按位或）        | 将把 $a 和 $b 中任何一个为 1 的位设为 1。                |
| **`$a ^ $b`**  | Xor（按位异或）     | 将把 $a 和 $b 中一个为 1 另一个为 0 的位设为 1。         |
| **`~ $a`**     | Not（按位取反）     | 将 $a 中为 0 的位设为 1，反之亦然。                      |
| **`$a << $b`** | Shift left（左移）  | 将 $a 中的位向左移动 $b 次（每一次移动都表示“乘以 2”）。 |
| **`$a >> $b`** | Shift right（右移） | 将 $a 中的位向右移动 $b 次（每一次移动都表示“除以 2”）。 |

### 其他运算符

#### 三元运算符：`？:`

```php
表达式1 ？ 表达式2 ： 表达式3
1成立执行2 ，不成立执行3
```

#### ``

 可以放系统命令 ，涉及到跨平台

```
$str = `ipconfig`;
var_dump($str);

输出：

string(802) " Windows IP 配置 以太网适配器 以太网: 媒体状态 . . . . . . . . . . . . : 媒体已断开连接 连接特定的 DNS 后缀 . . . . . . . : 无线局域网适配器 本地连接* 1: 媒体状态 . . . . . . . . . . . . : 媒体已断开连接 连接特定的 DNS 后缀 . . . . . . . : 无线局域网适配器 本地连接* 2: 媒体状态 . . . . . . . . . . . . : 媒体已断开连接 连接特定的 DNS 后缀 . . . . . . . : 无线局域网适配器 WLAN: 连接特定的 DNS 后缀 . . . . . . . : 本地链接 IPv6 地址. . . . . . . . : fe80::8538:d7f6:846f:8103%20 IPv4 地址 . . . . . . . . . . . . : 192.168.31.198 子网掩码 . . . . . . . . . . . . : 255.255.255.0 默认网关. . . . . . . . . . . . . : 192.168.31.1 以太网适配器 蓝牙网络连接: 媒体状态 . . . . . . . . . . . . : 媒体已断开连接 连接特定的 DNS 后缀 . . . . . . . : "
```

#### 屏蔽错误@

当这个代码出错时，屏蔽掉错误，什么也不打印

```php
打印一个没有的变量
echo @$a;
输出：
    Notice: Undefined variable: a in D:\phpStudy\WWW\myphp\index.php on line 2

echo @$xxx;
echo @$xxx;
输出：
    啥也不输出
```

#### =>

#### ->

#### instanceof

### 运算符的优先级





## 类型

### bool

### int

### float

### string



### 整体输出

```php
//类型
$a1 = true;
$b1 = false;
$a2 = 123;
$a3 = 123.123;
$a4 = 'holle world';
echo '<br/>';
echo 'a1是：',$a1,' 类型是：',var_dump($a1),'<br/>';
echo 'a2是：',$a2,' 类型是：',var_dump($a2),'<br/>';
echo 'a3是：',$a3,' 类型是：',var_dump($a3),'<br/>';
echo 'a4是：',$a4,' 类型是：',var_dump($a4),'<br/>';
echo 'b1是：',$b1,' 类型是：',var_dump($b1),'<br/>';

输出：
a1是： 类型是：bool(true)
a2是：123 类型是：int(123)
a3是：123.123 类型是：float(123.123)
a4是：holle world 类型是：string(11) "holle world"
b1是： 类型是：bool(false)
```

### 数组array



### 对象object



### 资源resource



### NULL



### 强转类型

```php
$aa10 = (int)'ada';
var_dump($aa10);
var_dump((float)$aa10);
$bb10 = (int)$aa10;
var_dump($aa10);
输出：
int(0) float(0) int(0)
```

字符串转整形

```php
$num = '11';
var_dump((int)$num);//int(11)
```

## 流程控制

### 判断语句

#### if语句

与C/C++同理

不带括号只执行if后一条语句

```php
if(表达式) 执行语句；
-----------------------
if(表达式) 
	执行语句；
else
	执行语句；
-----------------------
if(表达式) 
	执行语句；
else if(表达式)
	执行语句；
```



#### switch

不带break 会继续执行后面的case

case后没有语句，直接执行后面的

```php
switch(表达式){
	case 1：
		语句块1;
		break;
	case 2:
		语句块2;
		break;
	......
	default:
		语句块n;	
}
```



### 循环语句

#### for

```php
for(表达式1;表达式2;表达式3)
{
	语句块;
}
表达式1：初始化，可以多个
表达式2：逻辑判断，可以多个
表达式3：加减语句，可以多个

```



#### while

```php
while(表达式)
{
	语句;
}
```



#### do...while

```php
do
{
	语句;
}while(表达式);
```

### 特殊的控制语句

#### break

跳出当前所在循环语句

break后面可以跟数字，表示跳出第几层，默认是1**（C语言不支持）**

php支持break跳出多层

```php
for($i = 0;$i<5;$i++)
{
    echo "\$i执行到了第{$i}遍啦啦啦啦啦<br />";
    for($j = 0;$j<5;$j++)
    {
        if($i == 2)
            break 2;
        echo "\$j执行到了第{$j}遍<br />";
    }
}
```

C语言break跟数字会报错

```c
int main()
{
	for (int i = 0; i <= 5; i++)
	{
		printf("%d打印到了%d层lalalaalalala\n", i, i);
		for (int j = 0; j <= 5; j++)
		{
			if (j == 2)
				break 2;
			printf("%d打印到了%d层\n", i, i);
		}
	}
	return 0;
}
```

#### contine

跳过本次循环后的语句

#### exit()

退出程序

```php
//可以直接写
exit;
//可以跟输出语句
exit('程序退出啦');
```

#### die()

与exit()一样

## 函数

### 格式

```php
function 函数名（参数...）
{
	函数体
	return 表达式; 可以返回 也可以不返回，不写默认返回null
}
```

### 关键字是：**function**

```php
function test()
{
    echo '你好';
}
test();
```

### 传参

```php
function test($a,$b)
{
    echo $a+$b;
}
test(1,2);
```

#### 引用传参

与C++的引用传参一样

```php
function test4(&$a)
{
    $a++;
}
$b = 1;
test4($b);
echo $b;//2
```

#### 参数默认值

**默认参数从右往左加**

```php
function test5($a = 222)
{
    echo $a;//222
}
test5();
```

#### 可变传参

##### func_get_args();

以**数组**的形式获取参数

返回值是数组

```php
function test6()
{
    $arr = func_get_args();
    var_dump(func_get_args());
    //array(7) { [0]=> int(1) [1]=> int(2) [2]=> int(3) [3]=> int(4) [4]=> int(5) [5]=> int(6) [6]=> string(4) "ssss" }
    var_dump($arr);
    //array(7) { [0]=> int(1) [1]=> int(2) [2]=> int(3) [3]=> int(4) [4]=> int(5) [5]=> int(6) [6]=> string(4) "ssss" }
}
test6(1,2,3,4,5,6,'ssss');

```

##### func_get_arg();

以数**组的下标**形式获取参数

```php
function test6()
{
    var_dump(func_get_arg(6));
    //string(4) "ssss"
}
test6(1,2,3,4,5,6,'ssss');
```

##### func_num_args();

返回传入参数的个数

```php
function test6()
{
    var_dump(func_num_args());// int(7)
}
test6(1,2,3,4,5,6,'ssss');
```

### 可变函数

**把函数赋值给变量**

也就是说a变量成了 test6()  直接可以当函数用

**这是test6的别名？**

```
function test6()
{
    var_dump(func_num_args());//
}
$a = 'test6';
$a(1,2,3,4,5,6,'ssss');
```

### 递归函数

```
{
    echo $n.' ';
    if($n > 0)
        test($n-1);
    else
        echo '<-->';
    echo $n,' ';
}
test(3);//3 2 1 0 <-->0 1 2 3

```



### 返回值

```php
function test($a,$b)
{
    $c =  $a+$b;
    return $c; 
}
$d = test(1,2);

echo "\$d等于",$d;
```

## 数组

不写下标直默认0开始

可以写键值对



```php

//方式一
$struct[0] = 20;
$struct[1] = '张三';
$struct[2] = '男';
$struct[3] = '70.5kg';
print_r($struct);

$struct[] = 20;
$struct[] = '张三';
$struct[] = '男';
$struct[] = '70.5kg';
print_r($struct);

var_dump($struct);
//方式二
$struct[] = 20;
$struct[] = '张三';
$struct[] = '男';
$struct[] = '70.5kg';

//方式三
$struct[0] = array(20,'张三','娜娜');
$struct[0] =  20,'张三','娜娜';

//方式四
$struct[0] = array('年龄'=>20,'name'=>'张三');
echo '<br />';

echo $struct['name'];//20
//方式五
$struct['num'] = 20;
$struct['name'] = '张三';
$struct['sex'] = '男';
echo '<br />';

echo $struct['num'];//20
echo $struct[1];//张三
```

## 数组的函数

- [array_count_values](https://www.php.net/manual/zh/function.array-count-values.php) — 统计数组中所有的值

返回值是一个数组

```php
<?php
$array = array(1, "hello", 1, "world", "hello");
print_r(array_count_values($array));
?>
```

![image-20230506145452393](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimageimage-20230506145452393.png)

- [array_key_exists](https://www.php.net/manual/zh/function.array-key-exists.php) — 检查数组里是否有指定的键名或索引

array_key_exists(string|int `$key`, array `$array`): bool

成功时返回 **`true`**， 或者在失败时返回 **`false`**。

```
$array = array(1, "hello", 1, "world", "hello");
//print_r(array_count_values($array));
var_dump(array_key_exists("zhangsan",$array));
var_dump(array_key_exists("hello",$array));
```

![image-20230506150229466](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20230506150229466.png)

- [array_search](https://www.php.net/manual/zh/function.array-search.php) — 在数组中搜索给定的值，如果成功则返回首个相应的键名

  array_search([mixed](https://www.php.net/manual/zh/language.types.declarations.php#language.types.declarations.mixed) `$needle`, array `$haystack`, bool `$strict` = **`false`**):

  (值，所在数组，判断类型（true）)

  写true就是要判断所找到的值的类型是否相等

```php
<?php
$array = array('name'=> "zhangsan",'sex' => "男");

var_dump(array_search("name",$array));//false
var_dump(array_search("zhangsan",$array));//true 返回key的值
var_dump(array_search("hello",$array));//false
```

![image-20230506152536417](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20230506152536417.png)

## 预定义超全局数组变量

### 说明

PHP 中的许多预定义变量都是“超全局的”，这意味着它们在一个脚本的全部作用域中都可用。在函数或方法中无需执行 **global $variable;** 就可以访问它们。

### 变量是

- [$GLOBALS](https://www.php.net/manual/zh/reserved.variables.globals.php)

- [$_SERVER](https://www.php.net/manual/zh/reserved.variables.server.php)
- [$_GET](https://www.php.net/manual/zh/reserved.variables.get.php)

传递数据

- [$_POST](https://www.php.net/manual/zh/reserved.variables.post.php) 

传递数据

- [$_FILES](https://www.php.net/manual/zh/reserved.variables.files.php)
- [$_COOKIE](https://www.php.net/manual/zh/reserved.variables.cookies.php)
- [$_SESSION](https://www.php.net/manual/zh/reserved.variables.session.php)
- [$_REQUEST](https://www.php.net/manual/zh/reserved.variables.request.php)
- [$_ENV](https://www.php.net/manual/zh/reserved.variables.environment.php)







## 关键字

### 输出echo

输出变量：`echo $a;`

多种输出：`echo 'abc','<br/>',123,$a;`



### 输出类型var_dump

```php
$a = 123;
var_dump($a);
输出int
```

### 转义字符\

```php
echo '单引号：\' , 斜杠\\';
输出：
    单引号：'，双引号："，斜杠\,
```

### 引号"" ''

#### 单引号''

不会直接解析 变量，双引号会

```php
$a2 = 123;
echo '$a2';
echo "$a2";
输出：
$a2
123
```

另一种方式给变量加`{}`

```php
echo "这是：$a2","这是：{$a2}";
echo '<br/>';
echo '这是：$a2','这是：{$a2}';
echo '<br/>';
输出：
这是：123这是：123
这是：$a2这是：{$a2}
```



#### 双引号""

单引号双引号 可以嵌套

#### 嵌套

引号可以互相嵌套

```php
echo '她说："你是好人"';
输出：
她说："你是好人"
```

### 定界符<<<

格式：name之能是字母，数字，下划线

```php
<<<name
content（内容）
name；
```



```
$delimiter=<<<aaa
hello world！ 21212_{$a2}_32121"""'''''\
aaa;
echo '<br/>';

var_dump($delimiter);
```

### 销毁变量unset()

```php
$a = 123;
unset($a);
此时$a就是null
```

### 定义函数function

```php
function test()
{
    echo '你好';
}
test();
```

### 全局变量globa

声明$xxa为全局变量，只能在当前作用域声明

```php
$xxa = 10;
define('XXA',10);
function test2()
{
    global $xxa;//声明$xxa为全局变量，只能在当前作用域声明
    echo $xxa;
    echo XXA;
}
test2();
```

### 数组个数count()

返回数组实际个数

```php
//方式一
$struct[0] = 20;
$struct[1] = '张三';
$struct[2] = '男';
$struct[3] = '70.5kg';
print_r($struct);
echo '<br />';

echo count($struct);//4
echo '<br />';

```

## 传递数据

### 1.get方式

例如：

```
http://localhost/myphp/index.php
http://localhost/myphp/index.php?name='zhangsan'&id=520

```

![image-20230506141709688](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20230506141709688.png)

### 2.post 方式

代码

```php
<?php
var_dump($_POST);
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset = "utf-8" />
    <title>预定义超全局数据变量</title>
</head>
<body>
    <form method="post">
        姓名:<input type="text" name='username' /><br />
        性别:<input type="text" name='sex' /><br />
        <input type="submit" value='提交' />
    </form>
</body>
</html>
```

#### 运行

![image-20230506142954425](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20230506142954425.png)

#### 填入信息

![image-20230506143019323](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimageimage-20230506143019323.png)

#### 提交

![image-20230506143045080](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20230506143045080.png)

### 将以上代码改成get方式

会将表单中填写的数据放在URL地址中

#### 改代码

![image-20230506143548289](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20230506143548289.png)

```php
<?php
//var_dump($_POST);
var_dump($_GET);
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset = "utf-8" />
    <title>预定义超全局数据变量</title>
</head>
<body>
    <form method="get">//get
        姓名:<input type="text" name='username' /><br />
        性别:<input type="text" name='sex' /><br />
        <input type="submit" value='提交' />
    </form>
</body>
</html>
```

#### 填写+运行

![image-20230506143636103](https://picgo-1311604203.cos.ap-beijing.myqcloud.com/imageimage-20230506143636103.png)
