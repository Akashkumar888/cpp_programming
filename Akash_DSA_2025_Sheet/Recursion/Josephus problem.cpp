
class Solution {
  public:
// Josephus ka formula yaad rakhne ka sabse simple mental trick ye hai:
// “Har baar ek aadmi nikalta hai, circle rotate hota hai by k.”
// Isliye n se n-1 me jaate waqt answer shift hota hai.
// Base case yaad rakho:
// n = 1 → sirf ek banda → answer = 0 (0-based)
// Ab har baar jab ek banda nikalta hai:
// Pehle circle me n log the
// Ek nikal gaya → n-1 log bache
// Par starting point k se aage shift ho gaya
// Isliye formula ban jaata hai:
// solve(n, k) = (solve(n-1, k) + k) % n

// Isko yaad rakhne ka one-line trick:
// “Answer(n) = Answer(n-1) + k, but circle hai isliye % n.”
// Ya ek aur easy rhyme style:
// One man left → answer 0,
// Every step add k,
// Circle hai → mod n.

  // solve(n,k)=(solve(n-1,k) + k ) % n;
  int solve(int n,int k){
      if(n==1)return 0;
      // recursion tree banao pahle (n,k) ke liye
      // n to n-1 to n==1 tk ka cicrle hoga each time 
      // n to n-1 to n==1 tk ka cicrle hoga k ka use krte hue number ko delete krke
      // dono n-1 cicrle ka relation banao each time ke liye 
      return (solve(n-1,k) + k ) % n;//// shift + wrap, Har level pe +k, Circle hai → % n
  }
    int josephus(int n, int k) {
        // code here
        return solve(n,k) + 1;// + 1 because Given integers n and k, return the position (1-based index) of the person who will survive.
    }
};