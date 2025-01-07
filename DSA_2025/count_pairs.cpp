
#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int target) {
    // Complete the function
    int n = arr.size();
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == target) {
            int left = 1, right = 1;

            // Count duplicates for arr[l]
            while (l + 1 < n && arr[l] == arr[l + 1]) {
                left++;
                l++;
            }

            // Count duplicates for arr[r]
            while (l < r - 1 && arr[r - 1] == arr[r]) {
                right++;
                r--;
            }

            // Handle case where arr[l] == arr[r]
            if (arr[l] == arr[r]) {
                cnt += (left * (left - 1)) / 2;  // Choose 2 out of `left` occurrences
            } else {
                cnt += left * right;
            }

            l++;
            r--;
        } else if (sum < target) {
            l++;
        } else {
            r--;
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3}; // Example input
    int target = 4; // Example target

    int result = countPairs(arr, target);
    cout << "Count of pairs with sum " << target << ": " << result << endl;

    return 0;
}
