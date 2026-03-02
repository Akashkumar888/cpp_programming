
#include <bits/stdc++.h>
using namespace std;

int minRecolors(const string &s) {
    int n = s.size();
    int ans = INT_MAX;

    set<char> st(s.begin(), s.end());

    for (char t : st) {
        int ops = 0;
        bool in = false;

        for (int i = 0; i < n; i++) {
            if (s[i] != t) {
                if (!in) {
                    ops++;
                    in = true;
                }
            } else {
                in = false;
            }
        }

        ans = min(ans, ops);
    }

    return ans;
}