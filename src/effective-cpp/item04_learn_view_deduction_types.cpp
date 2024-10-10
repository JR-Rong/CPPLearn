#include <vector>

template <typename T>
class TD;

int main(){
    const int i = 442;

    // 通过ide查看变量类型
    auto x = i;
    auto y = &i;
    // delete y;
    y = new int{10};

    // 如果讲将下面注释打开，编译就会看见错误，进而了解到变量的类型
    // TD<decltype(i)> td;
    // TD<decltype(x)> tdx;
    // TD<decltype(y)> tdy;

    std::vector<int> v = {1,2,3,4,5};
    v[10]=10;

    return 0;
}

