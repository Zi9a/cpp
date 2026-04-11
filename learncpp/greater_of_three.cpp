#include <iostream>

int findGreater(int a, int b, int c) {
  int greater{a};
  if (b > greater) {
    greater = b;
  }
  if (c > greater) {
    greater = c;
  }
  return greater;
}

int main() {
  int a{20};
  int b{20};
  int c{30};

  std::cout << "Greater: " << findGreater(a, b, c) << '\n';

  return 0;
}
