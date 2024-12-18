#include <iostream>

auto fibo = [](int n) {
    const auto inner_fibo = [](int n, const auto& impl) -> int {
        if (n <= 1)
            return n;
        else
            return impl(n - 1, impl) + impl(n - 2, impl);
    };
    
    return inner_fibo(n, inner_fibo);
};

int main() {
    for (int i = 0; i < 10; ++i) {
        std::cout << fibo(i) << " ";
    }
    
}
