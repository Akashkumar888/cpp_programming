
class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.size();
        int idx1=0,idx2=0;
        char maxch='0',minch='9';
        for(int i=0;i<n;i++){
            if(maxch<=s[i]){
                maxch=s[i];
                idx1=i;
            }
            else if(minch>=s[i]){
                minch=s[i];
                idx2=i;
            }
        }
        for(int i=0;i<idx2;i++){
            if(i<idx1 && s[i]<maxch){
            swap(s[i],s[idx1]);
                return s;
            }
        }
       if(idx2<idx1)swap(s[idx2],s[idx1]);
        return s;
    }
};

// ⏱ Time and Space Complexity of your code
// Time Complexity:
// First loop: O(n)
// Second loop: O(n)
// → Overall: O(n)

// Space Complexity:
// Only a few extra variables, no extra data structures.
// → O(1)


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
