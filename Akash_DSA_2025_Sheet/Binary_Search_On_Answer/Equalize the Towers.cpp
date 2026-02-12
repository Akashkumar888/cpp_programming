
// binary search on answer 
class Solution {
public:
//Modifying the height of tower 'i' by 1 unit (add or remove) costs cost[i].
    // Function to calculate total cost if we make all towers height = target
    long long findCost(vector<int>& heights, vector<int>& cost, int mid) {
        long long totalCost = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            totalCost += 1LL * abs(heights[i] - mid) * cost[i];
        }
        return totalCost;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        int l = *min_element(heights.begin(), heights.end());
        int r = *max_element(heights.begin(), heights.end());
        long long ans = LLONG_MAX;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            long long cost1 = findCost(heights, cost, mid);
            long long cost2 = findCost(heights, cost, mid + 1);
            ans = min(cost1, cost2);
            if(cost1 < cost2) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};




class Solution {
  public:
    int calculateCost(int h,vector<int>&heights,vector<int>&cost){
        int sum=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            sum+=cost[i]*abs(heights[i]-h);
        }
        return sum;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n=heights.size();
        int l=*min_element(heights.begin(),heights.end());
        int r=*max_element(heights.begin(),heights.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            // we cant do partition based on height
            // we have to do partition based on total cost of that height
            int h1=mid;
            int h2=mid+1;
            int c1=calculateCost(h1,heights,cost);
            int c2=calculateCost(h2,heights,cost);
            if(c1>=c2){
                // so on increasing height cost decreases so we try higher h
                ans=c2;
                l=mid+1;
            }
            else{
                ans=c1;
                r=mid-1;
            }
        }
        return ans;
    }
};



// ternary search on answer 
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
            if(cost1 < cost2)high = mid2 - 1;
            else low = mid1 + 1;
        }
        return ans;
    }
};

