
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int collectMana(vector<int>& arr, int k) {
        int ans = 0;
        int sum = 0;
        
        for (int i = -1; i < (int)arr.size(); i++) {
            int now = sum;
            for (int j = i + 1; j < min((int)arr.size(), i + 32); j++) {
                int copy = arr[j] >> (j - i);
                now += copy;
            }
            ans = max(ans, now);
            if (i + 1 != (int)arr.size()) {
                sum += arr[i + 1] - k;
            }
        }
        
        return ans;
    }
};

int main() {
    // Input Example
    vector<int> arr = {3, 6, 9, 12}; // Example array
    int k = 2;                       // Mana reduction constant
    
    Solution solution;
    int result = solution.collectMana(arr, k);
    
    // Output the result
    cout << "Maximum Mana Collected: " << result << endl;
    
    return 0;
}
