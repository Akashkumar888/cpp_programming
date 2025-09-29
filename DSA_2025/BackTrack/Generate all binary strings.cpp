
class Solution {
  public:
  void solve(int n,int count,string &str,vector<string>&ans){
      if(count==n){
          ans.push_back(str);
          return;
      }
      str.push_back('1');// do push char not string 
      solve(n,count+1,str,ans);// explore
      str.pop_back();   // undo        
      
      
      str.push_back('0'); // do push char not string 
      solve(n,count+1,str,ans);// explore
      str.pop_back();   // undo        
      
  }
    vector<string> binstr(int n) {
        // code here
        vector<string>ans;
        string str;
        solve(n,0,str,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

