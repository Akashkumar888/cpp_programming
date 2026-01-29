
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int maxlen=-1;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
           if(mp.size()==k)maxlen=max(maxlen,j-i+1); // exactly k unique char 
            j++;
        }
        return maxlen;
    }
};

// ⏱ Time Complexity:
// Each character is processed at most twice (once by j and once by i) → O(n)
// mp.size() lookup → O(1) average (amortized for hash map)
// max() and other operations are constant time.
// ✅ Time: O(n)

// 💾 Space Complexity:
// In the worst case, you may store all unique characters in the map.
// For lowercase alphabets → max 26 keys.
// ✅ Space: O(1) (bounded by alphabet size)




class Solution {
  public:
  int frequency(vector<int>&mp){
      int freq=0;
      for(int i=0;i<26;i++){
          if(mp[i]!=0)freq++;
      }
      return freq;
  }
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        int i=0,j=0;
        int maxlen=-1;
        while(j<n){
            mp[s[j]-'a']++;
            while(frequency(mp)>k){
                mp[s[i]-'a']--;
                i++;
            }
           if(frequency(mp)==k)maxlen=max(maxlen,j-i+1);// exactly k unique char 
            j++;
        }
        return maxlen;
    }
};

// ⏱ Time Complexity:
// Window still slides as in the 1st → O(n)
// But frequency(mp) is called inside the loop, which iterates over all 26 letters each time → O(26) ≈ O(1)
// ✅ Time: O(n × 26) ⇒ O(n)

// 💾 Space Complexity:
// You're using a fixed size vector of 26 elements.
// ✅ Space: O(26) ⇒ O(1)

