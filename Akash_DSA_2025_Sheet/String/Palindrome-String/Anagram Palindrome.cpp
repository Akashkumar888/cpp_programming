class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int n=s.size();
        vector<int>mp(26,0);
        for(int i=0;i<n;i++)mp[s[i]-'a']++;
        int countOddChar=0;
        for(int i=0;i<26;i++){
            if(mp[i]%2!=0)countOddChar++;
        }
        return countOddChar<=1;
    }
};
// Even length string → all characters must have even frequency
// Odd length string → only 1 character can have odd frequency

bool canFormPalindrome(string &s) {
    int mask = 0;

    for(char c : s) {
        int bit = c - 'a';
        mask ^= (1 << bit); // toggle bit
    }

    // Check at most one bit is set
    return (mask == 0) || (mask & (mask - 1)) == 0;
}
