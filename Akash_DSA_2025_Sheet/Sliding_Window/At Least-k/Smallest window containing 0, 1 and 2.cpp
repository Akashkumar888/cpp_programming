class Solution {
  public:
  int solve(vector<int>&mp){
      int count=0;
      for(int i=0;i<3;i++){
          if(mp[i]!=0)count++;
      }
      return count;
  }
    int smallestSubstring(string s) {
        // code here
        int n=s.size();
        vector<int>mp(3,0);
        int minLength=INT_MAX;
        int i=0,j=0;
        while(j<n){
            mp[s[j]-'0']++;
            while(solve(mp)>=3){
                minLength=min(minLength,j-i+1);
                if(mp[s[i]-'0']>0)mp[s[i]-'0']--;
                i++;
            }
            j++;
        }
        return minLength==INT_MAX ? -1 : minLength;
    }
};


class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.size();
        vector<int> mp(3, 0);
        int minLength = INT_MAX;
        int i = 0, j = 0;
        int uniqueChar = 0; // number of distinct chars present

        while(j < n){
            if(mp[s[j]-'0'] == 0) uniqueChar++; // new character found
            mp[s[j]-'0']++;
            while(uniqueChar == 3){
                minLength = min(minLength, j - i + 1);
                mp[s[i]-'0']--;
                if(mp[s[i]-'0'] == 0) uniqueChar--; // one char removed completely
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};
