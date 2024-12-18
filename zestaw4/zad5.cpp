#include <iostream>

class A {
private:
  int i;

public:

  A(int i = 0) : i{i} {}

  A& operator++() { // prefix ++
    ++i;
    return *this;
  }

  A operator++(int) { // postfix ++
    A temp = *this;
    ++*this;
    return temp;
  }

  A& operator--() { // prefix --
    --i;
    return *this;
  }

  A operator--(int) { // postfix --
    A temp = *this;
    --*this;
    return temp;
  }

  A& operator+() { // unary +
    i=(+i);
    return *this;
  }

  A& operator-() { // unary -
    i=(-i);
    return *this;
  }

  A operator+(const A& value) { // binary +
    return A(i+value.i);
  }

  A operator-(const A& value) { // binary -
    return A(i-value.i);
  }

  friend std::ostream& operator<<(std::ostream& os, A const num){
    os << num.i << std::flush;
    return os;
  }
};

int main() {
  A a(0);

  std::cout << "a = " << a << std::endl; // a = 0

  ++a;
  std::cout << "a = " << a << std::endl; // a = 1

  ++++a;
  std::cout << "a = " << a << std::endl; // a = 3

  ------a;
  std::cout << "a = " << a << std::endl; // a = 0

  a++++++;
  std::cout << "a = " << a << std::endl; // a = 1

  a------;
  std::cout << "a = " << a << std::endl; // a = 0
}
