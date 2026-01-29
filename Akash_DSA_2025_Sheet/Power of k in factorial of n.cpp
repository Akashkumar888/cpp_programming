
class Solution {
public:
    int maxKPower(int n, int k) {
        map<int, int> primeFactors;

        // Step 1: Factorize k
        for (int i = 2; i * i <= k; ++i) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }
        if (k > 1) primeFactors[k]++; // k is prime

        int result = INT_MAX;

        // Step 2: For each prime factor, compute its count in n!
        for (auto &it : primeFactors) {
            int prime=it.first;
            int power=it.second;
            int count = 0;
            int x = n;
            while (x) {
                count += x / prime;
                x /= prime;
            }
            result = min(result, count / power);
        }

        return result;
    }
};



class Solution {
public:
    int maxKPower(int n, int k) {
        unordered_map<int,int>mp;

        // Step 1: Factorize k
        for (int i = 2; i * i <= k;i++) {
            while (k % i == 0) {
                mp[i]++;
                k/=i;
            }
        }
        if (k > 1) mp[k]++; // k is prime

        int result = INT_MAX;

        // Step 2: For each prime factor, compute its count in n!
        // Step 2: Apply Legendre’s Formula
        for (auto &it : mp) {
            int prime=it.first;
            int power=it.second;
            int count = 0;
            int x = n;
            while (x) {
                count += x / prime;
                x /= prime;
            }
            result = min(result, count / power);
        }
        return result;
    }
};
// When p is a prime number, we can use Legendre’s formula to find the highest power of p that divides n!. The formula calculates this power as: 
// Because we need to count how many times each prime factor of k divides n!.
// For a prime number p, Legendre’s formula gives:
// Power of p in n!=  ⌊n/p⌋ + ⌊n/p²⌋ + ⌊n/p³⌋ + ...



class Solution {
public:
    int maxKPower(int n, int k) {
        unordered_map<int,int>mp;

         // Step 1: Prime factorization of k
        for (int i = 2; i * i <= k;i++) {
            int num=i;
            while (k % num == 0) {
                mp[num]++; // prime number and its freq or power 
                k/=num;
            }
        }
        // Case: k = 97 (a prime number)
        // Loop: i goes from 2 to √97 ≈ 9, but 97 is not divisible by any of them.
        // So the loop doesn’t divide k at all — k is still 97.
        // Now this line:
        if (k > 1) mp[k]++; // k is prime

        int result = INT_MAX;
        // Step 2: For each prime factor, compute its count in n!
        // Apply Legendre’s Formula
        // count_p = ⌊n/p⌋ + ⌊n/p²⌋ + ⌊n/p³⌋ + ...
        // Power of prime `p` in n! = ⌊n/p⌋ + ⌊n/p²⌋ + ⌊n/p³⌋ + ... while n/p^i > 0
        for (auto &it : mp) {
            int prime=it.first;
            int power=it.second;
            int count=0;
            int number = n;
            while (number>0) {
                count += (number / prime);
                number /= prime;
            }
            // Total count of p in n! is `count`
            // Divide by the exponent of p in k to get how many times k can divide n!
            result = min(result, count / power);
            // Because we must satisfy all the prime power conditions in k.
            // The bottleneck (smallest possible value) limits the maximum x.
        }
        return result;
    }
};


// ✅ Final Time and Space Complexity
// ⏱ Time Complexity:
// O(√k + log k × log n)
// (Factorization + Prime Power Count in n!)

// 🧠 Space Complexity:
// O(log k)
// (Due to unordered_map storing prime factors of k)


