
class Solution {
public:
    static const int base = 256;
    static const int mod = 1000000007;

    // Function to calculate rolling hash
    long long createHash(string &s, int len) {
        long long hash = 0;
        for (int i = 0; i < len; i++) {
            hash = (hash * base + s[i]) % mod;
        }
        return hash;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;
        if (m > n) return -1;

        long long needleHash = createHash(needle, m);
        long long windowHash = createHash(haystack, m);

        long long power = 1;
        for (int i = 1; i < m; i++)
            power = (power * base) % mod;

        for (int i = 0; i <= n - m; i++) {
            if (needleHash == windowHash) {
                // Confirm match to avoid hash collision
                if (haystack.substr(i, m) == needle)
                    return i;
            }

            // Rolling hash update
            if (i < n - m) {
                windowHash = (windowHash - haystack[i] * power) % mod;
                if (windowHash < 0) windowHash += mod;

                windowHash = (windowHash * base + haystack[i + m]) % mod;
            }
        }
        return -1;
    }
};



