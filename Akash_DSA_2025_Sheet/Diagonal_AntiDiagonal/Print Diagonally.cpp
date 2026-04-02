class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n=mat.size();
        vector<int>result;
        map<int,vector<int>>mp;// ordered map because index start from 0 to n-1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto &it:mp){
            for(auto &num:it.second)result.push_back(num);
        }
        return result;
    }
};
