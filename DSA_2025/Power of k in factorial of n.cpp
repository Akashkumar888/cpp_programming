
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
