#include <iostream>
#include <vector>
using namespace std;

string multiplyStrings(string& s1, string& s2) {
    // Handle sign
    bool isNegative = false;
    if (s1[0] == '-') {
        isNegative = !isNegative;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        isNegative = !isNegative;
        s2 = s2.substr(1);
    }

    // Remove leading zeros
    while (s1.length() > 1 && s1[0] == '0') s1.erase(0,1);
    while (s2.length() > 1 && s2[0] == '0') s2.erase(0,1);


    // ✅ If your string starts with one or more '0' characters (example: "00023"),
    // ✅ It deletes the '0' from the beginning one-by-one, until:
    
    // Either the first character is not '0' anymore, or
    
    // Only one character is left (so we don't erase the full number accidentally).


    if (s1 == "0" || s2 == "0") return "0";

    int n = s1.size(), m = s2.size();
    vector<int> result(n + m, 0);

    // Multiply each digit
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    // Build answer string
    string ans = "";
    int i = 0;
    while (i < result.size() && result[i] == 0) i++; // skip leading zeros

    while (i< result.size()) {
        ans += (result[i] + '0');
        i++;
    }

    if (isNegative) ans = "-" + ans;
    return ans;
}

