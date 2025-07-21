
class Solution {
  public:
  vector<int> getMobius(int n) {
        vector<int> mu(n + 1, 1);
        vector<bool> isPrime(n + 1, true);

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    isPrime[j] = false;
                }
                for (long long j = 1LL * i * i; j <= n; j += 1LL * i * i) {
                    mu[j] = 0;  // Not square-free
                }
            }
        }
        return mu;
    }
    int cntCoprime(vector<int>& arr) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());

        // Step 1: Frequency of each number
        vector<int> freq(maxi + 1, 0);
        for (int &num : arr) {
            freq[num]++;
        }

        // Step 2: Count how many numbers divisible by i
        vector<int> divCount(maxi + 1, 0);
        for (int i = 1; i <= maxi;i++) {
            for (int j = i; j <= maxi; j += i) {
                divCount[i] += freq[j];
            }
        }

        // Step 3: Compute Möbius function
        vector<int> mobius = getMobius(maxi);

        // Step 4: Inclusion-Exclusion principle to count coprime pairs
        long long totalPairs = 0;
        for (int i = 1; i <= maxi; i++) {
            long long cnt = divCount[i];
            if (cnt >= 2 && mobius[i] != 0) {
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

