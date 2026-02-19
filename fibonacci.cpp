#include <iostream>
#include <vector>

void fibonacci(int);

void fibonacci(int n) {
  int a = 0, b = 1, next;
  int values[10]{};
  std::vector<int> someIntValueVector{values} std::cout
      << "Fibonacci sequence up to " << n << " terms:" << '\n';

  for (int i = 0; i < n; ++i) {
    std::cout << a << " ";
    next = a + b;
    a = b;
    b = next;
  }
  std::cout << '\n';
  return;
}

int main() {
  int terms{10};
  std::cout << "Enter the number of terms: ";
  std::cin >> terms;
  std::cout << '\n';

  if (terms < 0) {
    std::cout << "Please enter a positive integer." << '\n';
  } else {
    fibonacci(terms);
  }
  return 0;
}
