#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

template <typename T> void printArray(const std::vector<T> &arr) {
  std::cout << '(';
  for (std::size_t i{0}; i < std::size(arr); ++i) {
    std::cout << arr[i];
    if (i != std::size(arr) - 1) {
      std::cout << ", ";
    }
  }
  std::cout << ')';
  std::cout << '\n';
}

template <typename T> void findElement(const std::vector<T> &arr, T element) {
  for (std::size_t i{0}; i < std::size(arr); ++i) {
    if (arr[i] == element) {
      std::cout << "The element " << element << " has index " << i
                << " in the array" << '\n';
      return;
    }
  }
  std::cout << "The element " << element << " was not find in the array"
            << '\n';
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clearFailedExtraction() {
  if (std::cin.eof()) // If the stream was closed
  {
    std::exit(0); // Shut down the program now
  }
  std::cin.clear();
}

void invalidInputCheck() {
  if (!std::cin) {
    clearFailedExtraction();
  }
  ignoreLine();
}

auto getInput() {
  double input{};
  do {
    std::cout << "Enter a number: ";
    std::cin >> input;
    invalidInputCheck();
  } while (input < 1 || input > 10);
  return input;
}

int main() {
  auto input{getInput()};
  std::vector arr{4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9};
  findElement<double>(arr, input);
  printArray(arr);

  return 0;
}
