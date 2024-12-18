#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// Struktura funktora do sortowania wektora
struct CustomSort {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    std::vector<int> vec(100);

    // Wypełnij wektor wartościami od 1 do 100 za pomocą algorytmu iota
    std::iota(vec.begin(), vec.end(), 1);

    // Wymieszaj zawartość wektora za pomocą algorytmu shuffle
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(vec.begin(), vec.end(), rng);
    
    std::cout << "Wektor po wymieszaniu:\n";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Posortuj kopię zawartości wektora od największej do najmniejszej wartości
    std::vector<int> sortedCopy(vec);
    std::sort(sortedCopy.begin(), sortedCopy.end(), std::greater<int>());
    
    std::cout << "Kopia wektora posortowana algorytmem sort:\n";
    for (int num : sortedCopy) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sortowanie kopii z użyciem obiektu funkcyjnego
    std::vector<int> copyWithCustomSort(vec);
    std::sort(copyWithCustomSort.begin(), copyWithCustomSort.end(), CustomSort());

    std::cout << "Kopia wektora posortowana z użyciem obiektu funkcyjnego:\n";
    for (int num : copyWithCustomSort) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    // Sortowanie za pomocą wyrażenia lambda i "nietypowego" kryterium
    std::vector<int> copyWithLambda(vec);
    std::sort(copyWithLambda.begin(), copyWithLambda.end(), [](int a, int b) {
        std::string a_str = std::to_string(a);
        std::string b_str = std::to_string(b);
        
        // Porównujemy najpierw cyfry jedności
        if (a_str[0] != b_str[0]) {
            return a_str[0] < b_str[0];
        }
        
        // Jeśli cyfry jedności są takie same, porównujemy całe liczby
        return a < b;
    });

    std::cout << "Kopia wektora posortowana za pomocą wyrażenia lambda:\n";
    for (int num : copyWithLambda) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}
