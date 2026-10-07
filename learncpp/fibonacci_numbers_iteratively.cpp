#include <iostream>

int fibonacci(int x) {
  int first = 0;
  int second = 1;
  int answer = 0;
  for(int i{2}; i<x; ++i) {
    answer = first + second;
    first = second;
    second = answer;
  }
  return answer;
}

int main() {
  int x = 5;

  for(int i = 1; i <= 13; ++i) {
    std::cout << fibonacci(i) << ' ';
  }
  std::cout << '\n';

  return 0;
}
