#include <iostream>

int sumOfDigit(int x) {
  if (x % 10 == 0) {
    return x;
  }
  return x % 10 + sumOfDigit(x / 10);
}

int main() {
  int x{93427};
  std::cout << sumOfDigit(x) << '\n';
  return 0;
}
