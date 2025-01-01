
#include <iostream>
#include <string>
#include <algorithm> // For count function
using namespace std;

int maxScore(string s) {
    int n = s.size();
    int maxsr = 0;
    int zr = 0, on = 0;

    // Count total number of '1's in the string
    int one = count(s.begin(), s.end(), '1');

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') zr++;
        else on++;
        maxsr = max(maxsr, zr + (one - on));
    }
    return maxsr;
}

int main() {
    string s;

    cout << "Enter the binary string: ";
    cin >> s;

    int result = maxScore(s);
    cout << "Maximum score is: " << result << endl;

    return 0;
}
