# 模板学习

C++模板是一种强大的功能，允许编程者编写与类型无关的代码。下面是关于C++模板的知识点列表，每个知识点都进行了简单说明：

模板基础：模板允许函数或类操作通用数据类型，提高代码复用。

函数模板：使用关键字template创建可以操作任何类型的函数。

类模板：使得类可以用于存储任何数据类型的元素。

模板参数：模板可以有一个或多个参数，这些参数可以是类或函数。

模板参数默认值：可以为模板参数指定默认值。

模板特化：针对特定数据类型提供特定实现的能力。

偏特化：针对模板的部分参数提供特定实现。

模板重载：基于参数的不同，可以重载模板函数。

非类型模板参数：模板参数不仅可以是类型，也可以是值。

模板参数推导：在调用模板函数时，编译器能够自动推导参数的类型。

类型萃取：从给定的类型中提取信息的技术。

模板元编程：使用模板在编译时进行计��。

SFINAE（替换失败不是错误）：一种错误处理机制，用于模板编程中的类型兼容性问题。

变参模板：允许模板接受任意数量的参数。

模板别名：使用using为模板定义新的名称。

类模板偏特化：针对类模板参数的某些特定值提供特化版本。

模板参数包：用于变参模板中的参数集合。

折叠表达式：用于变参模板中简化对模板参数包的操作。

模板友元函数：可以声明特定的模板实例为其他类或函数的友元。

模板继承：类模板可以继承自其他模板类。

模板方法：在类模板中定义的模板函数。

外部模板：声明模板实例化将在别处定义，以减少编译时间。

模板的实例化和特化的顺序：影响程序如何选择使用哪个模板定义。

模板与类型检查：模板可以在编译时提供强��型检查。

模板的可见性和链接性：涉及模板定义在多个转换单元中如何处理。

这个列表涵盖了C++模板编程的多个方面，从基础到高级特性。每个知识点都有其自身的复杂性和应用场景，随着深入学习，你会对它们有更深的理解。

---

C++模板是一种强大的功能，允许编程者编写与类型无关的代码。下面是关于C++模板的知识点列表，每个知识点都进行了简单说明：

1. **模板基础**：模板允许函数或类操作通用数据类型，提高代码复用。

2. **函数模板**：使用关键字`template`创建可以操作任何类型的函数。

3. **类模板**：使得类可以用于存储任何数据类型的元素。

4. **模板参数**：模板可以有一个或多个参数，这些参数可以是类或函数。

5. **模板参数默认值**：可以为模板参数指定默认值。

6. **模板特化**：针对特定数据类型提供特定实现的能力。

7. **偏特化**：针对模板的部分参数提供特定实现。

8. **模板重载**：基于参数的不同，可以重载模板函数。

9. **非类型模板参数**：模板参数不仅可以是类型，也可以是值。

10. **模板参数推导**：在调用模板函数时，编译器能够自动推导参数的类型。

11. **类型萃取**：从给定的类型中提取信息的技术。

12. **模板元编程**：使用模板在编译时进行计��。

13. **SFINAE（替换失败不是错误）**：一种错误处理机制，用于模板编程中的类型兼容性问题。

14. **变参模板**：允许模板接受任意数量的参数。

15. **模板别名**：使用`using`为模板定义新的名称。

16. **类模板偏特化**：针对类模板参数的某些特定值提供特化版本。

17. **模板参数包**：用于变参模板中的参数集合。

18. **折叠表达式**：用于变参模板中简化对模板参数包的操作。

19. **模板友元函数**：可以声明特定的模板实例为其他类或函数的友元。

20. **模板继承**：类模板可以继承自其他模板类。

21. **模板方法**：在类模板中定义的模板函数。

22. **外部模板**：声明模板实例化将在别处定义，以减少编译时间。

23. **模板的实例化和特化的顺序**：影响程序如何选择使用哪个模板定义。

24. **模板与类型检查**：模板可以在编译时提供强��型检查。

25. **模板的可见性和链接性**：涉及模板定义在多个转换单元中如何处理。

这个列表涵盖了C++模板编程的多个方面，从基础到高级特性。每个知识点都有其自身的复杂性和应用场景，随着深入学习，你会对它们有更深的理解。

### 1. 模板基础
在C++中，模板使得你可以编写与类型无关的代码。模板可以用于函数或类，从而允许这些函数或类与任意的数据类型一起工作。模板的基本思想是将数据类型作为参数传递给函数或类，这样一来，同一段代码就可以用于多种不同类型的数据。

### 2. 函数模板
函数模板允许你创建一个函数，该函数可以对任何类型的参数进行操作。你通过在函数定义之前使用`template`关键字和类型参数列表来创建函数模板。当调用模板函数时，编译器会根据传递给函数的实际参数类型来实例化一个具体的函数。

**例子：**
```cpp
// 函数模板定义
template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    // 使用int类型调用
    int i = max(3, 7);        // 实例化为 max<int>(int, int)
    // 使用double类型调用
    double d = max(6.34, 3.12); // 实例化为 max<double>(double, double)
    
    return 0;
}
```
在这个例子中，`max`函数模板可以用于比较任意类型的两个值，并返回较大的那个值。

### 3. 类模板
类模板与函数模板类似，允许在定义类时使其能够处理任何类型的数据。与函数模板一样，你需要在类定义前使用`template`关键字和类型参数列表。当使用类模板创建对象时，必须指定类型参数。

**例子：**
```cpp
// 类模板定义
template <typename T>
class Box {
public:
    T content;
    Box(T content) : content(content) { }
    T getContent() {
        return content;
    }
};

int main() {
    // 使用int类型实例化
    Box<int> intBox(123);
    // 使用string类型实例化
    Box<std::string> stringBox("Hello World");
    
    std::cout << intBox.getContent() << std::endl;    // 输出：123
    std::cout << stringBox.getContent() << std::endl; // 输出：Hello World
    
    return 0;
}
```
这个例子展示了如何定义一个类模板`Box`，它可以存储任何类型的内容。在`main`函数中，使用`Box`的两个实例分别展示了如何用不同的类型（`int`和`std::string`）来实例化并使用这个模板类。

