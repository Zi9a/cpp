#include <functional>
#include <ios>
#include <iostream>
#include <limits>

using ArithmeticFunction = std::function<int(int, int)>;

char getOperator() {
  char op{};
  do {
    std::cout << "Enter the operator ( + | - | * | / ): ";
    std::cin >> op;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (!(op == '+' || op == '-' || op == '*' || op == '/'));

  return op;
}

int getInteger() {
  int x{};
  std::cout << "Enter an integer: ";
  std::cin >> x;
  return x;
}


int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

ArithmeticFunction getArithmeticFunction(char ch) {
  switch (ch) {
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
  }
  return nullptr;
}

int main() {
  int x{ getInteger() };
  char op{ getOperator() };
  int y{ getInteger() };

  ArithmeticFunction func{ getArithmeticFunction(op) };
  if (func) {
    std::cout << x << ' ' << op << ' ' <<  y << " = " << func(x, y) << '\n';
  }
  return 0;
}
