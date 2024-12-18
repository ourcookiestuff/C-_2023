#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

int main() {
    // a. Utworzenie obiektu vector<int>
    std::vector<int> numbers = {1, 2, 3, 4};

    // b. Wyrażenie lambda
    auto concatToString = [](const std::string& str, int num) {
        return str + "-" + std::to_string(num);
    };

    // c. Użycie accumulate
    auto it = numbers.begin();
    auto s = std::accumulate(std::next(it), numbers.end(), std::to_string(*it), concatToString);

    // Wypisanie wyniku
    std::cout << s << std::endl;
}
