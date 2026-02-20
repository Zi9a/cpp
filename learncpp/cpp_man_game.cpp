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

auto guess_random_word(std::string_view random_word) {
  char random_char{};
  std::string placeholder_string{};

  for (int i{}; i < random_word.size(); ++i) {
    if (random_char == random_word[i]) {
    }
  }
  return placeholder_string;
}

void print_guessed_word(std::string_view random_word) {
  std::string guessed_string{random_word};
  for (int i{}; i < guessed_string.size(); ++i) {
    guessed_string[i] = '_';
  }
  std::cout << guessed_string << '\n';
}

int main() {
  std::cout << " Welcome to C++ man(a variant of Hangman)\n To win : guess the "
               "word. ";
  std::cout << "\n To lose : run out of pluses.";
  std::cout << "\n The word is : ";

  std::string random_word{WordList::get_random_word()};

  print_guessed_word(random_word);
  std::cout << "\n The word is : ";
  std::cout << random_word << '\n';
  std::cout << '\n';

  return 0;
}
