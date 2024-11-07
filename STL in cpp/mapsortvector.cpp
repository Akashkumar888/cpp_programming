#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    // Input string
   string inputString = "examplestring";

    // Map to store character frequencies
    map<char, int> charFrequency;

    // Count the frequency of each character
    for (char ch : inputString) {
        charFrequency[ch]++;
    }

    // Vector to store pairs of characters and their frequencies
    vector<pair<char, int>> charFrequencyVector;

    // Push pairs into the vector
    for (const auto& entry : charFrequency) {
        charFrequencyVector.push_back(make_pair(entry.first, entry.second));
    }

    // Print the resulting vector
    for (const auto& element : charFrequencyVector) {
        cout << "{" << element.first << "," << element.second << "} ";
    }

    return 0;
}
