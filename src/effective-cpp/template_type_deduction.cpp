#include <iostream>
#include <typeinfo>

template<typename T>
void f(T& param) {
    std::cout << typeid(T).name() << std::endl;
}

template<typename T>
void fc(const T& param){
    std::cout << typeid(T).name() << std::endl;
}         //param现在是reference-to-const

template<typename T>
void fp(T* param){
    std::cout << typeid(T).name() << std::endl;
}               //param现在是指针

template<typename T>
void fgr(T&& param){
    std::cout << typeid(T).name() << std::endl;
}              //param现在是一个通用引用类型

template<typename T>
void fv(T param) {
    std::cout << typeid(T).name() << std::endl;
    T locals = param;
}                //以传值的方式处理param

int main() {
    int x=27;                       //x是int
    const int cx=x;                 //cx是const int
    const int& rx=x;                //rx是指向作为const int的x的引用
    f(x);                           //T是int，param的类型是int&
    f(cx);                          //T是const int，param的类型是const int&
    f(rx);                          //T是const int，param的类型是const int&

    fc(x);                           //T是int，param的类型是const int&
    fc(cx);                          //T是int，param的类型是const int&
    fc(rx);                          //T是int，param的类型是const int&

    const int *px = &x;             //px是指向作为const int的x的指针

    fp(&x);                          //T是int，param的类型是int*
    fp(px);                          //T是const int，param的类型是const int*

    //  ------- gdb
    // 基础的x命令的语法如下：
    // x/nfu addr
    // 其中参数的含义如下：
    // n 是要显示的元素数量。
    // f 是显示格式，例如 x（十六进制），d（十进制），u（无符号十进制），t（二进制），a（地址），i（机器指令），c（字符），等等。
    // u 是单位大小，例如 b（字节），h（半字，即两个字节），w（字，通常是四个字节），g（巨字，通常是八个字节）。
    // addr 是要检查的内存地址。
    // (gdb) x/10bx 0x6030b0
    //  ------- gdb

    fgr(x);                           //x是左值，所以T是int&，
                                    //param类型也是int&

    fgr(cx);                          //cx是左值，所以T是const int&，
                                    //param类型也是const int&

    fgr(rx);                          //rx是左值，所以T是const int&，
                                    //param类型也是const int&

    fgr(11);                          //27是右值，所以T是int，
                                    //param类型就是int&&

    fv(x);                           //T和param的类型都是int
    fv(cx);                          //T和param的类型都是int
    fv(rx);                          //T和param的类型都是int

    const char* const ptr =         //ptr是一个常量指针，指向常量对象 
        "Fun with pointers";

    fv(ptr);                         //传递const char * const类型的实参

    const char name[] = "J. P. Briggs";     //name的类型是const char[13]
    const char * ptrToName = name;          //数组退化为指针

    f(name);
    f(ptrToName);
}