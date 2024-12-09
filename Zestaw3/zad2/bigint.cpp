#include <iostream>
#include <string>
#include "bigint.h"

BigInt::BigInt() : digits_("0") {} // konstruktor domyślny, inicjujący liczbę na zero
BigInt::BigInt(const std::string& digits) : digits_(digits) {} // konstruktor z parametrem, inicjujący liczbę podanym łańcuchem znaków
BigInt::BigInt(const BigInt& other) : digits_(other.digits_) {} // konstruktor kopiujący

BigInt& BigInt:: operator=(const BigInt& other) { // operator przypisania
    if (this != &other) {
        digits_ = other.digits_;
    }
    return *this;
}

BigInt BigInt::add(const BigInt& other) const { // dodawanie
    std::string result;
    int carry = 0;
    int i = digits_.size() - 1;
    int j = other.digits_.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += digits_[i--] - '0';
            }
            if (j >= 0) {
                sum += other.digits_[j--] - '0';
            }
            result += std::to_string(sum % 10);
            carry = sum / 10;
        }

    std::reverse(result.begin(), result.end());
    return BigInt(result);
    }

BigInt BigInt::subtract(const BigInt& other) const { // odejmowanie
    std::string result;
    int borrow = 0;
    int i = digits_.size() - 1;
    int j = other.digits_.size() - 1;

    while (i >= 0 || j >= 0) {
        int diff = borrow;
        if (i >= 0) {
            diff += digits_[i--] - '0';
        }
        if (j >= 0) {
            diff -= other.digits_[j--] - '0';
        }
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        result += std::to_string(diff);
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return BigInt(result);
}

void BigInt::print() const { // wypisywanie
    std::cout << digits_ << std::endl;
}
