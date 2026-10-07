#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Random.h"

std::vector<int> getList(int start, int limit, int multiplyer) {
  std::vector<int> list{};
  for(int i{}; i < limit; ++i) {
    list.push_back(start * start * multiplyer);
    start++;
  }
  return list;
}

std::vector<int> generateList() {
  std::cout << "Start Where? ";
  int start{};
  std::cin >> start;

  std::cout << "How many? ";
  int limit{};
  std::cin >> limit;


  int multiplyer{ Random::get(2, 4) };

  std::cout << "I generated " << limit
            << " square numbers. Do you know what each number is after "
               "multiplying it by "
            << multiplyer << " ?\n";

  return getList(start, limit, multiplyer);
}

int getInputValue() {
  int input{};

  std::cout << "> ";
  std::cin >> input;

  return input;
}

void findFailed(auto list, int inputValue) {
  std::cout << "Wrong!\n";

  auto closest{
    std::min_element(list.begin(), list.end(), [=](int a, int b){
      return std::abs(inputValue - a) < std::abs(inputValue - b);
    })
  };

  std::cout << "Try, " << *closest << " next time" << '\n';
}

void removeFoundNumber(std::vector<int>& list, auto found) {
  list.erase(found);
  std::cout << "Nice! " << list.size() << " numbers left in the list" << '\n';
}

int main() {
  std::vector list { generateList() };
  while (list.size() > 0) {
    int inputValue{ getInputValue() };
    auto found = std::find( list.begin(), list.end(), inputValue);

    if (found == list.end()) {
      findFailed(list, inputValue);
      return 0;
    }
    if (list.size() == 1) {
      std::cout << "congratulations! You found all the numbers!!!" << '\n';
      return 0;
    }

    removeFoundNumber(list, found);
  }

  return 0;
}
