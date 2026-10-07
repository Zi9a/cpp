#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


int main() {
  std::cout << "How many names would you like to enter? : ";
  int t;
  std::cin >> t;

  auto* names{ new std::string[t]{} };

  for(int i{}; i<t; ++i) {
    std::cout << "name #" << i+1 << ": ";
    std::cin >> *(names + i);
  }

  std::sort(names, names + t);

  std::cout << "Sorted names: \n";
  for(int i{}; i<t; ++i) {
    std::cout << "Name #" << i+1 << ": ";
    std::cout << names[i];
    std::cout << '\n';
  }

  delete[] names;

  return 0;
}
