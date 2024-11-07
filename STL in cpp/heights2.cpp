#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::map<std::string, int> mp;
    std::vector<std::string> ans;

    // Assuming you have already filled the 'mp' map

    // Sorting the map based on the values
    auto lambda = [](const auto& a, const auto& b) {
        return a.second < b.second;
    };
    std::sort(mp.begin(), mp.end(), lambda);

    // Filling the 'ans' vector with the sorted string values
    for (const auto& pair : mp) {
        ans.push_back(pair.first);
    }

    // Displaying the contents of the 'ans' vector
    for (const auto& str : ans) {
        std::cout << str << std::endl;
    }

    return 0;
}
