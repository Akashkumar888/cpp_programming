#include <iostream>

int main() {
    int a, b;

    // + % +
    a = 10;
    b = 3;
    std::cout << a << " % " << b << " = " << a % b << std::endl;

    // + % -
    a = 10;
    b = -3;
    std::cout << a << " % " << b << " = " << a % b << std::endl;

    // - % +
    a = -10;
    b = 3;
    std::cout << a << " % " << b << " = " << a % b << std::endl;

    // - % -
    a = -10;
    b = -3;
    std::cout << a << " % " << b << " = " << a % b << std::endl;

    return 0;
}
