#include "log.hpp"
#include <thread>
#include <vector>

void funa();
void funb();

int main() {
    std::vector<std::thread> vt;
    for(int i=0;i<10;i++) {
        // std::thread th{};
        vt.emplace_back([i](){
            for(int j=0;j<100;j++){
                LOGD(10, "test", "th:%d, print:%d\n", i, j);
            }
        });
    }
    for(auto&  th:vt) {
        if(th.joinable()) th.join();
    }
    for(int i=0;i<40;i++){
        funa();
        funb();
    }
    print("1", "abc",123, "\n");
    return 0;
}