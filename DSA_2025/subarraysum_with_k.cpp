
#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays with sum equal to k
int countSubarrays(vector<int> &arr, int k) {
    unordered_map<int, int> mp; // To store prefix sum frequencies
    int cnt = 0, sum = 0;
    mp[0] = 1; // To handle cases where a subarray starts from index 0

    for (int &num : arr) {
        sum += num; // Update the running sum
        int remain = sum - k;

        // Check if there are subarrays that sum up to 'k'
        if (mp.find(remain) != mp.end())
            cnt += mp[remain];

        // Update the hash map with the current prefix sum
        mp[sum]++;
    }
    return cnt;
}

// Main function for testing
int main() {
    vector<int> arr = {1, 2, 3, -1, 4}; // Example array
    int k = 5; // Target sum
    cout << "Count of subarrays with sum " << k << " is: " 
         << countSubarrays(arr, k) << endl;
    return 0;
}
