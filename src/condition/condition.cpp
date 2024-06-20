#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <cerrno>
#include <iostream>

#define COLOR_HEAD  "\033["
#define RED_CHAR    "31"
#define BLUE_CHAR   "34"
#define GREEN_CHAR  "32"
#define YELLOW_CHAR "33"
#define YELLOW_BACK "43"
#define RED_BACK    "41"
#define RESET       "0m"

// 定义互斥量和条件变量
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void calculate_next_tick(struct timespec *ts, long tick_ms) {
    // 设置下次tick的绝对超时时间
    clock_gettime(CLOCK_REALTIME, ts);
    ts->tv_nsec += tick_ms * 1000000L;   // 假设tick_ms是毫秒
    while(ts->tv_nsec >= 1000000000L) {
        ts->tv_sec += 1;
        ts->tv_nsec -= 1000000000L;
    }
}

// 主线程的时间轮工作函数
void *timing_wheel_thread_func(void *arg) {
    long next_tick_ms = 500;  // 初始假设下一个tick是在64ms后

    while (1) {
        struct timespec ts;
        calculate_next_tick(&ts, next_tick_ms);

        pthread_mutex_lock(&mutex);
        int rc = pthread_cond_timedwait(&cond, &mutex, &ts);
        if (rc == ETIMEDOUT) {
            std::cout << COLOR_HEAD << RED_BACK << ";" << YELLOW_CHAR << "m" << "tick: 定时器触发了。" << COLOR_HEAD << RESET << std::endl;
        } else {
            std::cout << COLOR_HEAD << BLUE_CHAR << "m" << "tick: 新的timer被创建，提前唤醒。" << COLOR_HEAD << RESET << std::endl;
        }
        pthread_mutex_unlock(&mutex);

        // 执行定时轮检查和tick的工作
        // 更新 next_tick_ms 为下一个最近的定时器时间或64ms，取决于系统的状态和新timer
        
        // ... 处理定时轮 ...
        std::cout << COLOR_HEAD << RED_CHAR << "m" << "tick: timer called" << COLOR_HEAD << RESET << std::endl;
    }

    return NULL;
}

// 触发定时器创建的函数
void *create_timer_thread_func(void *arg) {
    while (1) {
        // 在这里创建一个新的timer
        // ...

        pthread_mutex_lock(&mutex);
        pthread_cond_signal(&cond);  // 唤醒定时轮，表明新的timer被添加
        pthread_mutex_unlock(&mutex);
        std::cout << COLOR_HEAD << YELLOW_BACK << ";" << GREEN_CHAR << "m" << "timer: 创建了新的timer。" << COLOR_HEAD << RESET <<std::endl;
        sleep(1); // 仅为了示例
    }

    return NULL;
}

int main() {
    pthread_t timing_wheel, timer_creator;

    // 创建线程
    pthread_create(&timing_wheel, NULL, timing_wheel_thread_func, NULL);
    pthread_create(&timer_creator, NULL, create_timer_thread_func, NULL);

    // 等待线程完成
    pthread_join(timing_wheel, NULL);
    pthread_join(timer_creator, NULL);

    // 清理
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}