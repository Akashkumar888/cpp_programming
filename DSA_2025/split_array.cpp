
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> presum(n, 0);

        // Initialize the prefix sum array
        presum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            presum[i] = nums[i] + presum[i + 1];
        }

        long cnt = 0, sum = 0;
        // Loop through the array and check if the sum of the left part is greater than or equal to the right part
        for (int i = 0; i < n - 1; i++) {
            sum += nums[i];
            if (sum >= presum[i + 1]) cnt++;
        }
        
        return (int) cnt;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution sol;
    cout << "Number of ways to split the array: " << sol.waysToSplitArray(nums) << endl;

    return 0;
}
