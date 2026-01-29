
class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int m=pat.size();
        int n=tar.size();
        // beacause no need to delete or add in string 
        int i=m-1,j=n-1;
        while(i>=0 && j>=0){
            if(pat[i]==tar[j]){
            j--;
            i--;    
            }
            // If not → skip pat[i] plus one more character (i -= 2) → this simulates the push + pop operation on the stack.
            // being pushed on stack → and immediately popped (hence i -= 2).
            // Append the character pat[i] to the string s.
           // Delete the last character of s (if s is empty do nothing).
            else i-=2;
        }
        return j==-1;
    }
};



// 🔹 Time Complexity
// You move through pat with i-- or i-=2, and through tar with j--.
// In the worst case, you’ll traverse each character of pat once.
// So, O(m) where m = pat.size().
// Since n <= m, that also covers tar.

// ✅ Time = O(m)
// 🔹 Space Complexity
// You don’t actually construct the stack or extra string s.
// Just a few variables (i, j).
// ✅ Space = O(1)




// ✅ Right-to-left (your current solution): O(m), O(1), very neat.
// ❌ Left-to-right without stack: Not possible, because deletions depend on future context.
// ✅ Left-to-right with explicit stack: Possible, but takes O(m) time and O(m) space.
