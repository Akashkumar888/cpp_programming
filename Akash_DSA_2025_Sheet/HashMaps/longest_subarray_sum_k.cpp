
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> mp; // To store the first occurrence of each cumulative sum
    int sum = 0; // Cumulative sum
    int len = 0; // Maximum length of the subarray with sum k
    
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Update cumulative sum
        
        // If the cumulative sum equals k, update the length
        if (sum == k) len = max(len, i + 1);
        
        // Check if sum - k exists in the map
        if (mp.find(sum - k) != mp.end()) {
            len = max(len, i - mp[sum - k]);
        }
        
        // Store the first occurrence of the cumulative sum
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return len;
}

int main() {
    // Test case
    vector<int> arr = {1, 2, 3, 7, 5};
    int k = 12;

    int result = longestSubarray(arr, k);
    cout << "Longest Subarray Length: " << result << endl;

    return 0;
}
