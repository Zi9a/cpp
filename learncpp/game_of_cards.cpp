#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

namespace itemType {
enum Item {
  health_potions,
  torches,
  arrows,
  total_items,
};

}

int total_items_sum(std::vector<int> &number) {
  int sum = 0;
  for (auto element : number) {
    sum += element;
  }
  return sum;
}

std::string_view get_item_name(int item) {
  switch (item) {
  case itemType::health_potions:
    return "health_potions";

  case itemType::torches:
    return "torches";

  case itemType::arrows:
    return "arrows";

  default:
    return "NOT AVAILABLE";
  }
}

int main() {
  int health_potion_number = 1;
  int torch_number = 5;
  int arrow_number = 10;

  std::vector number{health_potion_number, torch_number, arrow_number};
  assert(itemType::total_items == std::size(number));

  for (int element{0}; element < itemType::total_items; ++element) {
    std::cout << "You have " << number[element] << " number of "
              << get_item_name(static_cast<itemType::Item>(element)) << '\n';
  }
  std::cout << "You have " << total_items_sum(number) << " of Items" << '\n';
}
