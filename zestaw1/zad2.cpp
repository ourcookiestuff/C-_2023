#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;

int main()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    
    std::cout << "Podaj pierwszy ciag znakow: ";
    std::cin.getline(str1, MAX_SIZE);
    
    std::cout << "Podaj drugi ciag znakow: ";
    std::cin.getline(str2, MAX_SIZE);
    
    if (strlen(str1) != strlen(str2))
    {
        std::cout << "Ciągi znaków są różnej długości.\n";
        return 0;
    }
    
    for (int i = 0; i < strlen(str1)/2; i++)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            std::cout << "Ciągi znaków są różne.\n";
            return 0;
        }
    }
    
    std::cout << "Ciągi znaków są identyczne.\n";
    
}

