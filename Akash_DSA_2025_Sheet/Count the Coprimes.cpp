// 🔷 What is the Möbius Function?
// The Möbius function μ(n) is a number-theoretic function defined for positive integers n as:
// μ(1) = 1
// μ(n) = 0 if n is not square-free (i.e., divisible by a square > 1 like 4, 9, 16, etc.)
// μ(n) = (−1)^k if n is a product of k distinct primes
// (i.e., square-free and has even/odd number of distinct prime factors)
// 🔷 Why Möbius Function?
// When you want to count coprime pairs using Inclusion-Exclusion Principle, the Möbius function is the key.
// If f(i) is the number of array elements divisible by i, then the number of pairs (a, b) such that gcd(a, b) = 1 is:



class Solution {
  public:

    // Function to compute Möbius function mu[1..n]
    vector<int> getMobius(int n) {
        vector<int> mu(n + 1, 1);       // Initialize all values to 1
        vector<bool> isPrime(n + 1, true); // Mark all numbers as prime initially

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) { // If i is prime
                // Multiply mu[j] by -1 for all multiples of i
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    isPrime[j] = false; // Mark non-prime
                }

                // If a number has a squared prime factor, set mu[j] = 0
                for (long long j = 1LL * i * i; j <= n; j += 1LL * i * i) {
                    mu[j] = 0; // Not square-free
                }
            }
        }
        return mu;
    }

    // Main function to count coprime pairs
    int cntCoprime(vector<int>& arr) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());

        // Step 1: Count frequency of each number
        vector<int> freq(maxi + 1, 0);
        for (int &num : arr) {
            freq[num]++;
        }

        // Step 2: Count how many elements are divisible by i
        // Formula: divCount[i] = ∑ freq[j] for all j such that i divides j
        vector<int> divCount(maxi + 1, 0);
        for (int i = 1; i <= maxi; i++) {
            for (int j = i; j <= maxi; j += i) {
                divCount[i] += freq[j];
            }
        }

        // Step 3: Compute Möbius function values
        // μ(n) is:
        //   1 if n is square-free with even number of prime factors
        //  -1 if n is square-free with odd number of prime factors
        //   0 if n has squared prime factor (not square-free)
        vector<int> mobius = getMobius(maxi);

        // Step 4: Use inclusion-exclusion principle
        // For each i, count how many pairs have gcd = i
        // Number of coprime pairs = ∑ μ[d] * C(divCount[d], 2)
        // where C(n, 2) = n * (n - 1) / 2 is the number of ways to choose 2 out of n
        long long totalPairs = 0;
        for (int i = 1; i <= maxi; i++) {
            long long cnt = divCount[i];
            if (cnt >= 2 && mobius[i] != 0) {
                // Number of unordered pairs = C(cnt, 2) = cnt * (cnt - 1) / 2
                // Adds or subtracts the number of pairs where gcd = d
                totalPairs += 1LL * mobius[i] * (cnt * (cnt - 1)) / 2;
            }
        }

        return int(totalPairs);
    }
};


// ⏱ Time Complexity:
// 1. getMobius(n):
// Outer loop: from 2 to n.
// Inner loop 1 (multiples of i): ~n/i steps.
// Inner loop 2 (multiples of i*i): ~n/i² steps.
// So total cost: O(nlogn)

// 💾 Space Complexity:
// mu[], isPrime[], freq[], divCount[] all of size ≈ O(max(arr))
// No extra space for recursion or complex data structures. O(max(arr))