以上就是对C++模板基础、函数模板和类模板的基本介绍和例子说明。通过这些，你可以开始使用C++模板来编写更灵活、复用性更高的代码。

### 4. 模板参数
模板参数是在模板定义时放在尖括号`<>`内的。模板参数可以是一个或多个，它们定义了模板可以接受的类型或值。类型参数通常以关键字`typename`或`class`表示，而非类型参数可以是具体的整型值、指针、引用或者枚举。

**类型参数示例**:
```cpp
template <typename T>
void fun(T a) {
    // ...
}

template <class T, typename U>
T convert(U a) {
    return static_cast<T>(a);
}
```
在第一个例子中，`fun`有一个类型参数`T`；第二个例子`convert`有两个类型参数`T`和`U`。

**非类型参数示例**:
```cpp
template <typename T, int size>
class Array {
    T arr[size];
public:
    // ...
};

Array<int, 5> myArray; // 类型T=int, 非类型参数size=5
```
在这里，`Array`类模板有一个类型参数`T`和一个非类型参数`size`，它们被用于定义一个固定大小的数组。

### 5. 模板参数默认值
在定义模板时，可以为模板参数指定默认值。这就允许调用者在使用模板时不必为所有参数都提供具体的类型，而是可以依赖默认值。默认值对于类模板最为有用，因为这可以简化类模板的使用。

**例子**:
```cpp
template <typename T = int>
class Numbers {
    // ...
};

Numbers<> numbers; // 使用默认的int类型
Numbers<double> doubleNumbers; // 明确指定为double类型
```
在这个例子中，`Numbers`模板类有一个默认的类型参数，如果在创建对象时没有指明类型，则默认为`int`类型。

### 6. 模板特化
模板特化是为模板定义一个特定版本的过程，它针对特定数据类型或参数集合。通过模板特化，可以优化在某些情况下特定数据类型的处理，或者为某些类型提供完全不同的实现。

**全特化示例**：
```cpp
template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

// 对int类型进行特化
template <>
int max<int>(int x, int y) {
    std::cout << "Specialized for int" << std::endl;
    return (x > y) ? x : y;
}
```
这里，针对`int`类型的`max`函数进行了特化。调用`max<int>(5, 10)`将会使用这个特化版本。

### 6.1 模板偏特化（Partial Specialization）
对于类模板，可以提供偏特化版本，这涉及部分模板参数的特化，而不是全部参数。

**偏特化示例**：
```cpp
template <typename T, typename U>
class MyClass {
    // 通用实现
};

// 部分特化，只有第一个模板参数T被特化为int
template <typename U>
class MyClass<int, U> {
    // 针对第一个参数是int的特化实现
};
```
在这个例子中，如果第一个模板参数为`int`，第二个模板参数为任意类型`U`，那么会使用这个偏特化的版本。

模板参数、默认值、特化和偏特化都是模板编程中的高级特性，它们提供了额外的灵活性和性能优化，但同时也增加了复杂性。特化和偏特化是用来优化特定类型或参数组合的模板行为，而这在一些特定场景中非常有用。

### 7. 模板重载
在C++中，可以像重载普通函数那样重载模板函数。这意味着可以根据函数参数的不同（参数的数量或类型），定义多个同名的模板函数。编译器会根据调用时提供的参数自动选择最匹配的模板函数。

**模板重载示例**：
```cpp
template <typename T>
void print(T value) {
    std::cout << "Value: " << value << std::endl;
}

template <typename T, typename U>
void print(T value1, U value2) {
    std::cout << "Values: " << value1 << ", " << value2 << std::endl;
}

int main() {
    print(123);        // 调用第一个模板函数
    print(3.14, "pi"); // 调用第二个，重载的模板函数
}
```
在此示例中，基于提供给`print`函数的参数数量和类型的不同，编译器会选择合适的重载版本。

### 8. 非类型模板参数
除了类型模板参数外，C++模板还支持非类型模板参数。这意味着模板参数可以是一个具体的值而非一个类型。非类型参数必须是一个常量表达式，因为它们在编译时需要确定值。

**非类型模板参数示例**：
```cpp
template <typename T, int SIZE>
class Array {
    T data[SIZE];
public:
    void set(int index, T value) {
        if (index >= 0 && index < SIZE)
            data[index] = value;
    }
    T get(int index) {
        return data[index];
    }
};

int main() {
    Array<int, 5> intArray;
    intArray.set(0, 10);
    std::cout << intArray.get(0) << std::endl;
}
```
此示例展示了一个能够处理任何类型`T`的数组，其大小由非类型模板参数`SIZE`指定。

### 9. 模板参数推导
C++11及以后的版本，模板参数推导允许编译器基于函数调用的上下文自动推断模板参数的类型，这简化了模板函数的使用，因为调用时不总是需要显式指定模板参数类型。

**模板参数推导示例**：
```cpp
template <typename T>
void func(T arg) {
    // do something
}

int main() {
    func(10);   // T被推导为int
    func(5.5);  // T被推导为double
}
```
通过这个例子，可以看到调用`func`时没有明确指定类型`T`，编译器会根据传入`func`的参数自动推导`T`的类型。

模板参数推导是一个强大的特性，大大减少了模板使用时的繁琐，并使得代码更加简洁易读。然而，也需要注意其复杂情况下的行为，特别是当涉及到引用、指针、常量等复杂类型时，推导规则会相对复杂，可能导致不符合直觉的结果。

### 10. 类型萃取（Type Traits）

类型萃取是一套用于在编译时探知和操作类型属性的技术和方法。通过类型萃取，我们可以关于类型进行询问（如是否是指针、是否具有某个成员函数等），并基于这些信息编写出更加通用和健壮的模板代码。

**类型萃取示例**：
```cpp
#include <iostream>
#include <type_traits>

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is integer? " << std::is_integral<int>::value << '\n'; // 输出：true
    std::cout << "Is floating point? " << std::is_floating_point<int>::value << '\n'; // 输出：false
}
```
在这个例子中，我们利用`std::is_integral`和`std::is_floating_point`两个类型萃取来检测`int`类型是否是整数型和浮点型。类型萃取广泛应用于库的设计，使得模板代码可以根据类型的具体特性进行优化。

