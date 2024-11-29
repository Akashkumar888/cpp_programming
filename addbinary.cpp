
#include <iostream>
#include <string>
using namespace std;

string addBinary(string& s1, string& s2) {
    string ans = "";
    int n1 = s1.size();
    int n2 = s2.size();
    int carry = 0;
    int one = 0;
    int i = n1 - 1, j = n2 - 1;

    // Process both strings from the end
    while (i >= 0 || j >= 0) {
        if (i >= 0 && s1[i] == '1') one++;
        if (j >= 0 && s2[j] == '1') one++;

        if (one + carry == 0) {
            ans = '0' + ans;
            carry = 0;
        } else if (one + carry == 1) {
            ans = '1' + ans;
            carry = 0;
        } else if (one + carry == 2) {
            ans = '0' + ans;
            carry = 1;
        } else if (one + carry == 3) {
            ans = '1' + ans;
            carry = 1;
        }

        one = 0; // Reset counter for '1's
        i--;
        j--;
    }

    // Add leftover carry
    if (carry == 1) ans = '1' + ans;

    return ans;
}

int main() {
    string s1, s2;
    cout << "Enter first binary string: ";
    cin >> s1;
    cout << "Enter second binary string: ";
    cin >> s2;

    string result = addBinary(s1, s2);
    cout << "Result of binary addition: " << result << endl;

    return 0;
}
