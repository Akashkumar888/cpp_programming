
#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr) {
    int n = arr.size();
    int len = 0, sum = 0;
    unordered_map<int, int> mp; // Stores first occurrence of each sum

    for (int i = 0; i < n; i++) {
        // Treat 0 as -1 for balancing
        if (arr[i] == 0) sum -= 1;
        else sum += 1;

        // If sum becomes 0, update len as the entire subarray has equal 0s and 1s
        if (sum == 0) len = i + 1;

        // Check if the sum has been seen before
        if (mp.find(sum) != mp.end()) {
            // Calculate subarray length
            len = max(len, i - mp[sum]);
        } else {
            // Store the first occurrence of the sum
            mp[sum] = i;
        }
    }
    return len;
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 1, 1, 0};
    cout << "Longest subarray length: " << maxLen(arr) << endl;
    return 0;
}

