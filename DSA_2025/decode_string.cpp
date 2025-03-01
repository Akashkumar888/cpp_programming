
#include <bits/stdc++.h>
using namespace std;

string decodedString(string &s) {
    string ans = "";
    int num = 0;
    int n = s.size();
    stack<int> st1;
    stack<string> st2;
    
    for (char &ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // Forming the full number
        } 
        else if (ch == '[') {
            st1.push(num);    // Push the number
            st2.push(ans);    // Push current string
            num = 0;          // Reset num
            ans = "";         // Reset string
        } 
        else if (ch == ']') {
            int repeat = st1.top();
            st1.pop();
            string temp = ans;
            for (int i = 1; i < repeat; i++) {
                ans += temp;  // Repeat the substring
            }
            ans = st2.top() + ans;
            st2.pop();
        } 
        else {
            ans += ch;  // Append character to current string
        }
    }
    
    return ans;
}

int main() {
    string s = "3[a2[bc]]";
    cout << decodedString(s) << endl;  // Output: "abcbcabcbcabcbc"
    return 0;
}
