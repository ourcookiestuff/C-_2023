#include <iostream>
#include <random>
#include <vector>

void quicksort(std::vector<int> &arr, int lewo, int prawo) {
  int i = lewo, j = prawo;
  int pivot = arr[(lewo + prawo) / 2];

  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  if (lewo < j) {
    quicksort(arr, lewo, j);
  }
  if (i < prawo) {
    quicksort(arr, i, prawo);
  }
}

int main() {
  std::vector<int> arr;

  // Generowanie 10000 losowych liczb
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 10000);

  for (int i = 0; i < 10000; i++) {
    arr.push_back(distrib(gen));
  }

  // Wyświetlenie nieposortowanych wartości
  std::cout << "Nieposortowane wartości:" << std::endl;
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  // Sortowanie
  quicksort(arr, 0, arr.size() - 1);

  // Wyświetlenie posortowanych wartości
  std::cout << "Posortowane wartości:" << std::endl;
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
