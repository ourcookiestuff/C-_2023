#include <iostream>
#include <initializer_list>

template <typename T>
auto fun(const std::initializer_list<T>& arg) {
    auto sum = T{};
    for (const auto& elem : arg) {
        sum += elem;
    }
    return sum;
}

int main() {
    auto arg1 = {1, 2, 3}; // initializer_list<int>
    auto arg2 = {1.6, 2.3, 3.6}; // initializer_list<double>

    auto result1 = fun(arg1); 
    auto result2 = fun(arg2); 

    std::cout << "Suma dla arg1: " << result1 << std::endl;
    std::cout << "Suma dla arg2: " << result2 << std::endl;

    return 0;
}
