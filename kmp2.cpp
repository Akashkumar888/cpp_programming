
#include <bits/stdc++.h>
using namespace std;

bool areRotations(string &s1, string &s2) {
    // Check if lengths are the same
    if (s1.size() != s2.size()) return false;

    // Concatenate s1 with itself
    string temp = s1 + s1;

    // Implement KMP for substring search
    int n = temp.size(), m = s2.size();
    vector<int> lps(m, 0);

    // Compute LPS array for s2
    for (int i = 1, len = 0; i < m;) {
        if (s2[i] == s2[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    // Search for s2 in temp using KMP
    for (int i = 0, j = 0; i < n;) {
        if (temp[i] == s2[j]) {
            i++, j++;
            if (j == m) return true;
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }

    return false;
}

int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    if (areRotations(s1, s2)) {
        cout << "Yes, they are rotations of each other." << endl;
    } else {
        cout << "No, they are not rotations of each other." << endl;
    }

    return 0;
}
