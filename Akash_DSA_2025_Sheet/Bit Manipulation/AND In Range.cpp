
class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int bitWiseAnd=-1;
        for(int i=l;i<=r;i++){
            bitWiseAnd&=i;
        }
        return bitWiseAnd;
    }
};

// Bitwise AND (a & b)
// a&b≤min(a,b)
// ➡ Because AND only keeps 1 where both have 1, result is always less than or equal to the smaller number.

// Bitwise OR (a | b)
// a∣b≥max(a,b)
// ➡ Because OR keeps 1 if either has 1, result is always greater than or equal to the bigger number.

// Bitwise XOR (a ^ b)
// a^b = (a|b) - (a&b)
// XOR is 1 only when bits differ
// AND is 1 only when both bits are 1
// OR is 1 when any bit is 1








// ⭐ KEY OBSERVATION (Most Important)
// The bitwise AND of a range [L, R] becomes zero in any bit position where a carry occurs, meaning:
// 👉 Bits that change from 0 → 1 or 1 → 0 inside the range
// 👉 Those bits become 0 in the final AND
// Goal:
// Find the common leftmost prefix of L and R.
// All remaining lower bits become zero.
// Because whenever numbers differ in a bit position inside a range, AND becomes 0.

class Solution {
  public:
    int andInRange(int left, int right) {
        // code here
       int count=0;
       while(left!=right){
           left=left>>1;
           right=right>>1;
           count++;
       }
       return left<<count;
    }
};



class Solution {
  public:
    int andInRange(int left, int right) {
        // code here
        // The Brian Kernighan AND-reduction method (right = right & (right-1))
       while(right>left){
           right=(right&right-1);
       }
       return right;
    }
};
