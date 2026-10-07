#include <iostream>
#include <ostream>

class IntArray {
private:
  int *arr{nullptr};
  int m_size{};

public:
  IntArray(int size) : m_size{size} { this->arr = new int[size]; }

  IntArray(const IntArray &cpy) : m_size{cpy.m_size} {
    this->arr = new int[this->m_size];
    for (int i{}; i < this->m_size; ++i) {
      this->arr[i] = cpy.arr[i];
    }
  }

  ~IntArray() {
    delete[] arr;
    arr = nullptr;
  }

  int &operator[](const int idx) { return this->arr[idx]; }

  IntArray &operator=(const IntArray &array) {
    if (this == &array)
      return *this;

    delete[] this->arr;

    this->m_size = array.m_size;
    arr = new int[static_cast<std::size_t>(this->m_size)]{};

    for (int count{0}; count < array.m_size; ++count)
      this->arr[count] = array.arr[count];

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &, IntArray);
};

std::ostream &operator<<(std::ostream &out, IntArray a) {
  for (int i = 0; i < a.m_size; ++i) {
    std::cout << a[i] << ' ';
  }
  return out;
}

IntArray fillArray() {
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main() {
  IntArray a{fillArray()};

  std::cout << a << '\n';

  auto &ref{a};
  a = ref;

  IntArray b(1);
  b = a;

  a[4] = 7;

  std::cout << b << '\n';

  return 0;
}
