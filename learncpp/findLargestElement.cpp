#include <iostream>
#include <iterator>

template <typename T> T findMax(std::vector<T> &arr) {
  if (std::size(arr) < 1)
    return 0;
  T max{arr[0]};
  for (int i{0}; i < std::size(arr); ++i) {
    if (arr[i + 1] > max && i + 1 < std::size(arr)) {
      max = arr[i + 1];
    }
  }
  return max;
}

int main() {
  std::vector data1{84, 92, 76, 81, 56};
  std::cout << findMax(data1) << '\n';

  std::vector data2{-13.0, -26.7, -105.5, -14.8};
  std::cout << findMax(data2) << '\n';

  std::vector<int> data3{};
  std::cout << findMax(data3) << '\n';

  return 0;
}