### 11. 模板元编程（Template Metaprogramming, TMP）

模板元编程是一种利用模板实现的在编译时执行计算的技术。TMP可以用于生成编译时常数、类型计算和代码生成等任务，是一种非常强大的编程范式。

**模板元编程示例**：计算阶乘
```cpp
template<int N>
struct Factorial {
    enum { value = N * Factorial<N-1>::value };
};

template<>
struct Factorial<0> { // 特化的基准情况
    enum { value = 1 };
};

int main() {
    std::cout << "Factorial of 5: " << Factorial<5>::value << std::endl; // 输出：120
}
```
此示例展示了如何使用模板元编程在编译时计算5的阶乘。借助模板递归和模板特化，我们能够在编译时完成计算，`Factorial<5>::value`这个表达式被完全展开并计算为120。

### 12. SFINAE（Substitution Failure Is Not An Error）

SFINAE原则是C++模板编程中非常重要的一个概念。它表示在模板参数替换过程中的失败，并不直接导致编译错误，而是导致编译器忽略该模板重载，而尝试其他重载或模板。

SFINAE常用于实现基于条件的重载选择和编译时的错误检测，通常和`std::enable_if`配合使用。

**SFINAE示例**：使用`enable_if`限制模板函数只接受整数类型
```cpp
#include <type_traits>
#include <iostream>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
onlyIntegral(T value) {
    return value;
}

int main() {
    std::cout << onlyIntegral(5) << std::endl; // 正确，因为5是整数类型
    // std::cout << onlyIntegral(5.0) << std::endl; // 这将导致编译错误，因为5.0不是整数类型
}
```
在这个例子中，`onlyIntegral`函数模板通过`std::enable_if`和`std::is_integral`结合使用，限制了它只能接受整数类型参数。如果尝试用非整数类型调用它，通过SFINAE原则，会导致`onlyIntegral`模板实例化失败，而不会产生编译错误（当然，如果没有其他合适的重载，最终可能还是会导致编译错误）。

这些高级特性将C++模板编程的威力扩展到了极致，使得基于类型的计算和条件决定的代码生成成为可能，极大地提升了代码的灵活性和表达能力。

### 13. 变参模板（Variadic Templates）

变参模板是C++11引入的一项功能，它允许函数或类模板接受不定数量的模板参数。这些参数被称为模板参数包（parameter pack），可以是一组类型、非类型参数，或者两者的组合。变参模板可以极大地增加模板的灵活性，使我们能够编写能适应任意多参数的模板代码。

**变参模板示例**：
```cpp
#include <iostream>

// 基础情形：一个无参数的print函数
void print() {
    std::cout << "I am empty function and I am called at last.\n";
}

// 变参模板函数
template <typename T, typename... Types>
void print(T firstArg, Types... args) {
    std::cout << firstArg << std::endl; // 打印第一个参数
    print(args...); // 递归调用以打印其余参数
}

int main() {
    print(1, 3.14, "Hello", 'a'); // 可以无缝接受不同数量和类型的参数
}
```
在这个例子中，`print`函数可以接受不同数量和类型的参数，并将它们逐个打印出来，直到没有参数剩下，从而调用空的`print`函数。

### 14. 模板别名（Alias Templates）
C++11中引入了模板别名，它允许为一个复杂的模板类型定义一个新的简短名称。这��通过使用`using`关键字来实现。模板别名使得阅读和书写涉及复杂模板类型的代码变得更加容易。

**模板别名示例**：
```cpp
template <typename T>
using Vec = std::vector<T>; // 使用Vec作为std::vector<T>的别名

int main() {
    Vec<int> intVector; // 现在Vec<int>就是std::vector<int>
}
```
在这个例子中，`Vec`被定义为`std::vector`的模板别名，可以像正常的`vector`一样使用。

### 15. 类模板偏特化（Partial Specialization for Class Templates）
我们在前面简单提到了类模板的偏特化是可能的。这是一种模板特化，它只特化一部分模板参数，或者给模板参数增加一些条件限制。类模板的偏特化可以用于特殊情况下为模板提供特定的实现逻辑。

**类模板偏特化示例**：
```cpp
#include <iostream>

// 通用版本
template <typename T1, typename T2>
class MyClass {
public:
    void display() {
        std::cout << "Primary template\n";
    }
};

// 偏特化版本：第二个模板参数为int
template <typename T1>
class MyClass<T1, int> {
public:
    void display() {
        std::cout << "Partial specialization for second parameter as int\n";
    }
};

int main() {
    MyClass<double, double> obj1;
    MyClass<double, int> obj2;
    obj1.display(); // 调用通用版本
    obj2.display(); // 调用偏特化版本
}
```
在这个例子中，`MyClass`有一个通用模板以及一个偏特化版本。当第二个参数类型是`int`时，偏特化版本会被使用。

模板参数包、模板别名和类模板的偏特化都是提高模板代码��用性和灵活性的重要特性。它们各自在不同场景下提供了强大的工具，以便构建可维护、高效和可扩展的C++应用程序。

### 16. 模板方法（Template Methods）

在类模板中，除了将整个类作为模板外，还可以在类中定义模板成员函数。这类成员函数可以独立于外部类的模板参数，甚至可以接受自己的模板参数，这就是所谓的模板方法。

**模板方法示例**：
```cpp
#include <iostream>

template <typename T>
class MyClass {
public:
    T value;

    MyClass(T val) : value(val) {}

    // 模板方法，与外部类模板参数独立
    template <typename U>
    void print(U msg) {
        std::cout << msg << ": " << value << std::endl;
    }
};

int main() {
    MyClass<int> myInt(42);
    myInt.print("The value is"); // T=int, U=const char*

    MyClass<std::string> myString("Hello");
    myString.print(std::string("The string is")); // T=std::string, U=std::string
}
```
在这个例子中，`MyClass`是一个类模板，`print`是类内的模板方法，它接受与类模板参数`T`不同的类型`U`作为参数。

