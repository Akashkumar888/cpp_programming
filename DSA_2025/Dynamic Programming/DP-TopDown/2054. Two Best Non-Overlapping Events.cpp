
class Solution {
public:
int n;
int dp[100001][3];
int binarySearch(vector<vector<int>>&nums,int end){
    int idx=n;
    int l=0,r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(end<nums[mid][0]){
            idx=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return idx;
}
int f(vector<vector<int>>&nums,int i,int count){
    if(i>=n || count==2)return 0;
    if(dp[i][count]!=-1)return dp[i][count];
    int nextIdx=binarySearch(nums,nums[i][1]);
    int pick=nums[i][2]+f(nums,nextIdx,count+1);
    int notpick=f(nums,i+1,count);
    return dp[i][count]=max(pick,notpick);
}
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        memset(dp,-1,sizeof(dp));
        sort(events.begin(),events.end());
        return f(events,0,0);
    }
};
