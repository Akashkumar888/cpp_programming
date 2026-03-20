
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStringChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dp;

        // Sort words based on length
        sort(words.begin(), words.end(), [](string &s1, string &s2) {
            return s1.size() < s2.size();
        });

        int maxLength = 1;
        for (string &word : words) {
            int best = 1;
            for (int i = 0; i < word.size(); i++) {
                string prevWord = word.substr(0, i) + word.substr(i + 1);  // Remove one character
                if (dp.count(prevWord)) {
                    best = max(best, dp[prevWord] + 1);
                }
            }
            dp[word] = best;
            maxLength = max(maxLength, best);
        }

        return maxLength;
    }
};
