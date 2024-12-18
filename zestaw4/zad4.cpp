#include <iostream>

template <typename T> class TSmartPtr {
private:
  T *fp{nullptr};
  T *fTable[5]{nullptr};
  int fUse{0};

public:
  explicit TSmartPtr(T *ptr = nullptr) : fp(ptr) {}
  T *operator->() {
    fTable[fUse] = fp;
    fUse = (++fUse) % 5;
    return fp;
  }
  T &operator*() { return *(operator->()); }
};

class A {
public:
  void funA() { std::cout << "funA()" << std::endl; }
};

int main() {
  A a;
  TSmartPtr<A> wsk(&a);
  wsk->funA();
  (*wsk).funA();
}
