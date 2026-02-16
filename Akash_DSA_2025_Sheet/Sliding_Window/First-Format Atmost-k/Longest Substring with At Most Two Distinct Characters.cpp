
class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        // Write your code here
        int n=s.size();
        int i=0,j=0;
        int maxLen=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>2){
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