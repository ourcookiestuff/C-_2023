#include <iostream>
#include <algorithm>
#include <string>
#include "tstring.h"

using namespace std;

int main(){

    TString a("Hello");
    TString b(a);
    TString c(std::move(a));
    TString d;
    d = std::move(b);
    TString e = d;

    /*std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;*/
}
