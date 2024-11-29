
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        // Sort both strings
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        // Compare the sorted strings
        return s1 == s2;
    }
};

int main() {
    Solution solution;

    // Input strings
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    // Check if the strings are anagrams
    if (solution.areAnagrams(s1, s2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
