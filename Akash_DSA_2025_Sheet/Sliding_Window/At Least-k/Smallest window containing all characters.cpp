// substring find krne vale problems me always take two varibale start index and second length of substring 
//expand window -> satisfy condition -> shrink window -> record answer

class Solution {
public:
    string minWindow(string &s, string &p) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(char &ch:p)mp[ch]++;
        int required=p.size();
        int i=0,j=0;
        int start=0;
        int minLen=INT_MAX;
        while(j<n){
            if(mp[s[j]]>0)required--;
            mp[s[j]]--;
            while(required==0){
                if(j-i+1 < minLen){
                    minLen=j-i+1;
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)required++;
                i++;
            }
            j++;
        }
        if(minLen == INT_MAX)return "";
        return s.substr(start,minLen);
    }
};


class Solution {
public:
    string minWindow(string &s, string &p) {
        int n=s.size();
        vector<int>mp(26,0);
        for(char &ch:p)mp[ch-'a']++;
        int required=p.size();
        int i=0,j=0;
        int start=0;
        int minLen=INT_MAX;
        while(j<n){
            if(mp[s[j]-'a']>0)required--;
            mp[s[j]-'a']--;
            while(required==0){
                if(j-i+1 < minLen){//If there are multiple such substring of the same length found, return the one with the least starting index.
                    minLen=j-i+1;
                    start=i;
                }
                mp[s[i]-'a']++;
                if(mp[s[i]-'a']>0)required++;
                i++;
            }
            j++;
        }
        if(minLen == INT_MAX)return "";
        return s.substr(start,minLen);
    }
};


class Solution {
public:
    bool solve(vector<int>&mp2,vector<int>&mp1){
         for(int i=0;i<26;i++){
            if(mp2[i]<mp1[i])return false;
          }
        return true;
    }
    string minWindow(string &s, string &p) {
        int n=s.size();
        int m=p.size();
        if(n<m)return "";
        vector<int>mp1(26,0),mp2(26,0);
        for(char &ch:p)mp1[ch-'a']++;
        int i=0,j=0;
        int start=-1;
        int minLen=INT_MAX;
        while(j<n){
            mp2[s[j]-'a']++;
            while(solve(mp2,mp1)){
                if(j-i+1<minLen){//If there are multiple such substring of the same length found, return the one with the least starting index.
                start=i;
                minLen=j-i+1;
                }
                mp2[s[i]-'a']--;
                i++;
            }
            j++;
        }
        if(start==-1)return "";
        return s.substr(start,minLen);
    }
};

// 5️⃣ Key Trick of the Optimal Solution ⭐
// This line is very important:
// if(mp[s[j]] > 0) required--;
// Meaning:
// Only reduce required if the character was actually needed.
// Then
// mp[s[j]]--;
// Even if character is extra, map allows negative values.
// Example
// p = "ABC"
// window = "AABBC"
// map may become
// A -> -1
// B -> 0
// C -> 0
// But window still valid.

