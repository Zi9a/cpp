#include <bitstring.h>
#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>

auto appendElementsToVector(int size) {
  std::vector<int> tempVector{};
  for (std::size_t i{1}; i <= size; ++i) {
    tempVector.push_back(i);
  }
  return tempVector;
}

void fizzBuzz(std::vector<int> integerList) {
  std::vector<std::string_view> buzzWords{"fizz", "buzz", "pop", "bang",
                                          "jaz",  "pow",  "boom"};
  std::vector<int> primeList{3, 5, 7, 11, 13, 17, 19};

  for (std::size_t i{0}; i < std::size(integerList); ++i) {
    int j = 0;
    bool isPrimeDivisor{};
    bool printedOnce{};
    while (j < std::size(primeList)) {
      if (integerList[i] % primeList[j] == 0) {
        std::cout << buzzWords[j];
        isPrimeDivisor = true;
        std::cout << '\n';
      }
      j++;
    }
    if (!printedOnce && !isPrimeDivisor) {
      std::cout << integerList[i];
      printedOnce = true;
      std::cout << '\n';
    }
  }
  std::cout << '\n';
}

int main() {
  std::vector<int> integerList(150);
  integerList = appendElementsToVector(std::size(integerList));

  fizzBuzz(integerList);
  return 0;
}
