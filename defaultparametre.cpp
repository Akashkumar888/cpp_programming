
#include <iostream>
#include <string>

void Myname(const std::string &fullname = "Prabhu Deva") {
    std::cout << "My name is: " << fullname << std::endl;
}

int main() {
    Myname();              // Default name
    Myname("akash kumar"); // Custom name
    return 0;
}

