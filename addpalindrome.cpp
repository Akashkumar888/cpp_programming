#include <bits/stdc++.h>
using namespace std;

int minChar(string& s) {
    int n = s.size();
    if (n == 1) return 0; // Single character is already a palindrome

    string rev = s;
    reverse(rev.begin(), rev.end());
    string comb = s + '+' + rev;
    int m = comb.size();

    // LPS array
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
        if (comb[i] == comb[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Minimum characters to add
    return n - lps[m - 1];
}

int main() {
    string s = "aacecaaa";
    cout << "Minimum characters to make the string a palindrome: " << minChar(s) << endl;

    s = "abcd";
    cout << "Minimum characters to make the string a palindrome: " << minChar(s) << endl;

    return 0;
}
