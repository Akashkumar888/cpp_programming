
class Solution {
public:
void solve(int i,int tr,int k,vector<int>&temp,vector<vector<int>>&ans){
    if(temp.size()==k && tr==0){
        ans.push_back(temp);
        return;
    }
    for(int j=i;j<=9;j++){
        if(j<=tr){
            temp.push_back(j);
            solve(j+1,tr-j,k,temp,ans);
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>>ans;
       vector<int>temp;
       solve(1,n,k,temp,ans);
       return ans; 
    }
};
