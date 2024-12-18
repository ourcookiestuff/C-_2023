#include <iostream>
using namespace std;
#define P(x) std::cout << x << std::endl

class A1 {
  int i { 5 };
  public:
    A1(bool) { P("A1 c-tor"); } 
    virtual ~A1() { P("A1 d-tor"); } 
    int get() const { return i; }
};

class V1 : virtual public A1 { 
  public: 
    V1(bool) : A1(true) { P("V1 c-tor"); } 
    virtual ~V1() override { P("V1 d-tor"); }
};

class C1 : virtual public V1 {
public:
    C1(bool b) : A1(b), V1(b) { P("C1 c-tor"); }
    virtual ~C1() override { P("C1 d-tor"); }
};

class B2 {
public:
    B2(bool) { P("B2 c-tor"); }
    virtual ~B2() { P("B2 d-tor"); }
};

class B3 {
public:
    B3(bool) { P("B3 c-tor"); }
    virtual ~B3() { P("B3 d-tor"); }
};

class V2 : virtual public A1, public B2 {
public:
    V2(bool b) : A1(b), B2(b) { P("V2 c-tor"); }
    virtual ~V2() override { P("V2 d-tor"); }
};

class C2 : virtual public V2, public B3 {
public:
    C2(bool b) : A1(b), V2(b), B3(b) { P("C2 c-tor"); }
    virtual ~C2() override { P("C2 d-tor"); }
};

class M1 {
public:
    M1(bool) { P("M1 c-tor"); }
    virtual ~M1() { P("M1 d-tor"); }
};

class M2 {
public:
    M2(bool) { P("M2 c-tor"); }
    virtual ~M2() { P("M2 d-tor"); }
};

class X : public C1, public C2 {
    M1 m1;
    M2 m2;
public:
    X() : A1(true), V1(true), C1(true), V2(true), C2(true), m1(true), m2(true) { P("X c-tor"); }
    virtual ~X() override { P("X d-tor"); }
};


int main() {
  A1 *pa = new X;
  cout << pa->get() << endl; // zakomentować gdy public A1
  delete pa; 
}

/* 
  a) program wykonuj się tak samo
  b) A1 wykonuje się dwa razy
*/