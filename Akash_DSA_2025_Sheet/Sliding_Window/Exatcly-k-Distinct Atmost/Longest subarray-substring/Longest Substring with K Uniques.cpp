class Solution {
  public:
  //length of the longest substring that contains exactly k distinct characters
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int maxLen=-1;
        int uniqueChar=0;
        while(j<n){
            mp[s[j]]++;// phir bada do char frequency
            while(mp.size()>k){
                mp[s[i]]--;;// pahle frequency ghta do phir
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k)maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};



class Solution {
  public:
  //length of the longest substring that contains exactly k distinct characters
  int isPossible(vector<int>&mp){
      int count=0;
      for(int i=0;i<26;i++){
          if(mp[i]!=0)count++;
      }
      return count;
  }
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        int i=0,j=0;
        int maxLen=-1;
        while(j<n){
            mp[s[j]-'a']++;
            while(isPossible(mp)>k){
                if(mp[s[i]-'a']>0)mp[s[i]-'a']--;
                i++;
            }
            if(isPossible(mp)==k)maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};



class Solution {
  public:
  //length of the longest substring that contains exactly k distinct characters
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        int i=0,j=0;
        int maxLen=-1;
        int uniqueChar=0;
        while(j<n){
            if(mp[s[j]-'a']==0)uniqueChar++;// pahle unique char check karo
            mp[s[j]-'a']++;// phir bada do char frequency
            while(uniqueChar>k){
                mp[s[i]-'a']--;;// pahle frequency ghta do phir
                if(mp[s[i]-'a']==0)uniqueChar--; // check karo unique char
                i++;
            }
            if(uniqueChar==k)maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};