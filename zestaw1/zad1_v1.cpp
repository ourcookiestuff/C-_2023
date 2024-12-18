#include <iomanip>
#include <iostream>

int main() {
  int z, w;
  std::cout << "Podaj rozmiar dla kwadratu zwenętrznego: ";
  std::cin >> z;
  std::cout << "Podaj rozmiar dla kwadratu wewnętrznego: ";
  std::cin >> w;
  while (z <= w || (z - w) % 2 != 0) {
    if (z <= w)
      std::cout << "\nBLAD!!! Druga wartość nie może być większa lub równa "
                   "pierwszej!!!\n\n";
    else if ((z - w) % 2 != 0)
      std::cout << "\nBLAD!!! Podane liczby mogą być tylko nieparzyste lub "
                   "parzyste!!!\n\n";
    std::cout << "Podaj rozmiar dla kwadrata zwenętrznego: ";
    std::cin >> z;
    std::cout << "Podaj rozmiar dla kwadrata wewnętrznego: ";
    std::cin >> w;
  }
  std::cout << "\n";
  int licznik = (z - w) / 2;
  for (int i = 1; i <= z; i++) {
    if (i <= licznik || i > z - licznik)
      std::cout << std::setfill('x') << std::setw(z) << "";
    else {
      std::cout << std::setfill('x') << std::setw(licznik) << "";
      std::cout << std::setfill(' ') << std::setw(w) << "";
      std::cout << std::setfill('x') << std::setw(licznik) << "";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
