#include <cstring>
#include <iostream>

unsigned long long fib_rek(unsigned long long liczba1)
{
	if (liczba1 < 3)
	 return 1;
	else
	 return fib_rek(liczba1-1)+fib_rek(liczba1-2);
}

unsigned long long fib_it(unsigned long long liczba1)
{
  unsigned long long x = 0, y = 1, z = 0;
   for (unsigned long long i = 0; i < liczba1; i++) {
      z = x + y;
      x = y;
      y = z;
     }
  return x; 
}

int main()
{
	unsigned long long k;
  char metoda;
  std::cout<<"Podaj matode: (1) iteracja; (2) rekurencja\n";
  std::cin>>metoda;
  if(metoda != '1' && metoda != '2')
    {
      std::cout<<"Blad podanej wartosci!!!\n";
      return 0;
    }
  std::cout<<"Podaj liczbe\n";
  std::cin>>k;
  if(metoda == '1')
  {
    for (unsigned long long i=1; i<=k; ++i) {
        std::cout << i << ". " <<  fib_it(i) << "\n";
    }
  }
  if(metoda == '2')
  {
    for (unsigned long long i=1; i<=k; ++i) {
        std::cout << i << ". " <<  fib_rek(i) << "\n";
    }
  }
}
