
class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();
        // Maximum subarray sum from left side
        vector<int> leftMax(n);
        // Minimum subarray sum from left side
        vector<int> leftMin(n);
        // Maximum subarray sum from right side
        vector<int> rightMax(n);
        // Minimum subarray sum from right side
        vector<int> rightMin(n);
        //---------------- LEFT MAX ----------------//
        int sum = arr[0];
        leftMax[0] = arr[0];
        for(int i=1;i<n;i++){
            // Kadane
            sum = max(arr[i], sum + arr[i]);
            // Best till now
            leftMax[i] = max(leftMax[i-1], sum);
        }
        //---------------- LEFT MIN ----------------//
        sum = arr[0];
        leftMin[0] = arr[0];
        for(int i=1;i<n;i++){
            // Reverse Kadane for minimum
            sum = min(arr[i], sum + arr[i]);
            leftMin[i] = min(leftMin[i-1], sum);
        }
        //---------------- RIGHT MAX ----------------//
        sum = arr[n-1];
        rightMax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            sum = max(arr[i], sum + arr[i]);
            rightMax[i] = max(rightMax[i+1], sum);
        }
        //---------------- RIGHT MIN ----------------//
        sum = arr[n-1];
        rightMin[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            sum = min(arr[i], sum + arr[i]);
            rightMin[i] = min(rightMin[i+1], sum);
        }
        //---------------- Answer ----------------//
        int ans = INT_MIN;
        for(int i=0;i<n-1;i++){
            // Left maximum - Right minimum
            ans = max(ans, abs(leftMax[i] - rightMin[i+1]));
            // Left minimum - Right maximum
            ans = max(ans, abs(leftMin[i] - rightMax[i+1]));
        }
        return ans;
    }
};