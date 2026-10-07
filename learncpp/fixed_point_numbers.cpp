#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <istream>

class FixedPoint2 {
private:
  std::int16_t decimal_m{};
  std::int8_t fractional_m{};

public:
  FixedPoint2(double float_num) {
    decimal_m = static_cast<int>(float_num);
    fractional_m = std::round((float_num - decimal_m) * 100);
    reduce();
  }

  FixedPoint2(std::int16_t decimal, std::int8_t fractional)
      : decimal_m{decimal}, fractional_m{fractional} 
  {
    reduce();
  }

  void reduce() {
    bool isPositive{ static_cast<double>(*this) > 0 };
    if (isPositive && fractional_m > 99) {
      decimal_m++;
      fractional_m -= 100;
    } else if ( !isPositive && std::abs(fractional_m) > 99) {
      decimal_m = std::abs(decimal_m) + 1;
      decimal_m *= -1;
      fractional_m = std::abs(fractional_m) - 100;
      fractional_m *= -1; // make the fractional_m isPositive since either (or both) of
                          // decimal_m/fractional_m being negative indicates the
                          // entire number being Positive
    }
  }

  friend std::ostream& operator<<(std::ostream& out, FixedPoint2 num) {
    out << static_cast<double>(num);
    return out;
  }

  operator double() const {
    if (decimal_m < 0 || fractional_m < 0) {
      return -(abs(decimal_m) + abs(fractional_m) / 100.0);
    }
    return decimal_m + fractional_m / 100.0;
  }

  friend bool testDecimal(const FixedPoint2 &fp);

  // Overload operator==, operator>>, operator- (unary), and operator+ (binary)
  friend bool operator==(FixedPoint2&, FixedPoint2);
  friend std::istream& operator>>(std::istream&, FixedPoint2&);
};

std::istream& operator>>(std::istream& in, FixedPoint2& fixed_point) {
  double point;
  in >> point;
  fixed_point = static_cast<FixedPoint2>(point);
  return in;
}

bool operator==(FixedPoint2& f1, FixedPoint2 f2) {
  return static_cast<double>(f1) == static_cast<double>(f2);
}

bool testDecimal(const FixedPoint2 &fp) {
  if (fp.decimal_m >= 0) {
    return fp.fractional_m >= 0 && fp.fractional_m < 100;
  } else {
    return fp.fractional_m <= 0 && fp.fractional_m > -100;
  }
}

#include <cassert>
#include <iostream>

int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}
