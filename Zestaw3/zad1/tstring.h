#ifndef TSTRING_H
#define TSTRING_H

#include <cstring>
#include <iostream>

class TString
{
    public:
    TString(const std::string& s = std::string()); // c-tor
    TString(const TString& other); // cc-tor
    TString(TString&& other); // move c-tor
    TString& operator=(const TString& other); // copy operator=
    TString& operator=(TString&& other); // move operator=
    ~TString(); // d-tor

    private:
    std::string* str;
};

#endif // TSTRING_H