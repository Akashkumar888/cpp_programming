

class Solution {
  public:
  int check(vector<int>&mp){
      int cnt=0;
      for(int i=0;i<26;i++){
         if(mp[i]!=0)cnt++; 
      }
      return cnt;
  }
  int atmost(string &s,int k){
        int n=s.size();
        vector<int>mp(26,0);
        int i=0,j=0;
        int count=0;
        while(j<n){
            mp[s[j]-'a']++;
            while(check(mp)>k){
                mp[s[i]-'a']--;
                i++;
            }
            count+=(j-i+1); // substring count
            j++;
        }
        return count;
  }
    int countSubstr(string& s, int k) {
        // code here.
        return atmost(s,k)-atmost(s,k-1);
    }
};

