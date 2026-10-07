#include <iostream>

void binary(unsigned int x) {
  if (x == 0) {
    return;
  }
  binary(x / 2);
  std::cout << x % 2;
}

int main() {
  int x = -15;
  binary(x);
  return 0;
}
