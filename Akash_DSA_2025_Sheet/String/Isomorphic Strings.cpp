
class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n=s1.size();
        unordered_map<char,char>mp1,mp2;
        for(int i=0;i<n;i++){
            if(mp1.find(s1[i])!=mp1.end() && mp1[s1[i]]!=s2[i])return false;
            else mp1[s1[i]]=s2[i];
        }
        for(int i=0;i<n;i++){
            if(mp2.find(s2[i])!=mp2.end() && mp2[s2[i]]!=s1[i])return false;
            else mp2[s2[i]]=s1[i];
        }
        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
         unordered_map<char,char>mp2;
         int n=s.size();
         for(int i=0;i<n;i++){
            char ch1=s[i];
            char ch2=t[i];
            if( (mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2 )
            || (mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1 ) ){
                return false;
            } 
            mp1[ch1]=ch2;
            mp2[ch2]=ch1;
         }
         return true;
    }
};


class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.size() != s2.size()) return false;

        vector<int> map1(256, 0);
        vector<int> map2(256, 0);

        for(int i = 0; i < s1.size(); i++) {
            if(map1[s1[i]] == 0 && map2[s2[i]] == 0) {
                map1[s1[i]] = s2[i];
                map2[s2[i]] = s1[i];
            }
            else if(map1[s1[i]] != s2[i]) {
                return false;
            }
        }
        return true;
    }
};

// when only lowercase 
// ✅ 🔹 Method 1: Two Vectors (Lowercase Optimized – Size 26)

class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.size() != s2.size()) return false;

        vector<int> map1(26, 0);
        vector<int> map2(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';

            if(map1[c1] == 0 && map2[c2] == 0) {
                map1[c1] = c2 + 1;   // +1 to avoid confusion with default 0
                map2[c2] = c1 + 1;
            }
            else if(map1[c1] != c2 + 1) {
                return false;
            }
        }
        return true;
    }
};


// ✅ 🔹 Method 2: Last Seen Index (Best – Lowercase Version)
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.size() != s2.size()) return false;

        vector<int> last1(26, 0);
        vector<int> last2(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';

            if(last1[c1] != last2[c2])
                return false;

            last1[c1] = i + 1;
            last2[c2] = i + 1;
        }
        return true;
    }
};
