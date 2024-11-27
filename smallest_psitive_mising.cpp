
#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest missing positive integer
int missingNumber(vector<int>& arr) {
    unordered_map<int, int> mp;
    int n = arr.size();

    // Store frequency of each number
    for (int num : arr) {
        mp[num]++;
    }

    // Find the smallest missing number
    for (int i = 1; i <= n; i++) {
        if (mp.find(i) == mp.end()) {
            return i;
        }
    }

    // If all numbers are present, return n + 1
    return n + 1;
}

int main() {
    vector<int> arr = {3, 4, -1, 1}; // Sample input
    cout << "Missing Number: " << missingNumber(arr) << endl;
    return 0;
}
