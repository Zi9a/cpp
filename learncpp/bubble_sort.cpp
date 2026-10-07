#include <iostream>
#include <iterator>
#include <utility>

int main() {
  int array[]{6, 3, 2, -1, 7, 1, 5, 4, 8};

  for (int i{}; i < std::size(array) - 1; ++i) {
    bool swaps_done{false};
    for (int j{}; j < std::size(array) - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
        swaps_done = true;
      }
    }

    if (!swaps_done) {
      break;
    }

    for (auto element : array) {
      std::cout << element << ' ';
    }
    std::cout << " (" << i + 1 << ") " << '\n';
  }

  return 0;
}
