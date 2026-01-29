
class Solution {
public:
void solve(int i,int n,int tr,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
    if(tr<0)return;
    // if(i>=n)return ; this case is not necessary  beacause of for loop where j is never exceed n
    if(tr==0){
        ans.push_back(temp);
        return ;
    }
    for(int j=i;j<n;j++){
        if(j>i && nums[j]==nums[j-1])continue;
        if(nums[j]<=tr){
        temp.push_back(nums[j]);
        solve(j+1,n,tr-nums[j],nums,temp,ans);
        temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      int n=candidates.size();
      vector<vector<int>>ans;
      vector<int>temp;
      // lexocographical 
       solve(0,n,target,candidates,temp,ans);  
       return ans;
    }
};