### 17. 外部模板（Extern Templates）
C++11引入了外部模板的概念。��部模板用于显式告知编译器一个给定的模板实例化将在程序的其他地方定义。这主要用于减少编译时间和减小生成的二进制尺寸，因为阻止了模板在每一个使用它的源文件中都重复实例化。

**外部模板示例**：
```cpp
// some_header.hpp
template<typename T>
class MyClass {
    // ... 实现 ...
};

// TODO: 如果你知道某个特定实例化会在其他编译单元中出现，则可在头文件中声明
extern template class MyClass<int>;
```
```cpp
// some_implementation.cpp
#include "some_header.hpp"

// 具体实例化是在某个.cpp文件中完成
template class MyClass<int>;
```
在这个例子中，`MyClass<int>`的显式实例化在`some_implementation.cpp`完成，而`some_header.hpp`头文件中的`extern template`声明告诉编译器不要在包含这个头文件的其他源文件中再次实例化这个类模板。

### 18. 模板的实例化和特化的顺序
模板的实例化顺序和特化对于程序的行为是很重要的。通常，特化必须在首次实例化模板之前声明，否则特化将不会被考虑。此外，如果存在多个可能匹配的模板特化，编译器需要遵循一定的选择规则。

模板实例化一般在模板被使用时发生，例如，当你创建了一个模板类的对象或调用了一个模板函数时。特化可以是完全特化，也可以是偏特化。编译器首先会考虑最具体的特化，然后是更通用的特化，最后考虑原模板。

**特化顺序示例**：
```cpp
#include <iostream>

template <typename T>
void func(T) {
    std::cout << "Primary template" << std::endl;
}

template <>
void func<int>(int) {
    std::cout << "Specialized template for int" << std::endl;
}

template <>
void func<double>(double) {
    std::cout << "Specialized template for double" << std::endl;
}

int main() {
    func('a');    // 使用原模板
    func(10);     // 使用int特化模板
    func(3.14);   // 使用double特化模板
}
```
在这个例子中，为给定的类型`int`和`double`提供了特化版本的`func`函数。对应特化的版本会覆盖原模板的实现。模板特化需要在首次实例化模板或其它特化调用之前声明。

理解这些概念对于编写可预见行为的模板代码是非常重要的，因为这决定了编译器会如何在多个可能的模板定义或特化之间做出选择。

### 19. 模板友元函数
在C++中，友元函数是定义在类外部但仍然能够访问类的私有成员的函数。当涉及到模板时，我们可以定义模板的友元函数，这可以是一个普遍适用的模板友元，或者是特定实例化的友元。

**泛化的模板友元示例**：
```cpp
#include <iostream>

template <typename T>
class MyClass {
    T value;
public:
    MyClass(T val) : value(val) {}

    // 声明一个模板函数为友元，使其可以访问MyClass的私有成员
    template <typename U>
    friend void printValue(const MyClass<U>&);
};

// 模板友元函数的定义
template <typename T>
void printValue(const MyClass<T>& x) {
    std::cout << x.value << std::endl;
}

int main() {
    MyClass<int> object(42);
    printValue(object); // 输出：42
}
```
在这个例子中��`printValue`是一个模板友元函数，它可以访问所有`MyClass<T>`实例的私有成员，无论`T`的类型如何。

### 20. 模板继承
模板也可以被用于继承，允许定义通用的基础结构和接口。类模板可以从另一个类模板继承，无论是普通类还是模板类，从而使得代码更加灵活和可重用。

**模板继承示例**：
```cpp
#include <iostream>

template <typename T>
class Base {
public:
    T value;
    void show() {
        std::cout << "Value: " << value << std::endl;
    }
};

template <typename T>
class Derived : public Base<T> { // 模板继承
public:
    Derived(T val) {
       this->value = val; 
    }
};

int main() {
    Derived<int> d(10);
    d.show(); // 输出：Value: 10
}
```
在本例中，`Derived`类模板从`Base`类模板继承，`Base`中定义的`show`函数在`Derived`中也可以使用，展现了模板继承的强大能力。

### 21. 类模板中的模板成员函数
类模板不仅可以包含常规成员函数，还可以包含其自身的模板成员函数。这允许类在处理不同类型的数据时提供更加灵活的操作。

**类模板中模板成员函数示例**：
```cpp
#include <iostream>

template <typename T>
class MyClass {
public:
    // 模板成员函数
    template <typename U>
    void func(U u) {
        std::cout << "Handling value: " << u << std::endl;
    }
};

int main() {
    MyClass<int> myObject;
    myObject.func(42); // 使用int类型实例化模板成员函数
    myObject.func("Hello Template"); // 使用const char*类型实例化模板成员函数
}
```
在此例中，`MyClass`是类模板，它包含一个模板成员函数`func`，该函数可以接受任何类型的参数`U`，显示该模板成员函数提供的灵活性。

以上介绍的模板友元函数、模板继承以及类模板中的模板成员函数都是C++模板编程中非常强大的功能，它们为设计通用、灵活且强大的类库和应用程序提供了必要的工具。这些高级特性的恰当使用可以显著提高代码的表现力和复用性。

### 22. 折叠表达式 (Fold Expressions)

C++17 引入了折叠表达式（Fold Expressions），作为变参模板的一个重要补充，允许对参数包中的所有元素执行一个给定的操作，并将结果“折叠”成单个值。这极大简化了对变参模板参数包的操作，特别是进行累积、逻辑和比较操作时。

折叠表达式有两种形式：二元(left fold 和 right fold)和一元折叠。

**示例**：
```cpp
template<typename... Args>
auto sum(Args... args) {
    return (... + args); // 二元左折叠
}

int main() {
    auto total = sum(1, 2, 3, 4, 5); // 返回 15
    std::cout << "Total: " << total << std::endl;
}
```
在这个例子中，`sum`函数利用了折叠表达式来计算所有传入参数的和。折叠表达式`(... + args)`表示将`+`操作应用于所有参数包`args`中的元素，并将它们“折叠”成一个单一结果。

### 23. 类型萃取和 SFINAE

