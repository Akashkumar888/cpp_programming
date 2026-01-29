
class Solution {
public:
void solve(int i,int n,int k,vector<int>&temp,vector<vector<int>>&result){
    if(temp.size()==k){
        result.push_back(temp);
        return;
    }
    for(int j=i;j<=n;j++){
        temp.push_back(j);
        solve(j+1,n,k,temp,result);
        temp.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>>result;
         vector<int>temp;
         solve(1,n,k,temp,result);
         return result;
    }
};