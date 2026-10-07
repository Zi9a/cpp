#include <iostream>
#include <string_view>
#include <algorithm>
#include <string_view>
#include <vector>

struct StudentGrade {
  std::string name{};
  char grade{};
};

class GradeMap {
private:
  std::vector<StudentGrade> m_map{};

public:
  char& operator[](std::string_view key);
};

char& GradeMap::operator[](std::string_view key) {
  auto found{
    std::find_if(
      m_map.begin(), m_map.end(),
      [&](const StudentGrade &student) { return key == student.name; })};

  if (found != m_map.end()) {
    return found->grade;
  }

  return m_map.emplace_back(std::string{key}).grade;
}

int main() {
  GradeMap grades{};

  grades["Joe"] = 'A';
  grades["Frank"] = 'B';

  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

  return 0;
}
