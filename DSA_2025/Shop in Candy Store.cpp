
class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n=prices.size();
        sort(prices.begin(),prices.end());
        int start=0,end=n-1;
        int sum1=0,sum2=0;
        int lastIdx=n;
        while(start < lastIdx){
            sum1+=prices[start];
            sum2+=prices[end];
            start++,end--;
            lastIdx=lastIdx-k;
        }
        return {sum1,sum2};
    }
};

// ✅ Total Time Complexity:
// O(nlogn)+O(n)=O(nlogn)

// Space Complexity
// The algorithm sorts prices in-place → O(1) extra space (not counting input storage).
// Only a few integer variables are used → constant space.
// ✅ Space Complexity: O(1)
