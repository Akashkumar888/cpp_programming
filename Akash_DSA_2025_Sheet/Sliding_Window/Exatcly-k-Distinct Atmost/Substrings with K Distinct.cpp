
class Solution {
  public:
//   You have to count all possible substrings that have exactly k distinct characters.
  int atmost(string &s,int k){
        int count=0;
        int i=0,j=0;
        int n=s.size();
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
             count+=(j-i+1); // subarray count it count no of distinct subarray upto j th index and also size of subarray
            j++;
        }
        return count;
}
    int countSubstr(string& s, int k) {
        // code here
        int exactly= atmost(s,k) - atmost(s,k-1);
        return exactly;
    }
};




class Solution {
  public:
//   You have to count all possible substrings that have exactly k distinct characters.
  int solve(vector<int>&mp){
      int count=0;
      for(int i=0;i<26;i++){
          if(mp[i]!=0)count++;
      }
      return count;
  }
  int atmost(string &s,int k){
        int count=0;
        int i=0,j=0;
        int n=s.size();
        vector<int>mp(26,0);
        while(j<n){
            mp[s[j]-'a']++;
            while(solve(mp)>k){
                if(mp[s[i]-'a']>0)mp[s[i]-'a']--;
                i++;
            }
             count+=(j-i+1); // subarray count it count no of distinct subarray upto j th index and also size of subarray
            j++;
        }
        return count;
}
    int countSubstr(string& s, int k) {
        // code here
        int exactly= atmost(s,k) - atmost(s,k-1);
        return exactly;
    }
};


// ✅ Key Optimization (Interview Gold ⭐)
// 👉 Never recalculate distinct count again and again
// Instead:
// Maintain a running variable → distinctCount
// Update it only when needed
// ✅ Optimized Version (FAST & ACCEPTED)
// ✔️ Only minimal changes to YOUR code

class Solution {
  public:
    int atmost(string &s, int k){
        int n = s.size();
        int i = 0, j = 0;
        vector<int> mp(26, 0);
        int count = 0;
        int distinct = 0;   // 🔥 key optimization
        while(j < n){
            if(mp[s[j] - 'a'] == 0)distinct++;
            mp[s[j] - 'a']++;
            while(distinct > k){
                mp[s[i] - 'a']--;
                if(mp[s[i] - 'a'] == 0)distinct--;
                i++;
            }
            count += (j - i + 1);// subarray count it count no of distinct subarray upto j th index and also size of subarray
            j++;
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        int exactly= atmost(s,k) - atmost(s,k-1);
        return exactly;
    }
};
