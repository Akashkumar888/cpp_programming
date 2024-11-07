#include <iostream>
#include <string>

int main() {
    std::cout << (false || "Akash") << std::endl; // Output: 1
    std::cout << (false && "a") << std::endl;     // Output: 0 
    std::cout << (true && "Kumar") << std::endl;  // Output: 1
    return 0;
}
