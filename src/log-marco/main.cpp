#include "log.hpp"

void funa();
void funb();

int main() {
    for(int i=0;i<40;i++){
        funa();
        funb();
    }
    return 0;
}