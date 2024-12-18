#include <iostream>
#include <string>

std::string arabicToRoman(int number) {
  std::string result = "";
  int arabicNums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  std::string romanNums[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                             "XL", "X",  "IX", "V",  "IV", "I"};

  // Konwersja liczby
  for (int i = 0; i < 13; ++i) {
    while (number >= arabicNums[i]) {
      result += romanNums[i];
      number -= arabicNums[i];
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("BŁĄD podanej wartości!!!\n");
    return 0;
  }
  int number;
  number = atoi(argv[1]);
  // Sprawdzenie poprawności liczby
  if (number < 1 || number > 3999) {
    std::cout << "Nieprawidłowa liczba";
    return 0;
  }
  std::cout << "Liczba rzymska: ";
  std::cout << arabicToRoman(number) << "\n";
}
