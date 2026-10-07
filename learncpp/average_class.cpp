#include <cstdint>
#include <iostream>
#include <ostream>

class Average {
private:
  std::int32_t sum_m{};
  std::int32_t count_m{};

public:
  Average() = default;

  Average& operator+=(int x) {
    sum_m += x;
    count_m++;
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &, const Average &);
};

std::ostream &operator<<(std::ostream &out, const Average &obj) {
  if (obj.count_m == 0) {
    std::cout << 0;
    return out;
  }

  std::cout << static_cast<double>(obj.sum_m) / obj.count_m;
  return out;
}

int main() {
  Average avg{};
  std::cout << avg << '\n';

  avg += 4;
  std::cout << avg << '\n'; // 4 / 1 = 4

  avg += 8;
  std::cout << avg << '\n'; // (4 + 8) / 2 = 6

  avg += 24;
  std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

  avg += -10;
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

  (avg += 6) += 10;         // 2 calls chained together
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

  Average copy{avg};
  std::cout << copy << '\n';

  return 0;
}