虽然类型萃取(`Type Traits`)和SFINAE(`Substitution Failure Is Not An Error`)已经被简要介绍过，它们之间实际上有紧密的联系，特别是在模板元编程中，二者经常被结合使用来实现基于类型特征的条件编译和编译时决策。

类型萃取提供一种机制来在编译时检查、提取和使用类型的性质（如是否是指针、是否具有某个类型的成员等）。通过这些信息，SFINAE可以用来使某些模板只对符合特定条件的类型生效。

**示例**：使用`std::enable_if`
```cpp
#include <iostream>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
print_if_integral(T value) {
    std::cout << value << '\n';
    return value;
}

int main() {
    print_if_integral(42); // 正确: 42是整数
    // print_if_integral(3.14); // 错误: 如果取消注释将不能编译，因为3.14不是整数类型
}
```
这个例子中`print_if_integral`函数模板使用`std::enable_if`，仅当`T`是整数类型时才可用。这正是通过SFINAE和类型萃取技术共同作用的结果。

### 24. 模板的可见性和链接性 (Visibility and Linkage)

在C++中，模板的定义需要对编译器可见，这通常意味着模板的定义必须在头文件中，或者在需要它们的源文件之前。这是因为编译器在遇到模板使用时需要访问其完整定义，以生成模板的实例。

关于链接性，模板实例通常有内部链接性。这意味着每个实例化都是局部于包含它的翻译单元。然而，C++的`extern template`声明可以用来改变这一点，通过显式实例化和`extern`声明减少编译时间和减少生成的对象文件大小。

### 25. 外部模板 (Extern templates)

`extern template`声明是C++11引入的，用于显式告诉编译器不要在当前翻译单元中实例化模板，而是等到链接时使用其他翻译单元提供的实例。这可以大大减少编译时间，特别是对于大型项目而言。

**示例**:
```cpp
// 在头文件中声明Vector模板的一个特定实例化是外部的
extern template class std::vector<int>;

// 在一个.cpp文件中实际完成实例化
template class std::vector<int>; // 显式实例化
```
这种方法确保了模板只被实例化一次，然后在程序的其他部分被使用，从而优化编译过程。

通过这些高阶特性的介绍，我们可以看到C++模板提供极大的灵活性和强大的编程能力，但它们也要求开发者对模板机制有深入的理解。正确使用这些特性可以帮助解决复杂的编程问题，编写高效、可维护的代码。

---

---

# C++17模板相关特性
C++17引入了一些新特性来增强模板编程。这些特性致力于简化模板的使用，增强灵活性，以及改善编译时错误信息。在C++17中，其中一些对于模板的高阶用法改进和新增功能包括：

1. `if constexpr`:
   C++17引入了`if constexpr`语句，它在编译时对条件进行求值。如果条件为真，则编译并执行if内部的代码；否则，编译器会完全忽略该块代码。这对于模板元编程来说非常有用，因为它可以用于在编译时有条件地编译代码。

2. 折叠表达式（Fold Expressions）:
   折叠表达式使得在可变参数模板中对参数包进行操作变得更加简单。你可以使用折叠表达式来实现对参数包中所有元素进行递归操作，例如求和或比较，而不需要编写复杂的递归模板或使用辅助函数。

3. 类模板参数推断（Class Template Argument Deduction, CTAD）:
   在C++17之前，你在实例化类模板时通常需要显式指定模板参数。但是有了CTAD，编译器能够根据构造函数的参数类型来推断类模板参数，从而简化了模板的使用。

4. 模板参数列���中的auto:
   C++17 允许你在模板参数列表中使用`auto`关键字，从而能够推断非类型模板参数的类型。这样，你可以写出更通用的模板，它们能根据传递给它们的参数自动推断正确的类型。

5. 内联变量:
   C++17允许在类或命名空间范围内声明内联变量，这对于模板特化中的静态成员非常有用，因为它避免了在多个翻译单元中重复模板静态成员的定义。

6. 结构化绑定:
   虽然结构化绑定不是专门用于模板编程的，但它对于返回tuple或pair的模板函数来说非常有用，因为它允许你直接将这些结构的元素解构为独立的变量。

7. 模板的 `[[nodiscard]]` 属性:
   C++17引入了[[nodiscard]]属性，它可以用于模板函数和类，以警告用户不要忽略返回值。这对于设计API和模板库非常有用，可以提高代码的安全性和清晰性。

8. constexpr if和模板:
   使用constexpr if可以进一步简化模板和元编程代码，因为它提供了一种编译时决策方法，这在函数模板中特别有用。

这些特性使得模板编程变得更加强大且易于管理。注意，理解和应用这些高阶特性需要较深的C++模板和模板元编程的知识。随着C++20标准的推出，模板编程在那个版本中得到了更进一步的增强和改善。

---

`if constexpr` 是 C++17 中引入的一个新的条件编译语句，它允许在编译期间根据常量表达式的结果选择不同的代码路径。`if constexpr` 和普通的 `if` 语句不同之处在于，其条件必须是一个编译时常量表达式，而且如果 `if constexpr` 的条件为 `false` 时，其对应的分支在编译期就会被丢弃。

这对模板编程特别有用，因为它允许编译器根据模板参数在编译时展开不同的代码，这可以消除很多需要模板特化或重载来实现编译时决策的情况。

使用 `if constexpr` 的一个主要场景是在处理可变参数模板（variadic templates）时简化递归模板函数的写法。下面是一个使用 `if constexpr` 的例子，该例子中的函数 `print` 可以打印任意数量的参数：

```cpp
#include <iostream>

template<typename First, typename... Rest>
void print(const First& first, const Rest&... rest) {
    std::cout << first; // 打印第一个参数
    if constexpr (sizeof...(rest) > 0) {
        std::cout << ", ";
        print(rest...); // 递归调用打印剩余参数
    }
}

int main() {
    print(1, 2.5, "three", '4');
    return 0;
}
```
这段代码展示了可变参数模板 `print` 函数的定义，它接受至少一个参数。在函数中，使用 `if constexpr` 来判断是否还有更多的参数需要递归打印。条件 `sizeof...(rest) > 0` 在编译时进行检查，以决定是否执行递归调用 `print(rest...)`。如果没有更多参数，就不会再生成对 `print` 的递归调用，从而终止递归。

