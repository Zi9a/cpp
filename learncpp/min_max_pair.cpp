#include <iostream>
#include <utility>
#include <vector>

template <typename T> std::pair<T, T> get_min_max(std::vector<T> &num) {
  T min{};
  T max{};

  for (int v{0}; v < std::size(num); ++v) {
    if (num[v] > max) {
      max = num[v];
    }
  }

  // could've been better
  min = max;
  for (int v{0}; v < std::size(num); ++v) {
    if (num[v] < min) {
      min = num[v];
    }
  }

  return {min, max};
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction() {
  if (!std::cin) {
    if (std::cin.eof()) {
      std::exit(0);
    }

    std::cin.clear();
    ignoreLine();

    return true;
  }

  return false;
}

int main() {
  std::vector<int> vec{};
  bool firstExecution{true};

  do {
    double input{};

    std::cout << "Enter a positive integer (-1 to end): ";
    std::cin >> input;

    if (firstExecution && input == -1) {
      std::cout << "Oh, Uh! vector is empty, try again" << '\n';
      continue;
    }
    firstExecution = false;

    bool extractionFailed{clearFailedExtraction()};
    if (extractionFailed && input == 0) {
      continue;
    }

    if (input == -1) {
      break;
    }

    vec.push_back(input);
  } while (true);

  std::cout << "[ ";
  for (auto v : vec) {
    std::cout << v << " ";
  }
  std::cout << ']' << '\n';

  std::pair min_max{get_min_max(vec)};
  std::cout << "[" << min_max.first << ", " << min_max.second << "]" << "\n";

  return 0;
}
