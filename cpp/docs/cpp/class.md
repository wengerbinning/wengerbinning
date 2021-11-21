类是根据使用场景将一类对象进行抽象的一种自定义的抽象数据类型，是C++面向对象编程的核心，是继承与多态的基础。类的定义使用class来标识。

  ```c++
  class <class name> {
    <purview>:
		<member>;
	...
  };
  ```

> Note：在类的定义中存在三类权限，缺省为private权限；并且权限区块可以声明多个，每一权限区块可以声明数据成员与函数成员。在声明结束后必须以;结束，是因为在类的定义之后还可以有一个对象定义列表，一般为空。

数据成员是描述类的数据特征，一般设定为私有成员；通过接口来管理数据，不支持本身类型、寄存器、外部、constexpr与decltype的成员；C++11之后，在类中中可以指定类内初始值。在类中，常量成员、引用成员、类对象成员以及派生类的构造函数对超类构造函数的调用必须采用类内初始值或者构造函数的初始化列表来进行初始化。一般使用初始化列表初始化数据成员。

* 可变数据成员：可变数据成员不经常使用。可变数据成员可以在常量函数中改变、对象为常量时也可以被改变，使用`mutable`来声明。

  ```c++
  class Human {
    private:
      mutable string name;
    public：
      void Print() const;
  }

  void Human::Print() const {
    cout << this.name;
    this->name = "NULL";
  }
  
  ```



类的函数成员即类的行为特征，本质是函数，一般设定为公开成员，作为ADT的外部接口；可以在类内直接实现；也可以在类内声明，类外实现。在方程成员中，
有一个默认参数this指针。

 类的静态成员

静态成员是独立于任意该类型对象而存在的，所有实例化对象共享；是实现类间内存共享的机制。静态函数只能访问静态数据成员，使用static修饰。

* 静态数据成员：不能通过构造函数初始化，只能在定义时指定初始值。

  ```C++
  class Human {
    private:
      string name;
      static int COUNT;
      static initCount();
  }

  int Human::COUNT = initCount();     // 使用静态函数initCount()来初始化COUNT。
  ```

  在静态数据成员中，有一种特殊的静态数据成员：静态常量成员`const static int DAY;`

* 静态函数成员：没有this指针，可以直接访问静态数据成员，但不能直接访问非静态数据成员。不能被声明为常量函数于虚拟函数。

  ```c++
  class Human {
    private:
      string name;
      static int COUNT;
    public:
      static int Count();
  }

  int Count() {
    cout<< COUNT;
    return COUNT;
  }
  
  ```

  > Note：static仅在函数声明时出现，在函数实现时不出现。

类的常量成员时类所具有的

* 类的常量数据成员：只能在构造函数的初始化列表中初始化。

* 类的常量函数成员：

类的函数成员是对数据成员进行处理的函数，因为默认会带一个本身的this指针，所以称为这类函数为方法，用以描述类的行为。在这些函数中有一些特殊的函数需要了解。

## 构造函数

构造函数是

构造函数是使用该类型声明对象时自动调用，用以构造对象的函数。每一个类中可以存在多个构造函数。并且构造函数的名称与类的名称相同。

```c++
class String {
	public:
		// 构造函数的声明。
		String(const char* str=0);
		String(const String& str_obj);
		String& operator=(const String& str_obj);
		~String();
	private:
		char *m_data;
};

// 构造函数的实现。
inline
String::String(const char *str=0) 
{
	if(str) {
		this->m_data = new char[strlen(str)+1];
		strcpy(this->m_data, str);
	}
	else {
		this->m_data =new char[1];
		*(this->m_data) ='\0';
	}
}

```

构造函数的初始化列表是构造函数特有的；相较于函数体类初始化，该方式初始化更加快速。

```c++
class Complex {
	public:
		// 构造函数的声明。
		Complex(double, double);
		Complex& operator+=(const Complex&); 
		double real() const { return this->re; }
		double imag() const { return this->im; }
		
	private:
		double re, im;
		
		Complex& __doapl(const Complex&);
}

// 构造函数的初始化列表。
inline
Complex:: Complex(double r=0, double i=0)
: re(r), im(i)
{}

```

* 拷贝构造函数(copy constructor)是使用已有的对象来初始化的同类型对象是调用的构造函数。此构造函数的参数是自身对象的引用，其他参数都有默认值。

```c++ 
class String {
    public:
        String(const char* str=0);
        // 拷贝构造函数的声明。
		String(const String& str_obj);
		String& operator=(const String& str_obj);
		~String();
	private:
		char *m_data;
};

// 拷贝构造函数的实现。
inline
String::String(const String& str_obj)
{
	this->m_data = new char[strlen(str_obj.m_data)+1];
	strcpy(this->m_data, str_obj.m_data);
}
```

拷贝是将已有的对象通过赋值符号赋值给另一个同一类型的对象。目标对象已有内容需要先删除后在将原对象深拷贝一份给目标对象。

```c++
class String {
	public:
		String(const char* str=0);
		String(const String& str_obj);
		// 拷贝复制函数的声明。
		String& operator=(const String& str_obj);
		~String();
	private:
		char *m_data;
};

// 拷贝复制函数的实现。
inline
String& String::operator=(const String& str_obj) 
{
	if( this == &str_obj ) {
		return *this;
	}
	
	delete[] this->m_data;
	this->m_data = new char[strlen(str_obj.m_data)+1];
	strcpy(this->m_data, str_obj.m_data);
	return *this;
}

```

* 移动构造函数(move constructor) 


## 运算符操作
## 析构函数 


* 析构函数是在对象销毁时自动调用的函数，通常用于销毁指针成员。每一类中只能有一个析构函数。

```c++
class String {
	public:
		String(const char* str=0);
		String(const String& str_obj);
		String& operator=(const String& str_obj);
		// 析构函数的声明。
		~String();
	private:
		char *m_data;
};

// 析构函数的实现。
inline
String:~String(){
	delete[] m_data;
}

```


----

除了以上的函数之外还有一些操作符重载。

* 加法赋值运算符重载	

```c++
class Complex {
	public:
		Complex(double, double);
		// 加法赋值运算符重载声明。
		Complex& operator+=(const Complex&); 
		double real() const { return this->re; }
		double imag() const { return this->im; }
		
	private:
		double re, im;
		
		Complex& __doapl(const Complex&);
}

inline Conplex&
Complex::__doapl(const Complex&)
{

}

// 加法赋值运算符重载实现。
inline Complex& 
Complex::operator+=(const Conplex&)
{
	
}

```
