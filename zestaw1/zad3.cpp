#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;

int main() {
  char wyraz[MAX_SIZE];
  char wyraz_bez[MAX_SIZE];

  std::cout<<"Podaj zdanie do sprawdzenia: \n";
  std::cin.getline(wyraz, MAX_SIZE);

  int dlugosc=strlen(wyraz);

  int j=0;
  for(int i=0; i<dlugosc; i++)
    {
      if(wyraz[i] != ' ')
      {
        wyraz_bez[j]=tolower(wyraz[i]);
        j++;
      }
    }
  wyraz_bez[j] = '\0';

  dlugosc = j;

  for(int i=0; i<dlugosc; i++)
    {
      if(wyraz_bez[i] != wyraz_bez[dlugosc-i-1])
      {
        std::cout<<"Zdanie nie jest palindromem.\n";
        return 0;
      }
    }

  std::cout<<"Zdanie jest palindromem.\n";
}