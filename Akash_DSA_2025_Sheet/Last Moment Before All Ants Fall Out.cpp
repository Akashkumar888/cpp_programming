
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxLen=0;
        // For left-moving ants: they fall at time = position
        for(int &num:left)maxLen=max(maxLen,num-0);
        // For right-moving ants: they fall at time = n - position
        for(int &num:right)maxLen=max(maxLen,n-num);
        // An ant at position x going left falls off in x seconds.
        // An ant at position x going right falls off in n - x seconds.
        return maxLen;
    }
};

// ⏱️ Time Complexity:
// O(L + R) where L = left.size() and R = right.size().
// You iterate through both arrays once.

// 📦 Space Complexity:
// O(1) extra space (excluding input).
// Just a few variables used (maxLen and loop variables).

