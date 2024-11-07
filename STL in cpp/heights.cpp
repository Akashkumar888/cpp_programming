#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    std::unordered_map<std::string, int> name_height;
    name_height["akash"] = 12;
    name_height["ankit"] = 90;
    name_height["surya"] = 65;

    // Create a vector of pairs from the unordered_map
    std::vector<std::pair<std::string, int>> vec(name_height.begin(), name_height.end());

    // Define a custom comparator function to sort based on heights
    auto heightComparator = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };

    // Sort the vector based on heights using the custom comparator
    std::sort(vec.begin(), vec.end(), heightComparator);

    // Iterate over the sorted vector
    for (const auto& pair : vec) {
        std::cout << "Name: " << pair.first << ", Height: " << pair.second << std::endl;
    }

    return 0;
}
