#include <iostream>
#include <string>
#include <string_view>

class MyString {
private:
  std::string m_string{};

public:
  MyString(std::string_view string) : m_string{string} {}
  std::string_view operator()(int, int) const;
};

std::string_view MyString::operator()(int index, int limit) const {
  return std::string_view{m_string}.substr(index, limit);
}

int main() {
  MyString s{"Hello, world!"};
  std::cout << s(7, 5) << '\n';

  return 0;
}
