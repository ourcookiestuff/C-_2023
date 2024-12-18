#include <iostream>

const int MAX_SIZE = 100;
unsigned long long tab[MAX_SIZE] = {0, 1};

unsigned long long fib_rek(unsigned long long n)
{
    if (n < 2)
    {
        return tab[n];
    }
    else if (tab[n] != 0)
    {
        return tab[n];
    }
    else
    {
        tab[n] = fib_rek(n-1) + fib_rek(n-2);
        return tab[n];
    }
}

unsigned long long fib_it(unsigned long long n)
{
    if (n < 2)
    {
        return tab[n];
    }
    else
    {
        for (unsigned long long i = 2; i <= n; i++)
        {
            if (tab[i] == 0)
            {
                tab[i] = tab[i-1] + tab[i-2];
            }
        }
        return tab[n];
    }
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
