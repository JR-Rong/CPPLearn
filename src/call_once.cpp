#include <mutex>
#include <thread>
#include <iostream>
#include <functional>
std::once_flag flg;
static int times = 0;
void Init() {
    ++times;
}

void thread_safe_init() {
    std::call_once(flg, Init);
}

int main () {
    std::thread t[10];
    for(int i=0;i<10;i++){
        t[i] = std::thread(thread_safe_init);
    }
    for(int i=0;i<10;i++){
        if(t[i].joinable()) t[i].join();
    }
    std::cout << "timer is:" << times << std::endl;
    return 0;
}