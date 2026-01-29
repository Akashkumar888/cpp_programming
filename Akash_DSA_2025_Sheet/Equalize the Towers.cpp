
class Solution {
  public:
    int calculateCost(int n,int h,vector<int>&heights,vector<int>&cost){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=cost[i]*abs(heights[i]-h);
        }
        return sum;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n=heights.size();
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
        int ans = INT_MAX;
        while (low <= high){
            // we can do ternary search (slightly cleaner and optimal) from binary search:
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            int cost1 = calculateCost(n,mid1, heights, cost);
            int cost2 = calculateCost(n,mid2, heights, cost);
            ans = min(ans, min(cost1, cost2));
            if (cost1 < cost2)
                high = mid2 - 1;
            else
                low = mid1 + 1;
        }
        return ans;
    }
};