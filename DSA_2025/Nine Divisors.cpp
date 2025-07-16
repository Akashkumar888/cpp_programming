
// 🧮 PART 2: How to Count the Number of Divisors of a Number
// If the prime factorization of a number n is:
// n = p₁^e₁ × p₂^e₂ × p₃^e₃ × ... × pₖ^eₖ
// Then, the total number of divisors of n is:
// (e₁ + 1) × (e₂ + 1) × (e₃ + 1) × ... × (eₖ + 1)

// ✅ Example 2: n = 36
// Factorization:
// 36 = 2^2 × 3^2
// Number of divisors:
// (2 + 1)(2 + 1) = 3 × 3 = 9
// ✔️ Divisors: 1, 2, 3, 4, 6, 9, 12, 18, 36 ✅

// A number n has exactly 9 divisors when:
// (a) It is of the form p⁸ → (8+1 = 9)
// (b) Or p² × q² where p ≠ q (2+1)(2+1) = 9
// That's why your logic checks for:
// ans[i]^8 <= n ✅
// p^2 * q^2 <= n ✅



class Solution {
  public:
  vector<bool> seive(int n){
      vector<bool>prime(n+1,true);
      prime[0]=false;
      prime[1]=false;
      for(int i=2;i*i<=n;i++){
          if(prime[i]){
              for(int j=i*i;j<=n;j+=i){
                  prime[j]=false;
              }
          }
      }
      return prime;
  }
    int countNumbers(int n) {
        // Code Here
        typedef long long ll;
        vector<bool>prime=seive(sqrt(n)+1);
        vector<ll>ans;
        for(int i=2;i<prime.size();i++){
            if(prime[i])ans.push_back(i);
        }

        int count=0;
        for(int i=0;i<ans.size();i++){
            ll val=1;
          for(int j=1;j<=8;j++){
              val*=ans[i];
              if(val>n)break;
          }
          if(val <= n)count++;
        }
        for(int i=0;i<ans.size();i++){
            for(int j=i+1;j<ans.size();j++){
                ll p=ans[i];
                ll q=ans[j];
                if(1LL*p*p*q*q<=n)count++;
                else break;
            }
        }
        return count;
    }
};


// ⏱️ Time Complexity
// 1. Sieve of Eratosthenes (line: vector<bool> prime = seive(sqrt(n) + 1))
// You generate primes up to √n
// Time: O(√n * log(log√n)) → practically very fast
// 2. p⁸ ≤ n Loop
// For all primes p, check whether p^8 ≤ n
// Max p = n^(1/8) ⇒ Very small even for large n
// Time: O(√n) in worst case (since number of primes ≤ √n is π(√n))
// 3. p² × q² ≤ n Loop
// You loop over all pairs of distinct primes p ≠ q
// Total prime pairs: at most O((√n)^2) = O(n)
// But since p²*q² ≤ n, loop breaks early ⇒ practically: O(√n log n)

// ✅ Overall Time Complexity:
// O(√n * log log n + √n + number_of_valid_pairs)
// ≈ O(√n * log n)  in worst case
// This is efficient for n ≤ 10^9.

// 📦 Space Complexity
// Sieve storage: vector<bool> prime(sqrt(n)+1) → O(√n)
// ans stores primes up to √n: also O(√n)
// ✅ Total Space:O(√n)




