#include <iostream>
#include <memory>

template <typename Derived>
class Base {
  public:
    template <typename T>
    void Interface(T a) {
        static_cast<Derived*>(this) -> template Implementation<T>(a);
    }
    virtual ~Base() = default;
};

class ChildA : public Base<ChildA> {
public:
    template <typename T>
    void Implementation(T a) {
        std::cout << "child a get num :" << a << std::endl;
    }
};

class ChildB : public Base<ChildB> {
public:
    template <typename T>
    void Implementation(T a) {
        std::cout << "child b get num :" << a << std::endl;
    }
};

int main() {
    std::shared_ptr<ChildA> a = std::make_shared<ChildA>();
    std::shared_ptr<ChildB> b = std::make_shared<ChildB>();
    
    a->Interface(2.1f);
    b->Interface(10);
    return 0;
}