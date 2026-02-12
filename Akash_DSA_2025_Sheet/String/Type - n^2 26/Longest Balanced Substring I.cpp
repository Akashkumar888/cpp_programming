
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            vector<int> mp(26, 0);
            for (int j = i; j < n; j++) {
                mp[s[j] - 'a']++;
                int distinct=0;
                bool flag = true;
                int freq = -1;
                for (int k = 0; k < 26; k++) {
                    if (mp[k] != 0) {
                        distinct++;
                        if (freq == -1) {
                            freq = mp[k];
                        } 
                        else if(freq!=mp[k]){
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag)maxLen = max(maxLen, freq*distinct);
            }
        }
        return maxLen;
    }
};

// 🔥 Similar Problems (Very Important for You)
// 1️⃣ LeetCode 1234 – Replace the Substring for Balanced String
// https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// 2️⃣ LeetCode 395 – Longest Substring with At Least K Repeating Characters
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// 3️⃣ LeetCode 159 – Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// 4️⃣ GFG – Longest Substring with Equal 0s and 1s
// https://www.geeksforgeeks.org/longest-substring-with-equal-number-of-0s-and-1s/
// 5️⃣ LeetCode 1371 – Find the Longest Substring Containing Vowels in Even Counts
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/


class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            vector<int> mp(26, 0);
            int distinct = 0;
            int maxFreq = 0;
            for(int j = i; j < n; j++) {
                if(mp[s[j] - 'a'] == 0) distinct++;
                mp[s[j] - 'a']++;
                maxFreq = max(maxFreq, mp[s[j] - 'a']);
                int len = j - i + 1;
                if(maxFreq * distinct == len)maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
