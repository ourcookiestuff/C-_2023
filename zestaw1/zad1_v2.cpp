#include <iomanip>
#include <iostream>
#include <format>

int main() {
  int z=10, w=6;
  
  std::cout << "\n";
  int licznik = (z - w) / 2;
  for (int i = 1; i <= z; i++) {
    if (i <= licznik || i > z - licznik)
      std::cout << std::format("{:*<{}}", "", z);
    else {
      std::cout << std::format("{:*<{}}", "", licznik);
      std::cout << std::format("{:<{}}", "", w);
      std::cout << std::format("{:*<{}}", "", licznik);
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
