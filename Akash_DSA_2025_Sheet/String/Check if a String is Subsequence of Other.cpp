
class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(s1[i]==s2[j])i++;
            j++;
        }
        return i==m;
    }
};

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        int i=0,j=0;
        while(j<n){
            if(s1[i]==s2[j])i++;
            j++;
        }
        return i==m;
    }
};


// ✅ Time Complexity

// You iterate over both strings once at most.
// Worst case: j goes through all n characters of s2, and i moves only when matches occur.
// So, O(n) where n = s2.size().
// (m ≤ n, so you can also say O(m + n), but effectively O(n)).

// ✅ Space Complexity
// You only use a few variables (i, j, m, n).
// No extra data structures.
// So, O(1) (constant extra space).

