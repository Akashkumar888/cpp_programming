
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int, int> mp; 
        int CumSum = 0;             
        int maxLen = 0;     

        for (int i = 0; i < n; i++) {
            CumSum += arr[i]; 

            if (CumSum == 0) {
                maxLen = i + 1;
            }
            if (mp.find(CumSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[CumSum]);
            } 
            else {
                mp[CumSum] = i;
            }
        }
        return maxLen;
    }
};