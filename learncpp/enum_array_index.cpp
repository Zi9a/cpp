#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

namespace Animal {
enum Names { chicken, dog, cat, elephant, duck, snake, max_animals };
const std::vector legs{2, 4, 4, 4, 2, 0};
}; // namespace Animal

int main() {
  std::vector<int> animal(Animal::max_animals);
  assert(std::size(animal) == Animal::max_animals);

  std::cout << "elephant has " << Animal::legs[Animal::elephant] << " legs"
            << '\n';
}
