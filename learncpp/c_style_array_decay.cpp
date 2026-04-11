// Write a function to print a C-style string character by character. Use a
// pointer and pointer arithmetic to step through each character of the string
// and print that character. Write a main function that tests the function with
// the string literal “Hello, world!”.

#include <iostream>
#include <iterator>

void print(const char *arr, int size) {
  const char *pointer{&arr[size]};
  int count{};
  while (pointer != arr) {
    std::cout << arr[count];
    ++count;
    --pointer;
  }

  std::cout << '\n';
}

int main() {
  const char print_statement[]{"Hello, World"};
  print(print_statement, std::size(print_statement));

  return 0;
}
