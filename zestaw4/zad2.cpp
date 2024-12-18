#include <cmath>
#include <iostream>

class TComplex {
public:
  TComplex(double re, double im) : re{re}, im{im} {}
  TComplex operator()(double re, double im) const { return TComplex(re, im); }
  TComplex operator+(const TComplex &other) const {
    return TComplex(re + other.re, im + other.im);
  }
  TComplex operator-(const TComplex &other) const {
    return TComplex(re - other.re, im - other.im);
  }
  TComplex operator*(const TComplex &other) const {
    return TComplex(re * other.re - im * other.im,
                    re * other.im + im * other.re);
  }
  TComplex operator/(const TComplex &other) const {
    double denom = other.re * other.re + other.im * other.im;
    return TComplex((re * other.re + im * other.im) / denom,
                    (im * other.re - re * other.im) / denom);
  }
  TComplex conj() const { return TComplex(re, -im); }
  double abs() const { return std::sqrt(re * re + im * im); }

  friend std::ostream &operator<<(std::ostream &os, const TComplex &c);

private:
  double re{0}, im{0};
};

std::ostream &operator<<(std::ostream &os, const TComplex &c) {
  return os << '(' << c.re << ',' << c.im << ')';
}

int main() {
  TComplex c1(2, 3);
  TComplex c2(4, -1);
  TComplex c3 = c1 + c2;
  TComplex c4 = c1 - c2;
  TComplex c5 = c1 * c2;
  TComplex c6 = c1 / c2;
  TComplex c7 = c1.conj();
  double c8 = c1.abs();
  std::cout << "c1: " << c1 << '\n';
  std::cout << "c2: " << c2 << '\n';
  std::cout << "c1 + c2: " << c3 << '\n';
  std::cout << "c1 - c2: " << c4 << '\n';
  std::cout << "c1 * c2: " << c5 << '\n';
  std::cout << "c1 / c2: " << c6 << '\n';
  std::cout << "conj(c1): " << c7 << '\n';
  std::cout << "abs(c1): " << c8 << '\n';
}
