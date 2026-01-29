class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n=s.size();
        int totalSwap=n*(n-1)/2;
        vector<int>mp(26,0);
        int duplicate=0;
        for(char &ch:s)mp[ch-'a']++;
        for(int i=0;i<26;i++){
            if(mp[i]>1){
            duplicate+=mp[i]*(mp[i]-1)/2;
            }
        }
// ✅ If no duplicates, return total (i.e., all swaps produce unique results)
        if(duplicate==0)return total;
// ✅ If some duplicates, then subtract invalid swaps, and add 1 for the original string itself (why?)
        return totalSwap-duplicate+1;
    }
};