之所��用 `if constexpr` 而不是普通的 `if` 来做这件事，是因为普通的 `if` 不会影响模板的实例化过程。如果你在可变参数为空的情况下（即 `Rest...` 是空的）还进行模板函数的调用，那即使 `if` 条件为 `false`，编译器仍然会试图去生成代码，最终会导致错误。但在 `if constexpr` 的情况下，一旦条件为 `false`，相关的代码就会在编译期被丢弃，因此不会有模板实例化失败的问题。

`if constexpr` 是模板元编程和SFINAE（Substitution Failure Is Not An Error）技术的有力补充，能够提供更加直观和易于维护的编写方式。它不仅能简化编码，还有助于减少模板代码的编译时间，并改善编译期错误的可读性。

User：继续讲解第二点，折叠表达式

Assistant：折叠表达式（Fold Expressions）是C++17中引入的一项新特性，旨在简化可变参数模板中对参数包（Parameter Pack）的操作。在C++17之前，处理参数包时通常需要递归模板或者一些辅助函数，这在许多情况下既不直观也不简洁。折叠表达式通过提供一种紧凑、直接的方式对参数包中的所有元素执行运算，极大地改善了这种情况。

### 折叠表达式的基本形式

折叠表达式有两种形式：二元折叠和一元折叠。它们都能够应用于可变参数模板中的参数包，而且都可以应用任何支持的运算符。

1. **二元折叠**（接受一个初始值）:
   - *(pack op ... op init)* 和 *(init op ... op pack)*
   - 其中 `op` 表示运算符，`pack` 表示参数包，而 `init` 表示初始值。

2. **一元折叠**（不接受初始值）:
   - *(pack op ...)* 和 *(... op pack)*

### 折叠表达式的应用示例

让我们通过一些实际的例子来理解折叠表达式的用法。

**示例 1：计算所有参数的和**

```cpp
template<typename... Args>
auto sum(Args... args) {
    return (args + ... + 0);
}
```
在这个例子中，`(args + ... + 0)` 是一个右折叠表达式，它从左到右对参数包 `args` 中的所有元素执行加法运算，并使用 `0` 作为初始值。如果参数包为空，结果就是初始值 `0`。

**示例 2：将所有参数打印到标准输出**

```cpp
#include <iostream>

template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n';
}
```
在这个例子中，`(std::cout << ... << args)` 是一个左折叠表达式，它使用插入运算符 (`<<`) 从左到右依次打印所有参数。需要注意的是，这里没��提供初始值，因为 `std::cout` 本身就起到了起始元素的作用。

**示例 3：逻辑“与”检查**

```cpp
template<typename... Args>
bool allTrue(Args... args) {
    return (... && args);
}
```
这个例子中，`(... && args)` 是一个右折叠表达式，用逻辑“与”运算符 (`&&`) 检查所有参数。如果所有参数都为 `true`，则表达式的结果为 `true`；否则为 `false`。这里没有使用初始值，因为 `&&` 运算符的默认行为就能够正确处理空的参数包（在逻辑“与”的情况下，空参数包的结果为 `true`）。

### 小结

折叠表达式大大简化了对可变参数模板中参数包的操作，使得模板代码更加简洁、清晰。通过使用折叠表达式，许多原本需要复杂递归模板或专门的辅助函数来实现的操作现在可以通过一行代码轻松完成。这是C++17对模板编程带来的重要改进之一。

---

类模板参数推断（Class Template Argument Deduction, CTAD）是C++17引入的一项特性，用于简化类模板的使用。在C++17之前，每当你想要创建一个模板类的实例时，你通常需要明确指定模板参数。但是有了CTAD，编译器能够自动推断出模板参数的类型，这使得代码更加简洁，并且减少了出错的机会。

### 基本用法

CTAD允许你在构造模板对象时省略模板参数列表，编译器会根据构造函数的参数类型自动推断模板参数。

假设我们有一个简单的模板类`Box`:

```cpp
template<typename T>
class Box {
public:
    Box(T value) : value_(value) {}
    T value() const { return value_; }
private:
    T value_;
};
```

在C++17之前，如果你想创建一个`Box`的实例，你需要这样做：

```cpp
Box<int> intBox(123);  // 明确指定模板参数为int
Box<std::string> stringBox("Hello");  // 明确指定模板参数为std::string
```

但是有了CTAD，你就可以省略模板参数：

```cpp
Box intBox(123);  // 编译器推断T为int
Box stringBox("Hello");  // 编译器推断T为std::string
```

这样你的代码看起来更简洁，同时也减少了写错模板参数类型的风险。

### CTAD规则

编译器在进行类模板参数推断时，会遵循一系列的规则。它首先会检查是否存在用户定义的推导指引（Deduction Guide），如果没有，编译器会尝试使用模板类的构造函数来推断类型。简而言之，编译器会基于提供给构造函数的参数类型，来推断出模板参数的类型。

对于有多个构造函数的类模板，编译器会为每个构造函数尝试进行参数推断，选择最合适的构造函数进行类型推导。

### 注意事项

尽管CTAD大大简化了类模板的使用，但在一些复杂的情况下，编译器可能无法正确推断出模板参数的类型，或者推断的类型不是你所期望的。此时，你仍然需要手动指定模板参数。因此，对于复杂的模板类，了解其工作方式和构造函数的细节仍然很重要。

另外，为了控制模板参数的推断过程，你可以为模板类定义自己的推导指引（Deduction Guide）。这是一种显式告诉编译器如何根据构造函数参数类型推断模板参数类型的方法。

### 示例：推导指引

下面是一个使用推导指引的简单示例：

```cpp
template<typename T>
class Box {
public:
    Box(T value) : value_(value) {}
    T value() const { return value_; }
private:
    T value_;
};

// 推导指引
template<typename T>
Box(T) -> Box<T>;
```
在这个示例中，推导指引告诉编译器：当使用`Box`类的构造函数创建对象时，基于构造函数参数的类型`T`，应该推断出模板参数也是`T`。这对于复杂的情况或者特定的用法是非常有用的，它提供了更大的控制性。

