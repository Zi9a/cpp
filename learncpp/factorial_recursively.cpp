#include <iostream>

int factorial(int x) {
  if (x == 1 || x == 0) {
    return 1;
  }
  return x * factorial(x - 1);
}

int main() {
  int x = 5;

  for(int i{}; i<10; ++i) {
    std::cout << i << ": " << factorial(i) << '\n';
  }

  return 0;
}
