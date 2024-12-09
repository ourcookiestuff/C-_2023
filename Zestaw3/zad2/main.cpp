#include <iostream>
#include <string>
#include "bigint.h"

int main() {
    BigInt a("12345678901234567890");
    BigInt b("98765432109876543210");

    BigInt c = a.add(b);
    c.print(); // wypisze "111111111111111111100"

    BigInt d = b.subtract(a);
    d.print(); // wypisze "86419753208641975320"
}