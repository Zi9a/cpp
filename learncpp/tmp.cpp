#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(12);

  std::cout << "sizeof v: " << std::size(v);
  std::cout << '\n';
  for(auto i : v) {
    std::cout << i << " ";
  }

  return 0;
}
