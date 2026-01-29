
class Solution {
  public:
    int maxSum(string &s) {
        // code here
        int n = s.size();
    vector<int> left(n), right(n);
    
    // find longest odd-length palindrome ending 
    // at each position
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            left[r] = max(left[r], 2 * (r - i + 1) - 1);
            l--; r++;
        }
    }

    // find longest odd-length palindrome starting 
    // at each position
    for (int i = n - 1; i >= 0; i--) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            right[l] = max(right[l], 2 * (i - l + 1) - 1);
            l--; r++;
        }
    }

    // relax left array to get max till i
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i], left[i - 1]);
    }

    // relax right array to get max from i
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i], right[i + 1]);
    }

    // compute the answer by combining non-overlapping palindromes
    int maxi = 0;
    for (int i = 1; i < n; i++) {
        maxi = max(maxi, left[i - 1] + right[i]);
    }

    return maxi;
        
    }
};

class manacher {
public:
    // p[i] stores radius of palindrome centered 
    // at i in the modified string
    vector<int> p;  
    string ms;  
    manacher(string &s) {
        ms = "@";
        for (char c : s) {
            ms += "#" + string(1, c);
        }
        ms += "#$";
        runManacher();
    }
    // Runs Manacher's algorithm on transformed string `ms`
    // Fills `p[i]` with radius of palindrome centered at i
    void runManacher() {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n - 1; ++i) {
            if (r + l - i < n && r + l - i >= 0)
                p[i] = max(0, min(r - i, p[r + l - i]));

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0
                   && ms[i + 1 + p[i]] == ms[i - 1 - p[i]]) {
                ++p[i];
            }

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    // Returns length of longest odd/even 
    // palindrome centered at original index
    // `cen`
    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    // Utility function to check if 
    // substring s[l..r] is a palindrome
    bool check(int l, int r) {
        return (r - l + 1) <= getLongest((r + l) / 2, (r - l + 1) % 2);
    }
};
class Solution {
  public:
    int maxSum(string &s) {
        int n = s.size();
    vector<int> leftMark(n, 1), rightMark(n, 1);
    manacher mr(s);

    // Fill leftMark: maximum odd-length palindrome
    // ending at or before each index
    for (int i = 0; i < n; i++) {
        int val = mr.getLongest(i, 1);
        int li = i + val / 2;
        if (li < n)
            leftMark[li] = max(leftMark[li], val);
    }

    for (int i = n - 2; i >= 0; i--) {
        leftMark[i] = max(leftMark[i], leftMark[i + 1] - 2);
    }

    for (int i = 1; i < n; i++) {
        leftMark[i] = max(leftMark[i], leftMark[i - 1]);
    }

    // Fill rightMark: maximum odd-length 
    // palindrome starting at 
    // or after each index
    for (int i = n - 1; i >= 0; i--) {
        int val = mr.getLongest(i, 1);
        int ri = i - val / 2;
        if (ri >= 0)
            rightMark[ri] = max(rightMark[ri], val);
    }

    for (int i = 1; i < n; i++) {
        rightMark[i] = max(rightMark[i], rightMark[i - 1] - 2);
    }

    for (int i = n - 2; i >= 0; i--) {
        rightMark[i] = max(rightMark[i], rightMark[i + 1]);
    }

    // Combine the two arrays to compute the 
    // maximum sum of disjoint palindromes
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        ans = max(ans, leftMark[i] + rightMark[i + 1]);
    }
    return ans;
    }
};


class Solution {
  public:
    int maxSum(string &s) {
       int n = (int)s.size();
        if (n < 2) return 0;

        vector<int> rad(n); 
        for (int i = 0, L = 0, R = -1; i < n; i++) {
            int k = (i > R) ? 1 : min(rad[L + R - i], R - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            rad[i] = k;
            if (i + k - 1 > R) { 
                L = i - k + 1;
                R = i + k - 1;
            }
        }

        vector<int> bestEnd(n, 0), bestStart(n, 0);
        for (int c = 0; c < n; c++) {
            int len = 2 * rad[c] - 1;
            int l = c - rad[c] + 1;      
            int r = c + rad[c] - 1;
            bestEnd[r] = max(bestEnd[r] , len);
            bestStart[l] = max(bestStart[l] , len);
        }

        for (int i = n - 2; i >= 0; i--)
            bestEnd[i]   = max(bestEnd[i]  , bestEnd[i + 1] - 2);
            
        for (int i = 1; i < n; i++)
            bestStart[i] = max(bestStart[i], bestStart[i - 1] - 2);

        int bestLeft = 0, ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            bestLeft = max(bestLeft, bestEnd[i]);
            ans  = max(ans, bestLeft + bestStart[i + 1]);
        }
        return ans;
    }
};

// Final Complexity
// Time → O(n)

// Space → O(n)

