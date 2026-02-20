#include "random.h"
#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>

namespace WordList {

std::vector list{"mystery", "broccoli",  "account",  "almost", "spaghetti",
                 "opinion", "beautiful", "distance", "luggage"};

std::string_view get_random_word() {
  return list[Random::get(0, std::size(list) - 1)];
}

} // namespace WordList

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

auto get_guessed_word(std::string_view word_to_be_guessed) {
  static std::string guessed_string{word_to_be_guessed};
  static bool first_guess{true};

  if (first_guess) {
    for (int i{}; i < guessed_string.size(); ++i) {
      guessed_string[i] = '_';
    }
    first_guess = false;
  }

  std::cout << "guess the string: " << guessed_string << '\n';
  std::cout << "string: ";
  std::string input_word{};
  std::cin >> input_word;
  clearFailedExtraction();

  for (int i{}; i < guessed_string.size(); ++i) {
    if (input_word[i] == word_to_be_guessed[i]) {
      guessed_string[i] = word_to_be_guessed[i];
    }
  }

  std::cout << guessed_string << '\n';

  return guessed_string;
}

int main() {
  std::cout << " Welcome to C++ man(a variant of Hangman)\n To win : guess the "
               "word. \n";
  std::cout << " To lose : run out of pluses.\n";

  std::string random_word{WordList::get_random_word()};

  int attempt{0};
  do {
    auto current_guessed_word{get_guessed_word(random_word)};

    if (current_guessed_word == random_word) {
      break;
    } else {
      std::cout << "keep trying!\n";
    }

  } while (attempt <= 3);

  std::cout << "\n The word is : ";
  std::cout << random_word << '\n';

  return 0;
}
