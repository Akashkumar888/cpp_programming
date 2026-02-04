

class RabinKarpHash {
private:
    const int mod = 1e9 + 7;
    const int base = 31;
    vector<int> hash;
    vector<int> power;

    // modular addition
    int add(int a, int b) {
        a += b;
        if (a >= mod) a -= mod;
        return a;
    }

    // modular subtraction
    int sub(int a, int b) {
        a -= b;
        if (a < 0) a += mod;
        return a;
    }

    // modular multiplication
    int mul(int a, int b) {
        return (int)((1LL * a * b) % mod);
    }

    // convert character to int 
    // ('a' = 1, ..., 'z' = 26)
    int charToInt(char c) {
        return c - 'a' + 1;
    }

public:
    // constructor: precomputes prefix hashes and powers
    RabinKarpHash(string &s) {
        int n = s.size();
        hash.resize(n);
        power.resize(n);

        hash[0] = charToInt(s[0]);
        power[0] = 1;

        for (int i = 1; i < n; ++i) {
            hash[i] = add(mul(hash[i - 1], base), charToInt(s[i]));
            power[i] = mul(power[i - 1], base);
        }
    }

    // get hash of substring s[l...r] in O(1)
    int getSubHash(int l, int r) {
        int h = hash[r];
        if (l > 0) {
            h = sub(h, mul(hash[l - 1], power[r - l + 1]));
        }
        return h;
    }
};



class RabinKarpHash {
private:
    const int mod = 1e9 + 7;
    const int base = 31;
    vector<int> hash;
    vector<int> power;

    // modular addition
    int add(int a, int b) {
        a += b;
        if (a >= mod) a -= mod;
        return a;
    }

    // modular subtraction
    int sub(int a, int b) {
        a -= b;
        if (a < 0) a += mod;
        return a;
    }

    // modular multiplication
    int mul(int a, int b) {
        return (int)((1LL * a * b) % mod);
    }

    // convert character to int 
    // ('a' = 1, ..., 'z' = 26)
    int charToInt(char c) {
        return c - 'a' + 1;
    }

public:
    // constructor: precomputes prefix hashes and powers
    RabinKarpHash(string &s) {
        int n = s.size();
        hash.resize(n);
        power.resize(n);

        hash[0] = charToInt(s[0]);
        power[0] = 1;

        for (int i = 1; i < n; ++i) {
            hash[i] = add(mul(hash[i - 1], base), charToInt(s[i]));
            power[i] = mul(power[i - 1], base);
        }
    }

    // get hash of substring s[l...r] in O(1)
    int getSubHash(int l, int r) {
        int h = hash[r];
        if (l > 0) {
            h = sub(h, mul(hash[l - 1], power[r - l + 1]));
        }
        return h;
    }
};

// Rabin-Karp search using hash class
vector<int> searchPattern(string &text, string &pattern) {
    int n = text.size(), m = pattern.size();

    RabinKarpHash textHash(text);
    RabinKarpHash patHash(pattern);

    int patternHash = patHash.getSubHash(0, m - 1);
    vector<int> result;

    for (int i = 0; i <= n - m; i++) {
        int subHash = textHash.getSubHash(i, i + m - 1);
        if (subHash == patternHash) {
            result.push_back(i);
        }
    }

    return result;
}



class RabinKarpHash {
private:
    const int mod1 = 1e9 + 7;
    const int mod2 = 1e9 + 9;
    const int base1 = 31;
    const int base2 = 37;

    vector<int> hash1, hash2;
    vector<int> power1, power2;

    // modular addition
    int add(int a, int b, int mod) {
        a += b;
        if (a >= mod) a -= mod;
        return a;
    }

    // modular subtraction
    int sub(int a, int b, int mod) {
        a -= b;
        if (a < 0) a += mod;
        return a;
    }

    // modular multiplication
    int mul(int a, int b, int mod) {
        return (int)((1LL * a * b) % mod);
    }

    // convert character to int
    int charToInt(char c) {
        return c - 'a' + 1;
    }

public:
    // constructor: precomputes both prefix hashes and powers
    RabinKarpDoubleHash(string &s) {
        int n = s.size();
        hash1.resize(n);
        hash2.resize(n);
        power1.resize(n);
        power2.resize(n);

        hash1[0] = charToInt(s[0]);
        hash2[0] = charToInt(s[0]);
        power1[0] = 1;
        power2[0] = 1;

        for (int i = 1; i < n; ++i) {
            hash1[i] = add(mul(hash1[i - 1], base1, mod1),
                                            charToInt(s[i]), mod1);
                                            
            power1[i] = mul(power1[i - 1], base1, mod1);

            hash2[i] = add(mul(hash2[i - 1], base2, mod2), 
                                            charToInt(s[i]), mod2);
                                            
            power2[i] = mul(power2[i - 1], base2, mod2);
        }
    }

    // get double hash of substring s[l...r]
    vector<int> getSubHash(int l, int r) {
        int h1 = hash1[r];
        int h2 = hash2[r];
        if (l > 0) {
            h1 = sub(h1, mul(hash1[l - 1], power1[r - l + 1], mod1), mod1);
            h2 = sub(h2, mul(hash2[l - 1], power2[r - l + 1], mod2), mod2);
        }
        return {h1, h2};
    }
};




// 3️⃣ Rabin–Karp Algorithm
// 🔹 Idea
// Uses hashing instead of character-by-character comparison.
// Compute hash of pattern
// Compute rolling hash of text substrings
// Compare hashes → if equal, check characters
// 🔹 How It Works
// Calculate hash of pattern.
// Calculate hash of first window of text.
// Slide window:
// Remove left character
// Add right character
// Recalculate hash (rolling hash)
// If hashes match → verify string.
// 🔹 Time & Space Complexity
// Average: O(n + m)
// Worst case: O(nm) (hash collision)
// Space: O(1)
// 🔹 Where Rabin–Karp Is Used
// ✔️ Multiple pattern matching
// ✔️ Plagiarism detection
// ✔️ Document similarity
// ✔️ Searching large texts
// ✔️ Cybersecurity (signature matching)

class Solution {
public:
    static const int base = 256;
    static const int mod = 1000000007;

    long long getHash(const string &s, int len) {
        long long h = 0;
        for (int i = 0; i < len; i++) {
            h = (h * base + s[i]) % mod;
        }
        return h;
    }

    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();

        // Build repeated string until length >= b
        string repeated = a;
        int count = 1;

        while (repeated.size() < m) {
            repeated += a;
            count++;
        }

        // One extra repeat for overlap cases
        repeated += a;

        // Rabin–Karp setup
        long long bHash = getHash(b, m);
        long long windowHash = getHash(repeated, m);

        long long power = 1;
        for (int i = 1; i < m; i++)
            power = (power * base) % mod;

        for (int i = 0; i + m <= repeated.size(); i++) {
            if (bHash == windowHash) {
                if (repeated.substr(i, m) == b) {
                    return (i + m + n - 1) / n; // minimum repeats
                }
            }

            // rolling hash update
            if (i + m < repeated.size()) {
                windowHash = (windowHash - repeated[i] * power) % mod;
                if (windowHash < 0) windowHash += mod;

                windowHash = (windowHash * base + repeated[i + m]) % mod;
            }
        }
        return -1;
    }
};
