
class Solution {
public:
void solve(int i,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int tr){
 if(tr<0)return ;
 //if(i>=n) return;
 if(tr==0){
    ans.push_back(temp);
    return ;
 }

    for(int j=i;j<n;j++){
        if(nums[j]<=tr){//elements is valid or not like knapsack or target sum 
            temp.push_back(nums[j]);
            solve(j,n,nums,temp,ans,tr-nums[j]);
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      int n=candidates.size();
      vector<vector<int>>ans;
      vector<int>temp;
      solve(0,n,candidates,temp,ans,target);
      return ans;  
    }
};
