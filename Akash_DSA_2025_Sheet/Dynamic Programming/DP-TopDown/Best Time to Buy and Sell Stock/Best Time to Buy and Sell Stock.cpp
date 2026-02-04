
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
          maxProfit=max(maxProfit,prices[i]-mini);
          mini=min(mini,prices[i]);
        }
        return maxProfit;
    }
};

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int maxProfit=0;
        int minBuy=prices[0];
        for(int i=1;i<n;i++){
            minBuy=min(minBuy,prices[i]);
            int profit=prices[i]-minBuy;
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
    }
};


class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int ans=0;
        int minbuy=INT_MAX;
        for(int i=0;i<n;i++){
            minbuy=min(minbuy,prices[i]);
            
           int maxsell=max(minbuy,prices[i]);
            ans=max(ans,maxsell-minbuy);
        }
        return ans;
    }
};