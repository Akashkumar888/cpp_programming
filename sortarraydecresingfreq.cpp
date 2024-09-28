#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr = {4, 5, 6, 5, 4, 4, 3};
    
    // Step 1: Count the frequency of each element
    unordered_map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }
    
    // Step 2: Create a vector of pairs (element, frequency)
    vector<pair<int, int>> freqVec;
    for (auto& p : frequency) {
        freqVec.push_back(p);
    }
    
    // Step 3: Sort the vector of pairs based on frequency using a lambda function
    sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    });
    
    // Step 4: Create the result array based on sorted frequencies
    vector<int> result;
    for (auto& p : freqVec) {
        result.insert(result.end(), p.second, p.first);
    }
    
    // Output the sorted array
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
