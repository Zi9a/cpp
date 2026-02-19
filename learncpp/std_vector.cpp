#include <iostream>
#include <vector>

int main() {
    std::vector<int> array(3);
    std::cout << "Enter 3 integers: ";
    for(int i{0}; i<3; ++i) {
        std::cin >> array[i];
    }
    std::cout << '\n';

    std::cout << "sum of the numbers: ";
    int sum{};
    for(int i{0}; i<3; ++i) {
        sum += array[i];
    }
    std::cout << sum << '\n';

    std::cout << "product of the numbers: ";
    int prod{ 1 };
    for(int i{0}; i<3; ++i) {
        prod *= array[i];
    }
    std::cout << prod << '\n';

    return 0;
}
