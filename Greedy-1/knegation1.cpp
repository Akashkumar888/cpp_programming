
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while (k--) {
            int val = pq.top();
            pq.pop();
            pq.push(-val);
        }

        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {4, 2, 3};
    int k = 1;

    Solution solution;
    int result = solution.largestSumAfterKNegations(nums, k);

    
    cout << "The largest sum after " << k << " negations is: " << result << endl;
    return 0;
}
