
// A “perfect square” is a natural number whose square root is an integer. We
// can make perfect squares by multiplying a natural number (including zero) by
// itself. The first 4 perfect squares are: 0, 1, 4, 9.
//
// Use a global constexpr C-style array to hold the perfect squares between 0
// and 9 (inclusive). Repeatedly ask the user to enter a single digit integer,
// or -1 to quit. Print whether the digit the user entered is a perfect square.
//
// The output should match the following:
//
// Enter a single digit integer, or -1 to quit: 4
// 4 is a perfect square
//
// Enter a single digit integer, or -1 to quit: 5
// 5 is not a perfect square
//
// Enter a single digit integer, or -1 to quit: -1
// Bye
//

#include <ios>
#include <iostream>
#include <limits>
constexpr int perfect_square[]{0, 1, 4, 9};

constexpr bool is_single_digit_perfect_square(int digit) {
  for (const auto &i : perfect_square) {
    if (i == digit) {
      return true;
    }
  }
  return false;
}

constexpr void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
  int digit{};

  do {
    std::cout << "Enter a single digit integer, or -1 to quit: ";
    std::cin >> digit;

    if (!std::cin) {
      std::cin.clear();
      ignoreLine();
      std::cout << "Invalid input!" << '\n';
      continue;
    }

    if (digit == -1) {
      std::cout << "bye" << '\n';
      break;
    }

    if (digit < 0 || digit > 10) {
      std::cout << digit << " is not a single digit positive number" << '\n';
      continue;
    }

    if (is_single_digit_perfect_square(digit)) {
      std::cout << digit << " is a perfec square " << '\n';
    } else {
      std::cout << digit << " is not a perfect square " << '\n';
    }
  } while (digit != -1);

  return 0;
}
