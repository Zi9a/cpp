#include <array>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <string>
#include <string_view>

namespace Animal {
enum Name {
  chicken,
  dog,
  cat,
  elephant,
  duck,
  snake,
  maxAnimal,
};

constexpr std::array name{chicken, dog, cat, elephant, duck, snake, maxAnimal};
struct Data {
  std::string name{};
  std::string sound{};
  int numberOfLegs{};
};

std::array<Data, maxAnimal> info{{
    {"chicken", "chuck", 2},
    {"dog", "woof", 4},
    {"cat", "meow", 4},
    {"elephant", "urmom", 4},
    {"duck", "quack", 2},
    {"snake", "hisss", 0},
}};
} // NameSpace Animal

std::istream &operator>>(std::istream &in, Animal::Name &animal) {

  std::string input{};
  std::getline(std::cin >> std::ws, input);
  for (std::size_t i{}; i < std::size(Animal::info); ++i) {
    if (Animal::info[i].name == input) {
      animal = static_cast<Animal::Name>(i);
      return in;
    }
  }

  in.setstate(std::ios_base::failbit);
  return in;
}

void printAnimalInfo(Animal::Name animal) {
  const Animal::Data &animal_data{Animal::info[animal]};
  std::cout << animal_data.name << " has " << animal_data.numberOfLegs
            << " legs and says " << animal_data.sound << '\n';
}

int main() {
  std::cout << "Enter An Animal: ";
  Animal::Name animal;
  std::cin >> animal;

  if (!std::cin) {
    std::cout << "invalid input" << '\n';
    std::cin.clear();
    std::exit(1);
  }

  printAnimalInfo(animal);

  // std::string name{};
  // std::cout << "enter the name of animal: ";
  // std::cin >> name;
  //
  // bool found{false};
  // for (auto &nameOfAnimal : Animal::animals) {
  //   if (name == nameOfAnimal.name) {
  //     std::cout << nameOfAnimal.name << " has " << nameOfAnimal.numberOfLegs
  //               << " legs and says " << nameOfAnimal.sound << '\n';
  //     found = true;
  //   }
  // }
  //
  // if (!found) {
  //   std::cout << name << " ain't an animal i've ever heard of " << '\n';
  // }
  //
  // std::cout << '\n';
  // std::cout << "here's a list of other animals: " << '\n';
  // for (auto &nameOfAnimal : Animal::animals) {
  //   if (name == nameOfAnimal.name) {
  //     continue;
  //   }
  //   std::cout << " -" << nameOfAnimal.name << " has "
  //             << nameOfAnimal.numberOfLegs << " legs and says "
  //             << nameOfAnimal.sound << '\n';
  // }
  //
  // return 0;
}
