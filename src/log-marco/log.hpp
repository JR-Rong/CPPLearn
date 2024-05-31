#ifndef LOG_HPP_
#define LOG_HPP_
#include <iostream>
#include <atomic>
#include <cstdio>

#define CONCAT(base, line) base##line
#define LOG_COUNTER_NAME CONCAT(log_n_, __LINE__)

#define LOGD(n, tag, fmt, ...)                      \
    static std::atomic<int> LOG_COUNTER_NAME(0);    \
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

#endif // LOG_HPP_