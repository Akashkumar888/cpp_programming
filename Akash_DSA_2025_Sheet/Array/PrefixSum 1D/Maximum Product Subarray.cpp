
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int leftprod = 1;
        int maxAns = INT_MIN;

        // Left to right
        for(int i = 0; i < n; i++){
            leftprod *= nums[i];
            maxAns = max(maxAns, leftprod);
            if(leftprod == 0) leftprod = 1;
        }

        int rightprod = 1;

        // Right to left
        for(int i = n - 1; i >= 0; i--){
            rightprod *= nums[i];
            maxAns = max(maxAns, rightprod);
            if(rightprod == 0) rightprod = 1;
        }
        return maxAns;
    }
};


class Solution {
  public:
//   Note: It is guaranteed that the answer fits in a 32-bit integer.
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        
        int leftprod = 1;
        int maxAns = INT_MIN;

        // Left to right
        for(int i = 0; i < n; i++){
            leftprod *= arr[i];
            maxAns = max(maxAns, leftprod);
            if(leftprod == 0) leftprod = 1;
        }

        int rightprod = 1;

        // Right to left
        for(int i = n - 1; i >= 0; i--){
            rightprod *= arr[i];
            maxAns = max(maxAns, rightprod);
            if(rightprod == 0) rightprod = 1;
        }

        return maxAns;
    }
};


// 🔹 Steps
// Initialize:
// maxEnding = arr[0]
// minEnding = arr[0]
// ans = arr[0]
// Traverse from index 1 to n-1
// If arr[i] is negative → swap maxEnding and minEnding
// Update:
// maxEnding = max(arr[i], maxEnding * arr[i])
// minEnding = min(arr[i], minEnding * arr[i])
// Update answer


class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        
        int maxEnding = arr[0];
        int minEnding = arr[0];
        int ans = arr[0];
        
        for (int i = 1; i < n; i++) {
            // If current element is negative, swap
            if (arr[i] < 0)
                swap(maxEnding, minEnding);
            
            maxEnding = max(arr[i], maxEnding * arr[i]);
            minEnding = min(arr[i], minEnding * arr[i]);
            
            ans = max(ans, maxEnding);
        }
        
        return ans;
    }
};
