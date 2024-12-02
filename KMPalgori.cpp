
#include <bits/stdc++.h>
using namespace std;

// Build the LPS (Longest Prefix Suffix) array
void KMP(string &needle, vector<int> &lps) {
    int pre = 0, suf = 1;
    while (suf < needle.size()) {
        if (needle[pre] == needle[suf]) {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        } else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } else {
                pre = lps[pre - 1];
            }
        }
    }
}

// Perform KMP search
vector<int> search(string pat, string txt) {
    vector<int> ans;
    int m = pat.size();
    int n = txt.size();
    vector<int> lps(m, 0);
    KMP(pat, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            ans.push_back(i - j);  // Pattern found
            j = lps[j - 1];        // Prepare for the next match
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return ans;
}

int main() {
    string txt = "abcabcabcd";
    string pat = "abc";
    vector<int> result = search(pat, txt);

    cout << "Pattern found at indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}
