#include <iostream>
using namespace std;

void fibonacci(int n) {
  int a = 0, b = 1, next;

  cout << "Fibonacci sequence up to " << n << " terms:" << endl;

  for (int i = 0; i < n; ++i) {
    cout << a << " ";
    next = a + b;
    a = b;
    b = next;
  }

  cout << endl;
}

int main() {
  int terms;
  cout << "Enter the number of terms: ";
  cin >> terms;

  if (terms <= 0) {
    cout << "Please enter a positive integer." << endl;
  } else {
    fibonacci(terms);
  }

  return 0;
}
