class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        unordered_map<char,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()==3){
                cnt+=(n-j);
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};



class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> mp(3, 0);
        int count=0;
        int i = 0, j = 0;
        int uniqueChar = 0; // number of distinct chars present

        while(j < n){
            if(mp[s[j]-'a'] == 0) uniqueChar++; // new character found
            mp[s[j]-'a']++;
            while(uniqueChar == 3){
                count+=(n-j);
                mp[s[i]-'a']--;
                if(mp[s[i]-'a'] == 0) uniqueChar--; // one char removed completely
                i++;
            }
            j++;
        }
        return count;
    }
};