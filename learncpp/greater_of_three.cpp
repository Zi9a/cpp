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
  int a{35};
  int b{33};
  int c{5};

  std::cout << "Greater: " << findGreater(a, b, c) << '\n';

  return 0;
}
