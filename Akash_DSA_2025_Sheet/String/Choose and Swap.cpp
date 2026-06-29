
class Solution {
  public:
    string chooseSwap(string &s) {
        int n=s.size();
        vector<int> firstOccurence(26, -1);
        
        for (int i = 0; i < n; i++) {
            if (firstOccurence[s[i] - 'a'] == -1){
                firstOccurence[s[i] - 'a'] = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (char ch = 'a'; ch < s[i]; ch++) {
                if (firstOccurence[ch - 'a'] > i) {
                    char c1 = s[i];
                    char c2 = ch;
                    
                    for (int j = 0; j < n; j++) {
                        if (s[j] == c1){
                            s[j] = c2;
                        }
                        
                        else if (s[j] == c2){
                            s[j] = c1;
                        }
                    }
                    return s;
                }
            }
        }
        return s;
    }
};