
#include <bits/stdc++.h>
using namespace std;

int evaluateNested(string s) {
    int depth = 0;
    int total = 0;
    int num = -1; // to collect digits if multi-digit numbers appear

    for (char c : s) {
        if (c == '[') {
            depth++; // going deeper
        } 
        else if (c == ']') {
            depth--; // going back
        } 
        else if (isdigit(c)) {
            // convert char to int
            num = c - '0';
            total += num * depth; // multiply by current depth
        }
        // ignore commas and others
    }
    return total;
}

int main() {
    string s = "[[2,1],2,[2,1]]";
    cout << evaluateNested(s) << endl; // Output: 14
    return 0;
}
