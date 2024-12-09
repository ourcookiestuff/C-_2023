#ifndef BIGINT_H
#define BIGINT_H

#include <string>

class BigInt {
public:
    BigInt();
    BigInt(const std::string& digits);
    BigInt(const BigInt& other);

    BigInt& operator=(const BigInt& other);

    BigInt add(const BigInt& other) const;
    BigInt subtract(const BigInt& other) const;

    void print() const;

private:
    std::string digits_;
};

#endif // BIGINT_H
