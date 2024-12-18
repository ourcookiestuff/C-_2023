#include <algorithm>
#include <iostream>

class TArr {
private:
  struct InnerArray {
    std::size_t len{0};
    std::size_t ref{0};
    int *buf{nullptr};

    InnerArray(std::size_t len) : len(len), ref(1), buf(new int[len]) {}

    InnerArray(const InnerArray &other)
        : len(other.len), ref(1), buf(new int[len]) {
      std::copy(other.buf, other.buf + len, buf);
    }

    InnerArray(InnerArray &&other) noexcept
        : len(other.len), ref(1), buf(other.buf) {
      other.len = 0;
      other.ref = 0;
      other.buf = nullptr;
    }

    ~InnerArray() { delete[] buf; }
  } * ptr{nullptr};

  void ensure_unique() {
    if (ptr->ref > 1) {
      InnerArray *new_ptr = new InnerArray(*ptr);
      --ptr->ref;
      ptr = new_ptr;
    }
  }

public:
  TArr(std::size_t len) : ptr(new InnerArray(len)) {}

  TArr(const TArr &other) : ptr(other.ptr) { ++ptr->ref; }

  TArr(TArr &&other) noexcept : ptr(other.ptr) { other.ptr = nullptr; }

  ~TArr() {
    if (ptr && --ptr->ref == 0) {
      delete ptr;
    }
  }

  TArr &operator=(const TArr &other) {
    if (ptr != other.ptr) {
      if (ptr && --ptr->ref == 0) {
        delete ptr;
      }
      ptr = other.ptr;
      ++ptr->ref;
    }
    return *this;
  }

  TArr &operator=(TArr &&other) noexcept {
    if (ptr != other.ptr) {
      if (ptr && --ptr->ref == 0) {
        delete ptr;
      }
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  void set_value(std::size_t index, int value) {
    ensure_unique();
    ptr->buf[index] = value;
  }

  std::size_t ref_count() const { return ptr ? ptr->ref : 0; }
};

int main() {
  TArr a(10);
  TArr b(a);
  std::cout << a.ref_count() << std::endl; // Output: 2
  b.set_value(0, 1);
  std::cout << a.ref_count() << std::endl; // Output: 1
  TArr c(std::move(b));
  std::cout << a.ref_count() << std::endl; // Output: 1
  std::cout << c.ref_count() << std::endl; // Output: 1
  TArr d(5);
  d = c;
  std::cout << c.ref_count() << std::endl; // Output: 2
  std::cout << d.ref_count() << std::endl; // Output: 2
  TArr e(3);
  e = std::move(d);
  std::cout << d.ref_count() << std::endl; // Output: 0
  std::cout << e.ref_count() << std::endl; // Output: 2
}