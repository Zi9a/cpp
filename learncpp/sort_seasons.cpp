#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string_view>

struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

int main()
{
  std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };

  std::sort(seasons.begin(), seasons.end(), 
            [](const auto& s, const auto next_s) {
    return s.averageTemperature < next_s.averageTemperature;
  });

  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }

  return 0;
}
