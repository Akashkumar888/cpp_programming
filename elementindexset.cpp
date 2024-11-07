#include <iostream>
#include <set>
#include <iterator> // For std::distance

int main() {
    std::set<int> s = {10, 20, 30, 40, 50};

    int element = 30;
    auto it = s.find(element);  // Find the iterator to the element
    if (it != s.end()) {
        // Calculate the index as the distance from the beginning iterator
        int index = std::distance(s.begin(), it);
        std::cout << "The index of element " << element << " is: " << index << std::endl;
    } else {
        std::cout << "Element not found in the set." << std::endl;
    }

    return 0;
}