通过引入类模板参数推断，C++17使得模板类的使用变得更加灵活和简单，有助于减轻模板编程的一些复杂性，并提升了编码效率。

---

在C++17中引入了一项新的特性，允许在模板参数列表中使用`auto`，这为模板编程带来了更大的灵活性和简洁性。此特性使得在声明模板时可以用`auto`来占位，从而使编译器能够推断模板参数的类型。这主要用于非类型模板参数（Non-type Template Parameters, NTTP），即那些代表值而非类型的模板参数。

### 使用场景和好处

使用`auto`在模板参数列表中允许编写更通用的代码，因为它减少了针对特定类型的重载或特化的需要。`auto`使得模板可以针对任何合适的类型被实例化，而不必显式地在模板定义中指定所有可能的类型。

### 基本语法

假设我们有一个需求，要定义一个固定大小的数组模板类，但希望该模板类能针对任何大小（和类型）进行工作。在C++17之��，你可能需要这样做：

```cpp
template<typename T, std::size_t N>
class FixedArray {
    // ...
};
```

这里`std::size_t N`是一个非类型模板参数，它指定了数组的大小。然而，使用C++17中引入的`auto`关键字，你可以这样写：

```cpp
template<typename T, auto N>
class FixedArray {
    // ...
};
```

在这个例子中，通过将第二个模板参数声明为`auto N`，这个模板就能够自动推断`N`的类型。这意味着你可以在不同的上下文中用不同类型的值来实例化`FixedArray`，增加了模板的灵活性。

### 实用例子

让我们通过一个例子来更好地理解这个特性：

```cpp
#include <array>
#include <iostream>

template<auto N>
struct PrintNumber {
    void operator()() const {
        std::cout << N << '\n';
    }
};

int main() {
    PrintNumber<5>()();   // 输出 5
    PrintNumber<'a'>()(); // 输出 'a' （对应的ASCII值）
}
```

在这个例子中，我们定义了一个结构体`PrintNumber`，它接受一个`auto`类型的非类型模板参数`N`。这使得我们可以用各种不同类型的字面量实例化`PrintNumber`，包括整数和字符。通过这种方式，`auto`关键字提供了编写通用和灵活模板代码的能力。

### 注意事项

尽管在模板参数列表中使用`auto`使得模板的编写变得更灵活，但也要注意避免过度泛化。合理使用此特性可以使代码更简洁、更通用，但如果滥用，可能会导致代码的可读性和可维护性降低。另外，要记住的是，这个特性仅适用于非类型模板参数。

总的来说，C++17通过允许在模板参数列表中使用`auto`，为编写高效且灵活的模板代码提供了新的途径。这一改进提高了模板的实用性，并在某种程度上简化了模板编程的复杂性。

---

C++17 引入了内联变量（inline variables）这一特性，它解决了模板类中静态数据成员的多重定义问题，与内联函数有类似的作用。在此之前，如果在头文件中定义了一个静态数据成员，当多个源文件包括这个头文件时，会导致一个违反 One Definition Rule (ODR) 的情况，因为每个源文件都会尝试定义同一个静态数据成员的副��。

### 基本概念

标记为 `inline` 的变量具有多个定义是被允许的（在不同的编译单元中），但这些定义必须完全相同。此外，这些定义都指向相同的对象，就好像只有一个定义存在。

### 模板静态成员的问题

在C++17之前，如果你有一个模板类并在其中定义了一个静态成员变量，你必须在一个.cpp文件中提供该静态成员变量的定义，以确保该变量只有唯一一个定义，否则会因为多重定义导致链接错误。例如：

```cpp
// header.hpp
template <typename T>
class MyClass {
public:
    static int value;
};

// 必须在某个.cpp文件中这样做
template <typename T>
int MyClass<T>::value = 0;
```

但这种方式要求每一个可能的类型实例化都需要在.cpp文件提供定义，并且还会在每个包含该头文件的编译单元中实例化，从而可能产生多个定义。

### C++17 内联变量的使用

C++17 允许开发者将模板的静态数据成员声明为 `inline`，直接在类中初始化，无需在.cpp文件中进行定义：

```cpp
// header.hpp
template <typename T>
class MyClass {
public:
    inline static int value = 0; // C++17 允许这样做
};
```

这么做的好处是，类模板的每个实例化将共享��一个 `value` 静态成员，并且不会违反ODR规则，也不会产生链接错误。

### 影响和好处

内联变量的引入简化了模板库的实现，并且使得头文件只包含模板定义成为可能。它改善了模板类的静态成员定义的组织方式，使得模板编写更为高效和简洁。

正如内联函数一样，内联变量也提高了组件的可复用性，允许在各种编译单元之间共享变量定义而不会违反ODR。这例如在模板库编写和其他需要在头文件中包含静态数据的情况下特别有用。

---

C++17引入了结构化绑定（Structured Binding），这是一种新的语法特性，它允许从数组、元组（tuple）或结构体中一次性解包多个值，并将这些值绑定到变量上。这大大简化了某些编程情况中的代码，使得处理多值返回和复合数据结构变得更加直接和清晰。

结构化绑定的主要好处在于提高了代码的可读性和简洁性，尤其是在处理函数返回多个值或操作复杂数据结构时。

### 语法

结构化绑定的基本语法如下：

```cpp
auto [变量1, 变量2, ..., 变量N] = 表达式;
```

表达式的结果可以是元组、数组、结构体或pair，编译器会根据表达式的返回类型自动推断每个变量的类型。

### 使用元组和pair进行结构化绑定

假设有一个函数，它返回一个`std::tuple`，我们可以利用结构化绑定一次性接收所有的返回值：

```cpp
#include <tuple>

std::tuple<int, double, std::string> getPerson() {
    // 仅作示例，实际使用中可能会从数据库或输入获取数据
    return {1, 2.3, "John Doe"};
}

int main() {
    auto [id, age, name] = getPerson();
    // 现在id, age, name分别被绑定为1, 2.3和"John Doe"
}
```

### 使用数组进行结构化绑定

