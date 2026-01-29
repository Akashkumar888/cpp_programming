
class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        for(char &ch:s)mp[ch-'a']++;
        int cnt=0;
        for(int i=0;i<26;i++){
            int m=mp[i];
            cnt+=(m*(m+1))/2;
        }
        return cnt;
    }
  };

  