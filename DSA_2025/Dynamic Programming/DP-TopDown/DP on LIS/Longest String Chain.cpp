

class Solution {
public:
bool checkPossible(string &s1,string &s2){
    if(s1.size()!=s2.size()+1)return false;
    int i=0,j=0;
    while(i<s1.size()){
        if(j<s2.size() && s1[i]==s2[j]){
            i++,j++;
        }
        else i++;
    }
    if(i==s1.size() && j==s2.size())return true;
    return false;
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        auto cmp=[&](string &a, string &b) {
            return a.size() < b.size();
        };
        // ✅ Step 1: sort by length
        sort(words.begin(), words.end(),cmp);
        
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkPossible(words[i],words[j])) {
                    if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                 }
            }
        }
        if(maxi<dp[i]){
            maxi =dp[i];
         }         
        }
        return maxi;
    }
};


class Solution {
public:
bool checkPossible(string &s1,string &s2){
    if(s1.size()!=s2.size()+1)return false;
    int i=0,j=0;
    while(i<s1.size()){
        if(j<s2.size() && s1[i]==s2[j]){
            i++,j++;
        }
        else i++;
    }
    if(i==s1.size() && j==s2.size())return true;
    return false;
}
    // ✅ MUST be static
    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        // ✅ Step 1: sort by length
        sort(words.begin(), words.end(),cmp);

        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkPossible(words[i],words[j])) {
                    if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                 }
            }
        }
        if(maxi<dp[i]){
            maxi =dp[i];
         }         
        }
        return maxi;
    }
};

class Solution {
public:
bool predecessor(string &w1,string &w2){
      if(w1.size()>=w2.size() || w2.size()-w1.size()!=1)return false;
      int i=0,j=0;
      while(j<w2.size()){
          if(i<w1.size() && w1[i]==w2[j])i++;
          j++;
      }
      return i==w1.size();
  }
  int lis(int prev_idx,int i,int n,vector<string>&words,vector<vector<int>>&dp){
      if(i>=n)return 0;
      if(prev_idx!=-1 && dp[prev_idx][i]!=-1)return dp[prev_idx][i];
      int pick=0,notpick=0;
      if(prev_idx==-1 || predecessor(words[prev_idx],words[i])){
          pick=1+lis(i,i+1,n,words,dp);
      }
      notpick=lis(prev_idx,i+1,n,words,dp);
      if(prev_idx!=-1) dp[prev_idx][i]=max(pick,notpick);
      return max(pick,notpick);
  }
    int longestStrChain(vector<string>& words) {
         int n=words.size();
        auto lambda=[&](string &s1,string &s2){
            return s1.size()<s2.size();
        };
        sort(words.begin(),words.end(),lambda);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lis(-1,0,n,words,dp);
    }
};