#ifndef LOG_HPP_
#define LOG_HPP_

#include <iostream>
#include <atomic>
#include <cstdio>

#define CONCAT(base, line) base##line
#define LOG_COUNTER_NAME CONCAT(log_n_, __LINE__)

#define LOGD(n, tag, fmt, ...)                      \
    thread_local static std::atomic<int> LOG_COUNTER_NAME(0);    \
    if(++LOG_COUNTER_NAME > n) LOG_COUNTER_NAME-=n; \
    if(LOG_COUNTER_NAME == 1) {                     \
        LogD(tag, fmt, __VA_ARGS__);              \
    }

template <typename ...Args>
inline void LogD(std::string tag, std::string fmt, Args &&...args) {
    printf("tag:[%s] ", tag.c_str());
    printf(fmt.c_str(), std::forward<Args>(args)...);
    // 在结尾添加换行符
    printf("\n");
}

// -- 为什么仅使用模板函数不会造成重复定义的问题？--
// 当你仅仅使用模板函数时，并不会直接在编译时创建函数的实例化定义。模板函数本身只是一个模板，直到它被具体类型的参数调用时才实例化。
// 这个实例化过程是在每个源文件（翻译单元）中独立进行的，如果多个源文件中使用了相同的模板实例，链接器会自动处理这些重复的实例化并保留其中一个。

// C++ 标准允许在不同的翻译单元中有相同的模板实例化定义，链接器负责合并这些定义。这就是为什么仅使用变参模板函数不会在链接时产生重复定义问题的原因。

// -- 为什么加上void print() {}就造成了重复定义？ --
// 与模板不同，普通函数的定义在编译时就需要明确存在。当你在头文件中定义一个非模板的函数，比如 void print() {}，并且这个头文件被多个源文件包含，
// 每个包含它的源文件都会得到这个函数的一个副本。链接时，链接器会发现每个编译单元都提供了这个函数的定义，导致“multiple definition”（多重定义）错误。

// -- 为什么声明为inline能解决这个问题？ --
// inline 关键字给函数的定义提供了一种特殊的指示，告诉编译器和链接器多个翻译单元中的同名函数定义实际上是相同的，可以被合并。这不仅适用于性能优化目的
// 的“内联”调用场景，还解决了多个源文件包含同一个头文件导致函数重复定义的问题。

// 当函数被声明为 inline，编译器会为每个翻译单元中的调用生成一个函数实例，链接器在最终的链接过程中，会识别这些相同的函数是内联函数，并只保留一个副本
// 用于最终的程序，解决了多重定义问题。

inline void print() {} 

template <typename T, typename ...Args>
void print(T&& str, Args&& ...args) {
    std::cout << std::forward<T>(str);
    print(std::forward<Args>(args)...);
}

#endif // LOG_HPP_