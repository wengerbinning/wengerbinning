# 异常处理

异常处理机制允许程序在独立开发时能够对在运行时出现的问题进行通信并做出相应的处理，使得我们能够将问题的检测与解决过程分离。

* 异常对象(exception object)是一种特殊的对象，编译器使用异常抛出表达式来对对象进行拷贝初始化。异常对象位于由编译器管理的空间中。编译器确保无论最终调用的那个catch
子居都能访问该空间，当异常处理完成后，异常对象被销毁。

* 在C++中，我们通过抛出(throwing)一条表达式来引发(raised)一个异常，被抛出的表达式的类型以及当前的调用链共同决定了哪段处理代码(handler)来处理异常；
被选中的处理代码是在调用链中与抛出对象类型匹配的最近的处理代码。根据抛出对象的类型与内容，程序的抛出部分将告知处理代码发生了什么错误。当执行一个throw时，
程序暂停，并将程序的控制权转交给匹配的处理代码。

在抛出一个异常后，程序暂停执行，并立即寻找与异常匹配的catch子句，当throw出现在try语句块(try block)中，将检查与该try块关联的catch子句，如果找到则开始执行catch子句；
否则递归向上查找catch子句。如果在该函数中未找到，则退出当前函数，在调用当前函数中继续寻找；该过程称为栈展开(stack unwinding)。如果在整个调用链中未找到，则程序将调用
标准库中`terminate`来处理，即负责终止程序的执行。一个异常没有被捕获，则它将终止当前程序。

* 捕获异常通过catch子句(catch clause)来实现。catch子句中异常声明(exception declaration)看起来像只包含一个形参的函数形参列表，声明的类型决定了处理代码能够捕获的
异常，但是该类型必须是完全类型。在catch子句中可以实现异常重新抛出。

* noexcept说明(noexcept specification)指明某个函数不会抛出异常








--------

编程的错误包含编译错误与运行错误。

常见的编译错误有语法错误(syntax error)、类型错误(type error)、声明错误(declaration error).

异常是指程序运行期间发生的不正常情况。C++将异常检测与异常处理分离开try用于检测异常，throw抛出异常、catch处理异常。通过这一机制提高
程序的可读性和可维护性。异常的处理分为异常抛出、异常检测与异常捕获三步。

* 标准异常类型:标准异常即编译器提供的标准异常述据类型，其基类是BasicException；在此基础上派生出FileSysException、Osexception、SecuriyExption。

## 异常抛出

c++使用`throw`来抛出异常，格式为`throw <errorType>`。其中errorType为异常类型，可以任何类型数据类型。

* `noexcept`说明该函数不会抛出异常。

  ```c++
  <returnType> <funcName>(<parList>) noexcept {
    <code>;
  }
  ```

## 异常检测

C++使用`try`来检测代码区间抛出的异常并交由异常捕获模块。

* 异常检测：

  ```c++
  try {
    <code>;             // 被检测的代码区间。
  }
  catch(<errorType> <error>) {
    <code>;
  }
  ```

## 异常捕获

C++使用`catch`来捕获try检测到的异常并处理异常；catch必须位于try之后；可以出现多个catch语句。

* 异常捕获：

  ```c++
  try {
    <code>;
  }
  catch(<errorType> <error>) {
    <code>;             // 异常处理区块。
  }
  ```

* 捕获所有异常：

  ```c++
  try {
    <code>;
  }
  catch(...) {
    <code>;
  }
  ```

* 异常多次抛出：

  ```c++
  try {
    <code>;
  }
  catch(...) {
    throw;      // 将捕获的异常向上抛出。
  }
  ```

## 异常类型

## 异常的应用

由于构造函数没有返回值，则需要使用抛出异常来告诉外部初始化失败。

* 使用异常处理类实例化时构造函数产生的异常：

  ```c++
  ```