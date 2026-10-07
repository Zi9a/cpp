#include <ios>
#include <iostream>
#include <numeric> // for std::gcd

class Fraction {
private:
  int m_numerator{};
  int m_denominator{};

public:
  Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator} {
    reduce();
  }

  void reduce() {
    int gcd{std::gcd(m_numerator, m_denominator)};
    if (gcd) {
      m_numerator /= gcd;
      m_denominator /= gcd;
    }
  }

  friend Fraction operator*(const Fraction &f1, const Fraction &f2);
  friend Fraction operator*(const Fraction &f1, int value);
  friend Fraction operator*(int value, const Fraction &f1);

  friend std::ostream &operator<<(std::ostream &, const Fraction &);
  friend std::istream &operator<<(std::istream &, Fraction &);

  void print() const {
    std::cout << m_numerator << '/' << m_denominator << '\n';
  }
};

Fraction operator*(const Fraction &f1, const Fraction &f2) {
  return Fraction{f1.m_numerator * f2.m_numerator,
                  f1.m_denominator * f2.m_denominator};
}

Fraction operator*(const Fraction &f1, int value) {
  return Fraction{f1.m_numerator * value, f1.m_denominator};
}

Fraction operator*(int value, const Fraction &f1) {
  return Fraction{f1.m_numerator * value, f1.m_denominator};
}

std::ostream &operator<<(std::ostream &out, const Fraction &frac) {
  if (frac.m_denominator == 1) {
    std::cout << frac.m_numerator;
  } else {
    std::cout << frac.m_numerator << '/' << frac.m_denominator;
  }
  return out;
}

std::istream &operator>>(std::istream &in, Fraction &frac) {
  int x{};
  char op{};
  int y{};

  in >> x >> op >> y;
  if (y == 0) {
    in.setstate(std::ios_base::failbit);
  } else {
    frac = Fraction{x, y};
  }

  return in;
}

int main() {
  Fraction f1{};
  std::cout << "Enter fraction 1: ";
  std::cin >> f1;

  Fraction f2{};
  std::cout << "Enter fraction 2: ";
  std::cin >> f2;

  std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; 

  return 0;
}
