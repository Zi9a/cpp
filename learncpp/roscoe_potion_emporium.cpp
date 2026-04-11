// Roscoe’s potion emporium

#include <array>
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <string_view>

#include "random.h"

namespace Potion {
enum Type {
  health,       // 0
  mana,         // 1
  speed,        // 2
  invisibility, // 3
  max_potion,   // 4
};

constexpr std::array types{health, mana, speed, invisibility};
constexpr std::array cost{20, 30, 12, 50};
constexpr std::array<std::string_view, max_potion> potion_name{
    "health", "mana", "speed", "invisibility"};

static_assert((std::size(types) == max_potion),
              "types list mismatch to potion list");
static_assert((std::size(cost) == max_potion), //
              "cost mismatch to potion list");
static_assert((std::size(potion_name) == max_potion),
              "potion_name mismatch to potion list");
} // namespace Potion

void shop() {
  std::cout << '\n';
  std::cout << "Here's our selection for today: " << '\n';
  for (auto p : Potion::types) {
    std::cout << p << ") " << Potion::potion_name[p] << " costs "
              << Potion::cost[p] << '\n';
  }
}

struct Inventory {
  std::array<Potion::Type, Potion::max_potion> potion{};
  std::array<int, Potion::max_potion> potion_in_inventory{};
};

void handle_bad_input() {
  // clear the bad input
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "- Invalid Input!! Please Try Again...\n";
  std::cout << '\n';
}

void ignore_extraneous_input() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Player {
private:
  std::string name_m{};
  Inventory inventory_m{};
  int coins_m{};

public:
  Player() = default;
  Player(std::string_view name) : name_m{name} {}

  void ask_player_name() {
    while (true) {
      std::cout << "Enter Your Name: ";
      std::cin >> name_m;

      if (!std::cin) {
        handle_bad_input();
        continue;
      }
      ignore_extraneous_input();
      break;
    }
  }

  void display_initial_values() {
    coins_m = Random::get(1, 100);
    std::cout << "Hello, " << name_m << ", you have " << coins_m << " coins\n";
  }

  void select_shop_items() {
    int number_of_item_in_store{};
    while (true) {
      std::cout
          << "Enter the number of the potion you'd like to buy, or 'q' to "
             "quit: ";
      if (std::cin.peek() == 'q') {
        std::cout << '\n';
        std::cout << "Your inventory Contains: \n";
        for (auto i : Potion::types) {
          if (inventory_m.potion_in_inventory[i] == 0) {
            continue;
          }
          std::cout << "- " << "You Have " << inventory_m.potion_in_inventory[i]
                    << " " << Potion::potion_name[i]
                    << " Potions in your inventory\n";
        }

        std::cout << "- goodbye " << name_m << "...\n";
        std::exit(0);
      }

      std::cin >> number_of_item_in_store;
      if (!std::cin) {
        handle_bad_input(); // std::cin.clear() &&
                            // std::cin.ignore(std::numeric_limits<std::streamsize>::max())
        continue;
      }
      ignore_extraneous_input(); // std::cin.ignore(std::numeric_limits<std::streamsize>::max())

      if (number_of_item_in_store >= Potion::max_potion ||
          number_of_item_in_store < 0) {
        std::cout << "- Invalid Number! Please Try Again\n";
        std::cout << '\n';
        continue;
      }

      if (Potion::cost[number_of_item_in_store] > coins_m) {
        std::cout << "- You Need "
                  << Potion::cost[number_of_item_in_store] - coins_m
                  << " more Coins to buy a "
                  << Potion::potion_name[number_of_item_in_store] << " Potion."
                  << '\n';
        std::cout << "- coins_left: " << coins_m << '\n';
        std::cout << '\n';
        continue;
      }

      coins_m -= Potion::cost[number_of_item_in_store];
      std::cout << "- You've Purchased a "
                << Potion::potion_name[number_of_item_in_store] << " Potion\n";
      std::cout << "- You Have " << coins_m << " coins left\n";
      std::cout << '\n';

      inventory_m.potion[number_of_item_in_store] =
          Potion::types[number_of_item_in_store];
      inventory_m.potion_in_inventory[number_of_item_in_store]++;
    }
  }
};

int main() {
  Player player_one{"???"};
  std::cout << "Welcome to Roscoe's potion emporium!\n";

  player_one.ask_player_name();
  player_one.display_initial_values();
  shop();
  player_one.select_shop_items();

  std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";
  return 0;
}
