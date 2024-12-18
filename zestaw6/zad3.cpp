#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <experimental/iterator>

int main() {
    std::map<int, std::string> mis = {
        {0, "zero"},
        {1, "jeden"},
        {2, "dwa"},
        {3, "trzy"},
        {4, "cztery"},
        {5, "pięć"},
        {6, "sześć"},
        {7, "siedem"},
        {8, "osiem"},
        {9, "dziewięć"}
    };

    std::vector<int> numbers = {1, 4, 9, 2, 7};

    std::transform(numbers.begin(), numbers.end(), std::experimental::make_ostream_joiner(std::cout, " "),
                   [&mis](int num) {
                       return mis[num];
                   });

}
