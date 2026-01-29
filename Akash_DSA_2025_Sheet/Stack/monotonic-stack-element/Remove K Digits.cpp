
class Solution {
public:
    string removeKdig(string s, int k) {
        int n = s.size();
        if(n == 0) return "0";
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        // If k still remains, remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        // remove leading zeros
        while (result.size() > 1 && result[0] == '0')result.erase(0, 1);
        return result.empty() ? "0" : result;
        // Better & Efficient Way (Single Operation)
        // int i = 0;
        // while(i < result.size() && result[i] == '0') i++;
        // result.erase(0, i);
        // return result.empty() ? "0" : result;
    }
};

// Both versions are correct, but in practice the second one is better and more efficient.
// Your current loop version
while (result.size() > 1 && result[0] == '0')
    result.erase(0, 1);
return result.empty() ? "0" : result;


// Removes one zero at a time
// Each erase(0,1) shifts the whole string → O(n)
// If there are many leading zeros, total time becomes O(n²) in worst case
// Better & Efficient (Single Operation)
int i = 0;
while (i < result.size() && result[i] == '0') i++;
result.erase(0, i);
return result.empty() ? "0" : result;


// Counts all leading zeros first
// Erases them in one shot
// Time complexity: O(n)
// Which one should you use?

// For interview / competitive programming / large inputs →
// 👉 Use the second method (single erase).
// It shows that you understand:
// string::erase cost
// Time complexity implications
// Optimization mindset