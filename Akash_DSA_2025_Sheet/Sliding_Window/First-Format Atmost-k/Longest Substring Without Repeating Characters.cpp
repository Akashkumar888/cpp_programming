
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int maxLen=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        int n=s.size();
        int i=0,j=0;
        int maxLen=0;
        vector<int>mp(128,0);//s consists of English letters, digits, symbols and spaces.
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};


// 🔥 Why mp[s[j]] Works Here?
// Because:
// vector<int> mp(128, 0);
// You created a frequency array for ASCII characters.

// In C++:
// char c = 'A';
// cout << (int)c;   // prints ASCII value
// Characters are stored as integers internally.
// Example ASCII values:

// 'a' = 97
// 'A' = 65
// '0' = 48
// ' ' = 32

// So when you write:
// mp[s[j]]++;
// It is actually:
// mp[ASCII value of s[j]]++;
// If s[j] = 'A'
// It becomes:
// mp[65]++
// Perfectly valid because:
// vector size = 128
// Valid indices = 0 to 127

// 🔥 Why We Use mp[s[j] - 'a'] When Only Lowercase?
// If problem says:
// String consists only of lowercase English letters.
// Then characters are only:
// 'a' to 'z'
// ASCII range:
// 97 to 122
// Instead of wasting 128 size, we compress range to 26.
// We map:

// 'a' → 0
// 'b' → 1
// ...
// 'z' → 25

// How?
// s[j] - 'a'
// Because:
// 'a' - 'a' = 0
// 'b' - 'a' = 1
// ...
// 'z' - 'a' = 25

// So:
// vector<int> mp(26);
// mp[s[j] - 'a']++;
// Now index is between 0 and 25.

// 🔥 Why Not Always Use 26?
// Because if string contains:
// 'A'
// Then:
// 'A' - 'a' = 65 - 97 = -32 ❌
// Negative index → crash.
// Or if string contains digit:
// '0' - 'a' = 48 - 97 = -49 ❌

// Out of bounds.
// So 26 works only when strictly lowercase guaranteed.
// 🔥 Why s[j] - 'A' for Uppercase?
// ASCII values:
// 'A' = 65
// 'B' = 66
// ...
// 'Z' = 90

// If we subtract 'A':
// 'A' - 'A' = 0
// 'B' - 'A' = 1
// ...
// 'Z' - 'A' = 25

// So we map:
// 'A' → 0
// ...
// 'Z' → 25

// Then:
// vector<int> mp(26);
// mp[s[j] - 'A']++;
// Works perfectly.

// 🔥 Full Correct Summary Table
// Input                          Type	                                Vector Size	                            Indexing
// Only                          lowercase letters	                    26	                                    s[j] - 'a'
// Only                          uppercase letters	                    26	                                    s[j] - 'A'
// Both lower + upper	                                                  128	                                    mp[s[j]]
// Digits                        only	                                  10	                                    s[j] - '0'
// ASCII (letters, digits, symbols)	                                    128	                                    mp[s[j]]
// Extended ASCII	                                                      256                                     mp[(unsigned char)s[j]]
// Unicode	unordered_map	


// 🧠 Why Your Sliding Window Uses mp[s[j]]
// Because problem says:
// English letters, digits, symbols and spaces.
// So safe solution:
// vector<int> mp(128);
// mp[s[j]]++;
// 🎯 Golden Rule to Remember
// If problem explicitly says:
// Only lowercase letters
// Use:
// size 26 + - 'a'
// Otherwise:
// Use 128 or unordered_map
// 🔥 Extra Deep Insight (Interview Level)
// Actually:
// mp[s[j]]
// works because:
// char in C++ is internally treated as small integer (ASCII code).
// So:
// mp[s[j]]
// is same as:
// mp[(int)s[j]]
// 🚀 Final Understanding
// You subtract 'a' only when you want to:
// Compress character space
// Optimize memory
// Guarantee safe indexing
// Otherwise direct ASCII indexing is safest.

// 🚀 Extra Interview-Level Insight
// Even safer ASCII version:
// vector<int> mp(256,0);
// mp[(unsigned char)s[i]]++;

// Because sometimes char is signed and may cause negative indexing.