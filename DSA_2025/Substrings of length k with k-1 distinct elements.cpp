
class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        int count=0;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            while(j-i+1>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            if(j-i+1==k && mp.size()==k-1)count++;
            j++;
        }
        return count;
    }
};


class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        int count=0;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            if(j-i+1>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            if(j-i+1==k && mp.size()==k-1)count++;
            j++;
        }
        return count;
    }
};

// 🔍 Time Complexity:
// Each character enters and exits the window once → O(n)
// mp.size() and mp.erase() are O(1) average-case (unordered_map)
// So overall: ✅ O(n)

// 🧠 Space Complexity:
// unordered_map stores at most k characters (size of window) → max 26 keys
// So: ✅ O(1) (since alphabet is limited, space is constant)




class Solution {
  public:
  int frequency(vector<int>&mp){
      int freq=0;
      for(int i=0;i<26;i++){
          if(mp[i]!=0)freq++;
      }
      return freq;
  }
    int substrCount(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        int count=0;
        int i=0,j=0;
        while(j<n){
            mp[s[j]-'a']++;
            while(j-i+1>k){
                mp[s[i]-'a']--;
                i++;
            }
            if(j-i+1==k && frequency(mp)==k-1)count++;
            j++;
        }
        return count;
    }
};

class Solution {
  public:
  int frequency(vector<int>&mp){
      int freq=0;
      for(int i=0;i<26;i++){
          if(mp[i]!=0)freq++;
      }
      return freq;
  }
    int substrCount(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        int count=0;
        int i=0,j=0;
        while(j<n){
            mp[s[j]-'a']++;
            if(j-i+1>k){
                mp[s[i]-'a']--;
                i++;
            }
            if(j-i+1==k && frequency(mp)==k-1)count++;
            j++;
        }
        return count;
    }
};


// 🔍 Time Complexity:
// Sliding window operations: O(n)
// But frequency(mp) runs in O(26) = O(1)
// So overall: ✅ O(n)

// 🧠 Space Complexity:
// The mp vector is fixed size (26)
// ✅ O(1)


// Both are optimal with O(n) time and O(1) space, but the vector version may be marginally faster due to no hashing overhead.

