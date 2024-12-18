#include <compare>
#include <cstring>
#include <iostream>
#include <string>

class TKlasa {
public:
  TKlasa(const char *c) : str(c) {}
  const char *operator[](const char *s) const {
    const char *pos = std::strstr(str.c_str(), s);
    return pos ? pos : nullptr;
  }
  auto operator<=>(const TKlasa &other) const = default;

private:
  std::string str;
};

int main() {
  TKlasa k("Ala ma kota");

  const char *p = k["ma"];
  if (p) {
    std::cout << "Znaleziono podciag: " << p << '\n';
  } else {
    std::cout << "Nie znaleziono podciagu.\n";
  }

  TKlasa k2("Ala ma psa");
  if (k < k2) {
    std::cout << "Obiekt k jest mniejszy od obiektu k2.\n";
  } else if (k > k2) {
    std::cout << "Obiekt k jest wiekszy od obiektu k2.\n";
  } else {
    std::cout << "Obiekty k i k2 sa sobie rowne.\n";
  }
}
