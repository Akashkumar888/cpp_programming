
class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        vector<int> last(10, -1);
        for(int i = 0; i < n; i++)last[s[i] - '0'] = i;
        
        for(int i = 0; i < n; i++) {
            for(int d = 9; d > s[i] - '0'; d--) {
                if(last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }
        return s;
    }
};



class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        // '0' ≤ s[i] ≤ '9'
        // each index -1 
        vector<int>last_occurrence(10,-1);

        // Record last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last_occurrence[s[i] - '0'] = i;
        }

        // Traverse from left and find a bigger digit later
        for (int i = 0; i < n; i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                // last occurrence of each digit 
                int last_idx=last_occurrence[d];
                if (last_idx > i) {
                    swap(s[i], s[last_idx]);
                    return s;
                }
            }
        }
        return s;
    }
};