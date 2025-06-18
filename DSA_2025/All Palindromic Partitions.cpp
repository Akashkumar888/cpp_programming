
class Solution {
  public:
  bool isPalindrome(int i,int j,string &s){
      while(i<=j){
          if(s[i]!=s[j])return false;
          i++,j--;
      }
      return true;
  }
  void solve(int idx,int n,string &s,vector<string>&ans,vector<vector<string>>&result){
      if(idx>=n){
          result.push_back(ans);
          return;
      }
      // backtrack by using for loop 
      for(int j=idx;j<n;j++){
          if(isPalindrome(idx,j,s)){
          ans.push_back(s.substr(idx,j-idx+1));
          solve(j+1,n,s,ans,result);
          ans.pop_back();
          }
      }
  }
    vector<vector<string>> palinParts(string &s) {
        // code here
        int n=s.size();
        vector<vector<string>>result;
        vector<string>ans;
        solve(0,n,s,ans,result);
        return result;
    }
};

