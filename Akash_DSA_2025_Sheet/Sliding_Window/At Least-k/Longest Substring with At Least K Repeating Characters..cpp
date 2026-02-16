
// 🔥 Approach 1: Divide & Conquer (Most Elegant)
// 🧠 Core Idea
// If a character appears less than k times in the entire substring,
// then that character can NEVER be part of a valid answer.
// So:
// Count frequency in current substring.
// If any character has freq < k → split around it.
// Recursively solve left and right parts.
// Take max.


// (Divide & Conquer) 
class Solution {
public:
    int helper(string &s, int start, int end, int k) {
        if (end - start < k) return 0;
        vector<int> freq(26, 0);
        
        // Count frequency
        for (int i = start; i < end; i++)freq[s[i] - 'a']++;
        
        for (int i = start; i < end; i++) {
            
            if (freq[s[i] - 'a'] < k) {
                
                int j = i + 1;
                
                while (j < end && freq[s[j] - 'a'] < k)j++;
                
                return max(helper(s, start, i, k),helper(s, j, end, k));
            }
        // If no bad character found
        }
        return end - start;
    }
    int longestSubstring(string s, int k) {
        int n=s.size();
        return helper(s, 0, n, k);    
    }
};



// ⏱ Time Complexity
// Worst case: O(26 * n)
// Practically very fast.

// 🔥 Approach 2: Sliding Window with Fixed Unique Count (Advanced)
// This is trickier but important.
// Idea:
// For unique characters from 1 → 26:
// Fix number of unique characters
// Use sliding window
// Maintain:
// uniqueCount
// countAtLeastK
// Update answer when:
// uniqueCount == targetUnique
// AND
// countAtLeastK == targetUnique

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size();
        int ans = 0;
        
        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {
            
            vector<int> freq(26, 0);
            
            int left = 0, right = 0;
            int uniqueCount = 0;
            int countAtLeastK = 0;
            
            while (right < n) {
                
                if (freq[s[right] - 'a'] == 0)
                    uniqueCount++;
                
                freq[s[right] - 'a']++;
                
                if (freq[s[right] - 'a'] == k)
                    countAtLeastK++;
                
                while (uniqueCount > targetUnique) {
                    
                    if (freq[s[left] - 'a'] == k)
                        countAtLeastK--;
                    
                    freq[s[left] - 'a']--;
                    
                    if (freq[s[left] - 'a'] == 0)
                        uniqueCount--;
                    
                    left++;
                }
                
                if (uniqueCount == targetUnique &&
                    countAtLeastK == targetUnique) {
                    
                    ans = max(ans, right - left + 1);
                }
                
                right++;
            }
        }
        
        return ans;
    }
};

