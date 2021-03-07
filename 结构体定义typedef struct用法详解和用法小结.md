# 结构体定义 typedef struct 用法详解和用法小结
@[toc]
### 0. 前言
- `typedef`是类型定义的意思。
- `typedef struct` 是为了使用这个结构体方便。

具体区别在于:
- 若`struct node {}`这样来定义结构体的话。在申请`node`的变量时，需要这样写，`struct node n;`
- 若用`typedef`，可以这样写，`typedef struct node{}NODE;` 。在申请变量时就可以这样写，`NODE n;`

**区别就在于使用时，是否可以省去struct这个关键字。**
 

分三块来讲述：

### 1. 首先：在C中定义一个结构体类型要用typedef:
```c
typedef struct Student
{
    int a;
}Stu;
```

于是在声明变量的时候就可：
```c
Stu stu1;
```

如果没有`typedef`就必须用`struct Student stu1;`来声明

这里的`Stu`实际上就是`struct Student`的别名。

另外这里也可以不写`Student`（于是也不能`struct Student stu1;`了）
```c
typedef struct
{
    int a;
}Stu;
```

但在c++里很简单，直接
```c
struct Student
{
    int a;
};
```
于是就定义了结构体类型`Student`，声明变量时直接`Student stu2`；

即标准形式：

- 先定义后声明
```c
//定义结构体
struct teacher{
    char name[20];
    int age;
    char email[50];
};
//声明结构体变量
struct teacher teacher1;
```

- 定义的同时进行声明

```c
//定义时声明变量
struct teacher{
    char name[20];
    int age;
    char email[50];
}teacher1, teacher2;
```

- 使用`typedef`定义结构体
```c
//定义结构体
typedef struct Student
{
    char name[50];
    int age;
}Stu;
//声明结构体变量
Stu stu1;
```

- 直接(不使用Student)

```c
//定义结构体
typedef struct
{
    int a;
}Stu;
//声明结构体变量
Stu stu1;
```



----------------------------

### 2. 其次：在c++中如果用typedef的话，又会造成区别：

```c
struct Student
{
    int a;
}stu1;//stu1是一个变量
typedef struct Student2
{
    int a;
}stu2;//stu2是一个结构体类型
```

使用时可以直接访问`stu1.a`，但是`stu2`则必须先 `stu2 s2;`，然后 `s2.a=10;`

### 3. 掌握上面两条就可以了，不过最后我们探讨个没多大关系的问题
如果在c程序中我们写：
```c
typedef struct
{
    int num;
    int age;
}aaa,bbb,ccc;
```
这算什么呢？
我个人观察编译器（VC6）的理解，这相当于
```c
typedef struct
{
    int num;
    int age;
}aaa；
    typedef aaa bbb;
    typedef aaa ccc;
```
也就是说`aaa`,`bbb`,`ccc`三者都是**结构体类型**。

声明变量时用任何一个都可以,在c\++中也是如此。但是你要注意的是这个在c++中如果写掉了`typedef`关键字，那么`aaa`，`bbb`，`ccc`将是截然不同的三个对象。

### 4. C/C++中typedef struct和struct的用法

```c
struct _x1 {
    ...
} x1;
```
定义了结构体类型`_x1`和`_x1`的对象实例`x1`
```c
typedef struct _x2{
    ...
} x2;
```
定义了结构体类型`_x2`和`_x2`的类别名`x2`

所以它们在使用过程中是有区别的。

----

**[知识点]**

结构也是一种数据类型, 可以使用结构变量, 因此, 象其它 类型的变量一样, 在使用结构变量时要先对其定义。

定义结构变量的一般格式为:
```
struct 结构名
{
    类型 变量名;
    类型 变量名;
    ...
} 结构变量;
```
结构名是结构的标识符不是变量名。

另一种常用格式为:
```c
typedef struct 结构名
{
    类型 变量名;
    类型 变量名;
    ...

} 结构别名;
```
另外注意: 在C中，`struct`不能包含函数。在C++中，对`struct`进行了扩展，可以包含函数。

-----------------------

实例1: struct.cpp
```c
#include <iostream>
using namespace std;

typedef struct _point{
    int x;
    int y;
}point; //定义类，给类一个别名

struct _hello{
    int x,y;
} hello; //同时定义类和对象

int main()
{
    point pt1;
    pt1.x = 2;
    pt1.y = 5;

    cout<< "ptpt1.x=" << pt1.x << "pt.y=" <<pt1.y <<endl;

//  hello pt2;
//  pt2.x = 8;
//  pt2.y =10;
//  cout<<"pt2pt2.x="<< pt2.x <<"pt2.y="<<pt2.y <<endl;
//  上面的hello pt2;这一行编译将不能通过. 为什么?
//  因为hello是被定义了的对象实例了.

//正确做法如下: 用hello.x和hello.y

    hello.x = 8;
    hello.y = 10;

    cout<< "hellohello.x=" << hello.x << "hello.y=" <<hello.y <<endl;
    
    return 0;
}
```

### 5. 问答

**Q**： 用`struct`和`typedef struct`定义一个结构体有什么区别？为什么会有两种方式呢？
```c
//定义结构体Student时，声明了结构体变量stu
struct Student
{
    int a;
} stu;

//结构体类型Student2的别名为stu2
typedef struct Student2
{
    int a;
}stu2;
```

**A**：事实上，这个东西是从C语言中遗留过来的，`typedef`可以定义新的复合类型或给现有类型起一个别名，在C语言中，如果你使用
```c
struct xxx
{
    ...
};
```
的方法，使用时就必须用 `struct xxx var;` 来声明变量，而使用
```c
typedef struct
{
}xxx;
```
的方法 就可以写为 `xxx var;`

不过在C++中已经没有这回事了，无论你用哪一种写法都可以使用第二种方式声明变量，这个应该算是C语言的糟粕。

### 6. 用法小结

- 用途一：

定义一种类型的别名，而不只是简单的宏替换。可以用作同时声明指针型的多个对象。比如：
```c
char* pa, pb; // 这多数不符合我们的意图，它只声明了一个指向字符变量的指针，和一个字符变量；
```
以下则可行：
```c
typedef char* PCHAR; // 一般用大写
PCHAR pa, pb; // 可行，同时声明了两个指向字符变量的指针
```
虽然：
```c
char *pa, *pb;
```
也可行，但相对来说没有用`typedef`的形式直观，尤其在需要大量指针的地方，`typedef`的方式更省事。

- 用途二：

用在旧的C的代码中（具体多旧没有查），帮助`struct`。以前的代码中，声明`struct`新对象时，必须要带上`struct`，即形式为： `struct 结构名 对象名`，如：
```c
struct tagPOINT1
{
    int x;
    int y;
};
struct tagPOINT1 p1;
```
而在C++中，则可以直接写：结构名 对象名，即：
```cpp
tagPOINT1 p1;
```

估计某人觉得经常多写一个struct太麻烦了，于是就发明了：
```c
typedef struct tagPOINT
{
    int x;
    int y;
}POINT;

POINT p1; // 这样就比原来的方式少写了一个struct，比较省事，尤其在大量使用的时候
```

或许，在C++中，`typedef`的这种用途二不是很大，但是理解了它，对掌握以前的旧代码还是有帮助的，毕竟我们在项目中有可能会遇到较早些年代遗留下来的代码。 