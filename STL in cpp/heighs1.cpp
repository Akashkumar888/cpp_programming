#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> name_height;

    // Define an array of names and corresponding heights
    std::string names[] = {"akash", "ankit", "surya"};
    int heights[] = {12, 90, 65};

    // Determine the size of the arrays
    int size = sizeof(names) / sizeof(names[0]);

    // Fill the map using a for loop
    for (int i = 0; i < size; ++i) {
        name_height[names[i]] = heights[i];
    }

    // Display the contents of the map
    for (const auto& pair : name_height) {
        std::cout << "Name: " << pair.first << ", Height: " << pair.second << std::endl;
    }

    return 0;
}