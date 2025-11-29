
class Solution {
  public:
    int countSetBits(int n) {
        // code here
        long long ans=0;
        for(int i=0;(1LL<<i)<=n;i++){
            long long cycle=1LL<<(i+1);
            long long half=1LL<<i;
            long long full=n/cycle;
            ans+=full*half;
            long long rem=n%cycle;
            ans+=max(0LL,rem-half+1);
        }
        return ans;
    }
};

// 🧠 Main Logic:
// For each bit position i, count:
// How many complete ON–OFF cycles occur
// How many extra 1s come from leftover part

// Then add them.
// ⭐ Now, line-by-line breakdown
// for(int i=0;(1LL<<i)<=n;i++){

// ✔ Loop over each bit position
// Runs for bit = 0,1,2,... until 2^i > n.

// long long cycle = 1LL << (i + 1);
// ✔ Full pattern length at bit i

// For bit i:
// 0...0  (2^i times)
// 1...1  (2^i times)


// Total cycle length = 2^(i+1).

// long long half = 1LL << i;
// ✔ Number of 1’s in each full cycle

// Each cycle contains exactly:
// 2^i  ones

// long long full = n / cycle;
// ✔ Number of complete cycles in 1..n

// Example for i=1 (pattern 0 0 | 1 1):

// 1..n
// | full cycles | extra |

// ans += full * half;

// ✔ All full cycles contribute:
// (full cycles) × (2^i ones per cycle)

// This adds the guaranteed 1’s.

// long long rem = n % cycle;

// ✔ Size of leftover part after full cycles

// This leftover may contribute partial 1’s.

// ans += max(0LL, rem - half + 1);

// ✔ Count extra 1’s in leftover part

// If leftover part exceeds the first half zeros,
// then the remaining (rem - half + 1) elements have bit i = 1.

// Example:
// i = 2 → half = 4

// pattern = 0000 | 1111
// rem = 5  
// bit=1 from 5 - 4 + 1 = 2 values → correct

// return ans;
// ✔ Final total set bit count from 1 to n.