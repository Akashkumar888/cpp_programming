
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int maxLength = 0;

    for (int num : arr) {
        // Check if num is the start of a sequence
        if (s.find(num - 1) == s.end()) {
            int currentNum = num;
            int currentLength = 1;

            // Count the length of the sequence
            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {99, 80, 60, 33, 44, 86, 34, 64, 77, 18, 39, 3, 27, 16, 29, 60, 67, 23, 7, 87, 6, 75, 92, 11, 59, 13, 88, 24, 98, 4, 26, 6};
    cout << "Longest Consecutive Subsequence Length: " << longestConsecutive(arr) << endl;

    return 0;
}
