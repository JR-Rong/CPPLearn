#include <iostream>

void someFunc(int a, double b) {
    double c = b;
}   //someFunc是一个函数，
                                //类型为void(int, double)

int main() {
    auto x = 27;                    //情景三（x既不是指针也不是引用）
    const auto cx = x;              //情景三（cx也一样）
    const auto & rx=cx;             //情景一（rx是非通用引用）

    auto&& uref1 = x;               //x是int左值，
                                //所以uref1类型为int&
    auto&& uref2 = cx;              //cx是const int左值，
                                    //所以uref2类型为const int&
    auto&& uref3 = 27;              //27是int右值，
                                    //所以uref3类型为int&&

    const char name[] =             //name的类型是const char[13]
        "R. N. Briggs";

    auto arr1 = name;               //arr1的类型是const char*
    auto& arr2 = name;              //arr2的类型是const char (&)[13]

    auto func1 = someFunc;          //func1的类型是void (*)(int, double)
    auto& func2 = someFunc;         //func2的类型是void (&)(int, double)

    auto x1 = 27;                   //类型是int，值是27
    auto x2(27);                    //同上
    auto x3 = { 27 };               //类型是std::initializer_list<int>，
                                    //值是{ 27 }
    auto x4{ 27 };                  //同上

    // auto x5 = { 1, 2, 3.0 };        //错误！无法推导std::initializer_list<T>中的T
    // 在c++14中，auto可以作为返回值
    // auto createInitList()
    // {
    //     return { 1, 2, 3 };         //错误！不能推导{ 1, 2, 3 }的类型
    // }
    //
    // std::vector<int> v;
    // …
    // auto resetV = 
    //     [&v](const auto& newValue){ v = newValue; };        //C++14
    // …
    // resetV({ 1, 2, 3 });            //错误！不能推导{ 1, 2, 3 }的类型

    return 0;
}