
class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int n=s.size();
        int count=0;
        set<string_view> st;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                st.insert(string_view(s.data() + i, j - i + 1));
            }
        }

      return st.size();  
    }
};
// Why this is faster?
// No substring copy
// string_view is O(1) creation (stores just pointer + length)
// Memory is not duplicated
// Big speed boost for substring problems


// ✔ Real Solution → Use Suffix Automaton (SAM)
// Time complexity: O(n)
// Counts distinct substrings in linear time
// This is the intended optimal solution.

class Solution {
public:
    struct State {
        int link = -1;
        int len = 0;
        map<char, int> next;
    };

    long long countDistinctSubstrings(string &s) {
        int n = s.size();
        vector<State> st(2 * n);
        int last = 0, sz = 1;

        long long ans = 0;

        for (char c : s) {
            int cur = sz++;
            st[cur].len = st[last].len + 1;

            int p = last;
            while (p != -1 && !st[p].next.count(c)) {
                st[p].next[c] = cur;
                p = st[p].link;
            }

            if (p == -1) {
                st[cur].link = 0;
            } else {
                int q = st[p].next[c];
                if (st[p].len + 1 == st[q].len) {
                    st[cur].link = q;
                } else {
                    int clone = sz++;
                    st[clone] = st[q];
                    st[clone].len = st[p].len + 1;

                    while (p != -1 && st[p].next[c] == q) {
                        st[p].next[c] = clone;
                        p = st[p].link;
                    }
                    st[q].link = st[cur].link = clone;
                }
            }

            last = cur;
        }

        // count distinct substrings
        long long total = 0;
        for (int i = 1; i < sz; i++)
            total += st[i].len - st[st[i].link].len;

        return total;
    }

    int countSubs(string &s) {
        return countDistinctSubstrings(s);
    }
};

