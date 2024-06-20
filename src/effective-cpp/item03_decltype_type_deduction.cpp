#include <vector>
#include <iostream>

template <typename Container, typename Index>
auto GetContainerWithIndex(Container c, Index idx) -> decltype(c[idx]) {
    return c[idx];
}

int main() {
    std::vector<int> vi = {9,8,7,6,5,4,22,1};
    GetContainerWithIndex(vi, 3);
    std::vector<bool> vb = {0,1,0,1};
    GetContainerWithIndex(vb, 3);
    // GetContainerWithIndex({10,10}, 3);

    return 0;
}