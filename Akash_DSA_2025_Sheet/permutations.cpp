void backtrack(int i,int n,string &s,vector<string>&ans){
      if(i>=n){
          ans.push_back(s);
          return ;
      }
      vector<int>st(26,0);
      for(int j=i;j<n;j++){
          if(st[(s[j]-'A')]==0){
          st[(s[j]-'A')]=1; 
          swap(s[i],s[j]);
          backtrack(i+1,n,s,ans);
          swap(s[i],s[j]);
          }
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        int n=s.size();
        vector<string>ans;
        backtrack(0,n,s,ans);
        return ans;
    }