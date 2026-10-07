
#include <array>
#include <iostream>
#include <iterator>
#include <utility>

int main() {
  std::array array{30, 60, 20, 50, 40, 10};

  for (auto i : array) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  for (int i{}; i < std::size(array) - 1; ++i) {
    int smallIndex{i};
    for (int j{smallIndex + 1}; j < std::size(array); ++j) {
      if (array[j] > array[smallIndex]) {
        smallIndex = j;
      }
    }

    std::swap(array[i], array[smallIndex]);

    for (auto element : array) {
      std::cout << element << ' ';
    }
    std::cout << " (" << i << ") ";
    std::cout << '\n';
  }

  return 0;
}
