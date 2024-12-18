#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void justifyText(const std::string& inputFileName, const int& columnWidth) {
    // Otwarcie pliku tekstowego do odczytu
    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku " << inputFileName << "\n";
        return;
    }

    // Utworzenie wektora, w którym przechowywane będą linie tekstu
    std::vector<std::string> lines;

    std::string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    // Przeprowadzenie wyrównywania tekstu
    for (const auto& l : lines) {
        std::stringstream ss(l);
        std::string word;
        std::string line = "";
        while (ss >> word) {
            if (line.size() + word.size() <= columnWidth) {
                line += word + " ";
            } else {
                int spacesToAdd = columnWidth - line.size();
                while (spacesToAdd > 0) {
                    for (int i = 0; i < line.size(); ++i) {
                        if (spacesToAdd == 0) {
                            break;
                        }
                        if (line[i] == ' ' && (i == 0 || line[i - 1] != ' ')) {
                            line.insert(i, " ");
                            spacesToAdd--;
                        }
                    }
                }
                std::cout << line << "\n";
                line = word + " ";
            }
        }
        int spacesToAdd = columnWidth - line.size();
        while (spacesToAdd > 0) {
            line += " ";
            spacesToAdd--;
        }
        std::cout << line << "\n";
    }
}

int main() {
    std::string fileName;
    int columnWidth;
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;
    std::cout << "Podaj szerokosc kolumny: ";
    std::cin >> columnWidth;

    // Wywołanie funkcji do wyrównywania tekstu
    justifyText(fileName, columnWidth);

}
