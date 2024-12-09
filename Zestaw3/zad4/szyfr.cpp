#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// funkcja pomocnicza do sprawdzania czy liczba jest pierwsza
bool isPrime(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// funkcja pomocnicza do obliczania największego wspólnego dzielnika
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// funkcja pomocnicza do obliczania odwrotności modulo
int modInverse(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;
  if (m == 1) {
    return 0;
  }
  while (a > 1) {
    // q jest ilorazem a i m, t jest modyfikatorem m
    q = a / m;
    t = m;
    // m jest resztą z dzielenia a przez m
    m = a % m;
    a = t;
    t = x0;
    // modyfikacja x0 i x1
    x0 = x1 - q * x0;
    x1 = t;
  }
  // jeśli x1 jest ujemne, to dodajemy m0, żeby było dodatnie
  if (x1 < 0) {
    x1 += m0;
  }
  return x1;
}

// funkcja pomocnicza do generowania kluczy RSA
void generateKeys(int &p, int &q, int &n, int &phi, int &e, int &d) {
  // wybierz dwie losowe liczby pierwsze p i q
  p = rand() % 100 + 100;
  q = rand() % 100 + 100;
  while (!isPrime(p)) {
    p = rand() % 100 + 100;
  }
  while (!isPrime(q) || p == q) {
    q = rand() % 100 + 100;
  }

  // oblicz n i phi
  n = p * q;
  phi = (p - 1) * (q - 1);

  // wybierz losową liczbę e względnie pierwszą z phi
  do {
    e = rand() % phi + 2;
  } while (gcd(e, phi) != 1);

  // oblicz d
  d = modInverse(e, phi);
}

// funkcja pomocnicza do szyfrowania wiadomości
long long encrypt(long long m, long long e, long long n) {
  long long result = 1;
  for (long long i = 0; i < e; i++) {
    result = (result * m) % n;
  }
  return result;
}

// funkcja pomocnicza do deszyfrowania wiadomości
long long decrypt(long long c, long long d, long long n) {
  long long result = 1;
  for (long long i = 0; i < d; i++) {
    result = (result * c) % n;
  }
  return result;
}

int main() {
  srand(time(NULL));
  int p, q, n, phi, e, d;
  generateKeys(p, q, n, phi, e, d);
  cout << "Klucz publiczny: (" << e << ", " << n << ")" << endl;
  cout << "Klucz prywatny: (" << d << ", " << n << ")" << endl;

  int message, ciphertext, plaintext;
  cout << "Podaj wiadomość do zaszyfrowania: ";
  cin >> message;
  ciphertext = encrypt(message, e, n);
  cout << "Zaszyfrowana wiadomość: " << ciphertext << endl;
  plaintext = decrypt(ciphertext, d, n);
  cout << "Odszyfrowana wiadomość: " << plaintext << endl;
}
