
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int longestUniqueSubstr(string &s) {
    int n = s.size();
    vector<int> mp(26, 0);  // Frequency map for characters
    int i = 0, j = 0;
    int len = INT_MIN;

    while (j < n) {
        // Include the current character in the window
        mp[s[j] - 'a']++;

        // Shrink the window until it's valid (all unique characters)
        while (mp[s[j] - 'a'] > 1) {
            mp[s[i] - 'a']--;
            i++;
        }

        // Update the maximum length
        len = max(len, j - i + 1);

        // Expand the window
        j++;
    }

    return len;
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    int result = longestUniqueSubstr(input);
    cout << "Length of the longest substring with unique characters: " << result << endl;

    return 0;
}