结构化绑定也适用于数组：

```cpp
int main() {
    int arr[] = {1, 2, 3};
    auto [a, b, c] = arr;
    // a, b, c分别被绑定为1, 2, 3
}
```

### 使用结构体进行结构化绑定

结构化绑定甚至可以用于结构体，但要求结构体的成员是public的：

```cpp
struct MyStruct {
    int x;
    double y;
};
int main() {
    MyStruct s{100, 3.14};
    auto [a, b] = s;
    // a被绑定为100, b被绑定为3.14
}
```

### 注意事项

- 结构化绑定创建的变量是对原数据的引用，除非使用了`std::move()`，否则不会发生数据的复制。
- 结构化绑定也可以与`auto&`、`const auto&`和`auto&&`结合使用，以获得不同类型的引用。
- 结构体的成员必须是public的，以便结构化绑定能够访问。

结构化绑定在处理多返回值函数、遍历元组等场合十分有用，简化了代码的编写工作，使得代码更加清晰、简洁。这是C++17对于现代C++编程实践的又一显著改进。

---

C++17 引入了一个新的属性 `[[nodiscard]]`，用于强调函数的返回值不应被忽略。当函数被声明为 `[[nodiscard]]` 时，如果调用方忽略了其返回值，编译器将发出警告。这对于提高代码的安全性和避免编程错误非常有用，尤其是在那些返回值中携带重要状态或错误信息的场景中。

在C++17以前，经常会发现代码中调用了某些重要的函数但忽略了其返回值，这可能导致难以发现的错误。使用`[[nodiscard]]`属性可以帮助开发者及早地在编译时发现这类问题��

### 基本语法

```cpp
[[nodiscard]] 返回值类型 函数名(参数列表);
```

### 用于普通函数

```cpp
[[nodiscard]] int calculateSomethingImportant() {
    // 一些重要的计算
    return 42;
}

int main() {
    calculateSomethingImportant(); // 这行会引发编译器警告，因为忽略了返回值
    return 0;
}
```

### 用于模板和类成员函数

`[[nodiscard]]` 同样可以用于模板函数和类的成员函数上，来确保返回的值被妥善处理。

```cpp
class [[nodiscard]] ErrorInfo {
public:
    bool hasError() const { return true; } // 示例方法，总是表示有错误
};

ErrorInfo checkForError() {
    // 检查错误
    return ErrorInfo();
}

int main() {
    checkForError(); // 这行也会引发编译器警告，因为忽略了返回的 ErrorInfo 对象
    return 0;
}
```

特别地，你可以将 `[[nodiscard]]` 属性应用到整个类上，这样来自该类的所有方法返回值都自动成为 `[[nodiscard]]`。这对于设计那些返回值总是重要且不应被忽略的类非常有用。

### 用于构造函数

需要注意的是，`[[nodiscard]]` 属性不能用于构造函数。构造函数本身没有返回值，而且其调用方式（创建对象实例）本质上不同于普通函数调用。

### 功能扩展

在C++20中，`[[nodiscard]]` 属性的功能得到了扩展。你可以为警告信息提供自定义的消息，这使得该属性在实践中更加灵活和有用。

```cpp
[[nodiscard("Check the error code to handle potential failures")]]
ErrorInfo checkForErrorCxx20() {
    // 检查错误
    return ErrorInfo();
}
```

通过使用`[[nodiscard]]`，你可以设计出更加健壮和安全的接口，减少因忽略重要返回值而引发的潜在错误。

---

`if constexpr` 是 C++17 引入的一项特性，它允许在编译时根据条件是否为真来展开不同的模板代码路径。与传统的 `if` 语句不同，`if constexpr` 的条件必须是一个常量表达式。这意味着条件的值必须在编译时就可以确定，编译器会根据这个条件来决定是否保留或丢弃 `if` 或 `else` 块内的代码。

这项特性对模板编程尤其有用，因为它可以用于根据模板参数在编译时做出决策，从而避免不必要的编译时递归或生成不可用代码。

### 使用示例

```cpp
#include <iostream>
#include <type_traits>

template <typename T>
void process(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integer number: " << value << std::endl;
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Floating point number: " << value << std::endl;
    } else {
        std::cout << "Not a number\n";
    }
}

int main() {
    process(10);    // 调用 process<int>
    process(3.14);  // 调用 process<double>
    process("C++"); // 调用 process<const char*>
    return 0;
}
```

在这个例子中，函数`process`是一个模板函数，它接受任意类型的参数。在函数内部，它会使用`if constexpr`检查参数`T`的类型，并且只有符合条件的代码块会被编译器保留。如果传递给`process`的是一个整数类型，就只会保留第一个`if constexpr`块。如果是浮点数，就只保留第二个`else if constexpr`块。如果是其他类型，则只保留最后一个`else`块。

### 应用于模板编程

`if constexpr`在模板编程中的一个典型应用是，它可以用于替代基于特化的编译时决策过程（例如 SFINAE 技术）。它简��了代码，使模板元编程更加直观，并且可以显著提升编译器对于不同模板实例化的处理性能。

另一个应用例子是带有递归展开的可变参数模板：

```cpp
template<typename T>
void print(T t) {
    std::cout << t << std::endl;  // Base case for a single argument
}

template<typename First, typename... Rest>
void print(const First& first, const Rest&... rest) {
    std::cout << first << ", ";
    if constexpr (sizeof...(rest) > 0) {
        print(rest...);  // Recursive call only if more arguments are present
    }
}
```

在这个递归 `print` 函数的例子中，我们使用 `if constexpr` 来检查是否有更多的参数需要打印。如果 `sizeof...(rest)` 为 `0`，编译器在实例化时不会生成更多的 `print` 函数调用，从而在达到基本情况时终止递归。

### 注意事项

尽管 `if constexpr` 提供了强大的编译时决策能力，但使用它也需要注意不能滥用。在某些情况下，过分依赖 `if constexpr` 可能会导致代码的复杂性增加，特别是当条件非常多或者嵌套深时。正确使用`if constexpr`可以优化你的模板代码，提高执行效率，并且增强代码的可读性和可维护性。