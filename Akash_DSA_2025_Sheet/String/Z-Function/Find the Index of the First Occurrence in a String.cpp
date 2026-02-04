
class {
public:
vector<int> zFunction(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            // Case 2: reuse the previously computed value
            z[i] = min(r - i + 1, z[k]);
        }
        // Try to extend the Z-box beyond r
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        // Update the [l, r] window if extended
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
};




class {
  public:
  // Z-function to compute Z-array
  vector<int> zFunction(string &s) {
      int n = s.length();
      vector<int> z(n);
      int l = 0, r = 0;
  
      for (int i = 1; i < n; i++) {
          if (i <= r) {
              int k = i - l;
              
              // Case 2: reuse the previously computed value
              z[i] = min(r - i + 1, z[k]);
          }
  
          // Try to extend the Z-box beyond r
          while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
              z[i]++;
          }
  
          // Update the [l, r] window if extended
          if (i + z[i] - 1 > r) {
              l = i;
              r = i + z[i] - 1;
          }
      }
  
      return z;
  }
  

  // Function to find all occurrences of pattern in text
  vector<int> search(string &text, string &pattern) {
      string s = pattern + '$' + text;
      vector<int> z = zFunction(s);
      vector<int> pos;
      int m = pattern.size();
  
      for (int i = m + 1; i < z.size(); i++) {
          if (z[i] == m){
              // pattern match starts here in text
              pos.push_back(i - m - 1); 
          }
      }
      return pos;
  }
};


// 2️⃣ Z-Algorithm (Z-Index Method)
// 🔹 Idea
// For a string S, Z[i] tells:
// Length of the longest substring starting at i which matches the prefix of S.
// 🔹 How It Is Used for Pattern Matching
// Create a new string:
// pattern + "$" + text


// Compute Z-array.
// If any Z[i] == pattern length, pattern exists at that index.
// 🔹 Example
// Pattern = "abc"
// Text = "xabcab"
// Combined string:
// abc$xabcab

// If Z[i] == 3, match found.
// 🔹 Time & Space Complexity
// Time: O(n + m)
// Space: O(n + m)

// 🔹 Where Z-Algorithm Is Used
// ✔️ Fast pattern matching
// ✔️ Finding repetitions in strings
// ✔️ String compression
// ✔️ Competitive programming
// ✔️ Bioinformatics


class Solution {
public:
    // Z-Algorithm to compute Z array
    void Zalgo(string &s, vector<int> &Z) {
        int n = s.size();
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i <= r)
                Z[i] = min(r - i + 1, Z[i - l]);

            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
                Z[i]++;

            if (i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        string combined = needle + "$" + haystack;
        int n = combined.size();
        vector<int> Z(n, 0);
        Zalgo(combined, Z);
        int patLen = needle.size();
        for (int i = 0; i < n; i++) {
            if (Z[i] == patLen) {
                return i - patLen - 1;  // index in haystack
            }
        }
        return -1;
    }
};

