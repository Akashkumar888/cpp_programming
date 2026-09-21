
class Solution {
  public:
    int transform(string &s1, string &s2) {
        int n = s1.size();

        // Length must be same
        if(s1.size() != s2.size())return -1;

        // Step 1: Check both strings have
        // same characters with same frequency
        vector<int> freq(256, 0);

        for(char ch : s1){
            freq[ch]++;
        }

        for(char ch : s2){
            freq[ch]--;
        }

        for(int i = 0; i < 256; i++){
            if(freq[i] != 0){
                return -1;
            }
        }

        // Step 2: Compare from right to left
        int i = n - 1;// for s1
        int j = n - 1;// for s2
        int count = 0;
        while(i >= 0){
            // Character is already in correct relative order
            if(s1[i] == s2[j]){
                i--;
                j--;
            }
            // This character needs to be moved to front
            else{
                count++;
                i--;
            }
        }
        return count;
    }
};