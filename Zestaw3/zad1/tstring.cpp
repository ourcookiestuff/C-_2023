#include "tstring.h"
#include <iostream>

TString::TString(const std::string& s) {
#ifdef DEBUG
    std::cout << "TString c-tor: [" << str << "]" << std::endl;
#endif
}

TString::~TString() {
#ifdef DEBUG
    std::cout << "TString d-tor: [" << str << "]" << std::endl;
#endif
}

TString::TString(const TString& other) : str(other.str) {
#ifdef DEBUG
    std::cout << "TString cc-tor: [" << str << "]" << std::endl;
#endif
}

TString& TString::operator=(const TString& other) {
    if (this != &other) {
        str = other.str;
    }
#ifdef DEBUG
    std::cout << "TString copy operator=: [" << str << "]" << std::endl;
#endif
    return *this;
}

TString::TString(TString&& other) : str(std::move(other.str)) {
#ifdef DEBUG
    std::cout << "TString move c-tor: [" << str << "]" << std::endl;
#endif
}

TString& TString::operator=(TString&& other) {
    if (this != &other) {
        str = std::move(other.str);
    }
#ifdef DEBUG
    std::cout << "TString move operator=: [" << str << "]" << std::endl;
#endif
    return *this;
}
