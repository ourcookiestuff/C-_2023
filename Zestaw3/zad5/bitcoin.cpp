#include "sha256.h"
#include <climits>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// funkcja do generowania losowego ciągu znaków o zadanej długości
string generateRandomString(int length) {
  static const char alphanum[] = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
  string str;
  for (int i = 0; i < length; ++i) {
    str += alphanum[rand() % (sizeof(alphanum) - 1)];
  }
  return str;
}

int main() {
  // stworzenie nowego obiektu haszującego
  SHA256 sha256;
  
  // ustawienie ziarna dla funkcji generującej losowe liczby
  srand(time(nullptr));

  // inicjalizacja zmiennej nonce
  int nonce = 0;

  // ustalenie poziomu trudności
  int difficulty = 6;

  // inicjalizacja zmiennej hash
  string hash;

  // rozpoczęcie pomiaru czasu
  clock_t start = clock();

  // generowanie losowego ciągu znaków
  string message = generateRandomString(16);

  // pętla symulująca proces "kopania"
  for (nonce = 0; nonce < INT_MAX; ++nonce) {
    // dodanie wartości zmiennej nonce do ciągu
    string message_with_nonce = message + to_string(nonce);

    // obliczenie funkcji skrótu SHA256 dla ciągu
    hash = sha256(message_with_nonce);

    // sprawdzenie, czy wynikowa suma kontrolna spełnia wymagania trudności
    bool found = true;
    for (int i = 0; i < difficulty; ++i) {
      if (hash[i] != '0') {
        found = false;
        break;
      }
    }
    if (found) {
      break;
    }
  }

  // zakończenie pomiaru czasu
  clock_t end = clock();

  // obliczenie czasu trwania procesu "kopania"
  double duration = double(end - start) / CLOCKS_PER_SEC;

  // wyświetlenie wyniku
  cout << "Hash: " << hash << endl;
  cout << "Nonce: " << nonce << endl;
  cout << "Duration: " << duration << "s" << endl;
}