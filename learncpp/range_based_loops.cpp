#include <iostream>
#include <string_view>
#include <vector>

template <typename T> bool is_value_in_array(std::vector<T> &array, T element) {
  bool found{false};
  for (const auto &current_element : array) {
    if (element == current_element) {
      found = true;
    }
  }
  return found;
}

int main() {
  std::vector<std::string_view> names{"Alex",   "Betty", "Caroline", " Dave ",
                                      " Emily", "Fred",  " Greg",    " Holly "};
  std::string input_name{};
  std::cout << "enter the name: ";
  std::cin >> input_name;

  bool found = is_value_in_array<std::string_view>(names, input_name);
  if (found) {
    std::cout << input_name << " was found" << '\n';
  } else {
    std::cout << input_name << " was not found" << '\n';
  }
}
