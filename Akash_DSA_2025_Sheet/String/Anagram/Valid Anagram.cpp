
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        unordered_map<char,int>mp1;
        for(int i=0;i<n;i++) mp1[s[i]]++;
        unordered_map<char,int>mp2;
        for(int i=0;i<n;i++) mp2[t[i]]++;
        for(auto p:mp1){
            char ch1=p.first;
            int freq1=p.second;
            if(mp2.find(ch1)!=mp2.end()){
                int freq2=mp2[ch1];
                if(freq1!=freq2) return false;
            }
            else return false;
        }
        return true;
    }
};



class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++) mp[s[i]]++;
        for(int i=0;i<n;i++){
            char ch=t[i];
            if(mp.find(ch)!=mp.end()){
             mp[ch]--;
             if(mp[ch]==0) mp.erase(ch);
            }
            else return false;
        }
        if(mp.size()>0) return false;
        return true;
    }
};



class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.size()!=s2.size())return false;
        vector<int>mp(26,0);
        for(char &ch:s1)mp[ch-'a']++;
        for(char&ch:s2){
            if(mp[ch-'a']==0)return false;
            mp[ch-'a']--;
        }
        return true;
    }
};

