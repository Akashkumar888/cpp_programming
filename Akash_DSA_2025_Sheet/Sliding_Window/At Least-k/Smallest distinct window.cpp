
class Solution {
  public:
    int findSubString(string& s) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        for(char &ch:s)mp[ch]++;
        int required=mp.size();
        mp.clear();
        int i=0,j=0;
        int minLength=INT_MAX;
        int uniqueChar=0;
        while(j<n){
            if(mp[s[j]]==0)uniqueChar++;
            mp[s[j]]++;
            while(uniqueChar==required){
                minLength=min(minLength,j-i+1);
                mp[s[i]]--;
                if(mp[s[i]]==0)uniqueChar--;
                i++;
            }
            j++;
        }
        if(minLength == INT_MAX)return -1;
        return minLength;
    }
};


class Solution {
  public:
    int findSubString(string& s) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        for(char &ch:s)mp[ch-'a']++;
        int required=0;
        for(int i=0;i<26;i++){
            if(mp[i]!=0)required++;
        }
        fill(mp.begin(),mp.end(),0);
        int i=0,j=0;
        int minLength=INT_MAX;
        int uniqueChar=0;
        while(j<n){
            if(mp[s[j]-'a']==0)uniqueChar++;
            mp[s[j]-'a']++;
            while(uniqueChar==required){
                minLength=min(minLength,j-i+1);
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0)uniqueChar--;
                i++;
            }
            j++;
        }
        if(minLength == INT_MAX)return -1;
        return minLength;
    }
};