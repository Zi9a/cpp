#include <iostream>

template <typename T> double pow(T base, T expo) {
  double result{1};

  bool less_than_one{false};
  if (expo < 0) {
    expo = -expo;
    less_than_one = true;
  }

  for (auto i{0}; i < expo; ++i) {
    result *= base;
  }

  if (less_than_one) {
    return 1 / result;
  }
  return result;
}

int main() {

  std::cout << pow('a', 1) << '\n';

  return 0;
}
