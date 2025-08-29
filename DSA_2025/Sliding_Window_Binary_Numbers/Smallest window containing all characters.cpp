// s, p consists of lowercase english letters

class Solution {
  public:
  bool solve(vector<int>&mp2,vector<int>&mp1){
      for(int i=0;i<26;i++){
          if(mp2[i]<mp1[i])return false;
      }
      return true;
  }
    string smallestWindow(string &s, string &p) {
        // code here
        int n=s.size();
        int m=p.size();
        if(n<m)return "";
        vector<int>mp1(26,0),mp2(26,0);
        for(char &ch:p)mp1[ch-'a']++;
        int i=0,j=0;
        int first=-1,len=0;
        int minLen=INT_MAX;
        while(j<n){
            mp2[s[j]-'a']++;
            while(solve(mp2,mp1)){
                if(j-i+1>=m && j-i+1<minLen){
                first=i;
                len=j-i+1;
                minLen=j-i+1;
                }
                mp2[s[i]-'a']--;
                i++;
            }
            j++;
        }
        if(first==-1)return "";
        return s.substr(first,len);
    }
};

// ✅ Final Answer:
// Time Complexity: O(n)
// Space Complexity: O(1)

// s and t consist of uppercase and lowercase English letters.
class Solution {
public:
bool solve(vector<int>&mp2,vector<int>&mp1){
      for(int i=0;i<256;i++){
          if(mp2[i]<mp1[i])return false;
      }
      return true;
}
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m)return "";
        vector<int>mp1(256,0),mp2(256,0);
        for(char &ch:t)mp1[(unsigned char)ch]++;
        int i=0,j=0;
        int minLen=INT_MAX;
        int first=-1,len=0;
        while(j<n){
            mp2[(unsigned char)s[j]]++;
            while(solve(mp2,mp1)){
                if(j-i+1>=m && j-i+1<minLen){
                first=i;
                len=j-i+1;
                minLen=j-i+1;
                }
                mp2[(unsigned char)s[i]]--;
                i++;
            }
            j++;
        }
        if(first==-1)return "";
        return s.substr(first,len);
    }
};

// ✅ Final Answer:
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (n < t.size())
            return "";
        unordered_map<char, int> mp;
        for (char& ch : t) {
            mp[ch]++;
        }
        int requiredcount = t.size();
        int i = 0, j = 0;
        int minwindowsize = INT_MAX;
        int start_i = 0;
        while (j < n) {
            char ch = s[j];
            if (mp[ch] > 0)
                requiredcount--;

            mp[ch]--;
            while (requiredcount == 0) {
                int curwindowsize = j - i + 1;
                if (minwindowsize > curwindowsize) {
                    minwindowsize = curwindowsize;
                    start_i = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    requiredcount++;
                }
                i++;
            }
            j++;
        }
        return minwindowsize == INT_MAX ? "" : s.substr(start_i, minwindowsize);
    }
};

