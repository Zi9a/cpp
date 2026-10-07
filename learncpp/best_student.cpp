#include <algorithm>
#include <iostream>

struct Student {
  std::string name;
  int points;
};

int main() {
  constexpr std::array<Student, 8> arr{{{"Albert", 3},
                              {"Ben", 5},
                              {"Christine", 2},
                              {"Dan", 8}, // Dan has the most points (8).
                              {"Enchilada", 4},
                              {"Francis", 1},
                              {"Greg", 3},
                              {"Hagrid", 5}}};

  constexpr auto max {
    [](const auto &a, const auto &b) {
      return a.points < b.points;
    }
  };

  const auto best {std::max_element(arr.begin(), arr.end(), max)};

  std::cout << best->name << " is da best \n";

  return 0;
}
