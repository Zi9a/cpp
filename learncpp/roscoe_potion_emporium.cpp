// Roscoe’s potion emporium

#include <array>
#include <string_view>
namespace Potion {
enum Type {
  max_potion,
};

std::array<int, max_potion> cost{};
std::array<std::string_view, max_potion> potion_name{};

void shop() {}

} // namespace Potion

int main() { return 0; }
