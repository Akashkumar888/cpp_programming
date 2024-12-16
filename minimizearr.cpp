
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<P> vec;
        
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        
        // Create a min heap from the vector
        priority_queue<P, vector<P>, greater<P>> pq(vec.begin(), vec.end());
        
        // Process k times to multiply the smallest element and push back
        while (k-- && !pq.empty()) {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            nums[idx] = val * multiplier;
            pq.push({nums[idx], idx});
        }
        
        return nums;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {4, 3, 7, 6, 5};
    int k = 3;
    int multiplier = 2;

    vector<int> result = solution.getFinalState(nums, k, multiplier);
    
    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
