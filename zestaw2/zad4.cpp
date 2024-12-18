#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  std::cout << "Current path is " << fs::current_path() << '\n';
  // Zapytaj użytkownika o ścieżkę do katalogu
  std::cout << "Podaj ścieżkę do katalogu: ";
  std::string path_str;
  std::getline(std::cin, path_str);
  fs::path path(path_str);

  // Sprawdź, czy podana ścieżka istnieje i czy jest katalogiem
  if (!fs::exists(path)) {
    std::cerr << "Podana ścieżka nie istnieje.\n";
    return 1;
  }
  if (!fs::is_directory(path)) {
    std::cerr << "Podana ścieżka nie jest katalogiem.\n";
    return 1;
  }

  // Iteruj po plikach w katalogu i wypisz nazwy i rozmiary zwykłych plików
  bool found = false;
  for (const auto &entry : fs::directory_iterator(path)) {
    if (fs::is_regular_file(entry)) {
      std::cout << entry.path().filename().string() << " ("
                << fs::file_size(entry) << " bytes)\n";
      found = true;
    }
  }
  if (!found) {
    std::cout << "Nie znaleziono zwykłych plików w podanym katalogu.\n";
  }

  return 0;
}
