#include <iostream>
#include <list>
#include <set>
#include <iterator>
using namespace std;
int main() {
    list<char> myList{'a', 'c', 'b', 'd', 'f', 'e', 'h', 'g'};

    auto compare = [](const auto& l, const auto& r) {
        set<char> order{'a', 'c', 'b', 'd', 'f', 'e', 'h', 'g'};
        auto it_l = order.find(l);
        auto it_r = order.find(r);
        return it_l != order.end() && it_r != order.end() && it_l != it_r && *it_l < *it_r;
    };

    set<char, decltype(compare)> mySet({'a', 'a', 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'}, compare);

    for (auto c : mySet) {
        cout << c;
    }
}