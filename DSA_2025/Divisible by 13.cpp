
// This is based on a mathematical property of modular arithmetic:
// If
// A ≡ r (mod m)
// and you append a digit d,
// then A' = A*10 + d ≡ (r*10 + d) mod m

class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int n=s.size();
        int rem=0;
        for(char &ch:s){
            int digit=ch-'0';
//  How it avoids overflow
// Instead of computing the actual number (which might have 1e5 digits!), you maintain:
            rem=(rem*10+digit)%13;
            // So you're never storing the full number, only the mod 13 remainder.
        }
        return rem==0;
    }
};


// ✅ Time: O(n) per check
// ✅ No need for big integers, works for strings of size up to 10⁵+


// You can write a similar function for any divisor:
// is completely valid and correct for checking divisibility of any large number (given as a string) by a small integer divisor (within the int range).


bool divisibleBy(string &s, int divisor) {
    int rem = 0;
    for (char ch : s) {
        rem = (rem * 10 + (ch - '0')) % divisor;
    }
    return rem == 0;
}

