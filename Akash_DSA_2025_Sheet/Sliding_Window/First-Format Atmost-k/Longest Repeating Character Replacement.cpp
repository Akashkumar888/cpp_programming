
// 🔥 Key Insight (MOST IMPORTANT)
// In any window:
// window size - frequency of most common char ≤ k
// 👉 Why?
// Because:
// remaining chars = need to replace
// Maintain:
// maxFreq → highest frequency in current window
// window size = j - i + 1
// Condition:
// (j - i + 1) - maxFreq > k
// 👉 Then shrink window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0, j = 0;
        int maxLen = 0;
        int maxFreq = 0;
        while (j < n) {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            while((j - i + 1) - maxFreq > k) {
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};


// 🔥 Key Insight (MOST IMPORTANT)
// In any window:
// window size - frequency of most common char ≤ k
// 👉 Why?
// Because:
// remaining chars = need to replace
// Maintain:
// maxFreq → highest frequency in current window
// window size = j - i + 1
// Condition:
// (j - i + 1) - maxFreq > k
// 👉 Then shrink window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>mp(26,0);
        int i = 0, j = 0;
        int maxLen = 0;
        int maxFreq = 0;
        while (j < n) {
            mp[s[j]-'A']++;
            maxFreq = max(maxFreq, mp[s[j]-'A']);
            while((j - i + 1) - maxFreq > k) {
                if(mp[s[i]-'A']>0)mp[s[i]-'A']--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};