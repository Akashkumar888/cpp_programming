
#include <iostream>
#include <vector>
using namespace std;

char nonRepeatingChar(string &s) {
    vector<int> freq(26, 0); // Frequency array for 26 lowercase letters
    for (char &ch : s) {
        freq[ch - 'a']++; // Increment frequency
    }
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i]; // Return first non-repeating character
        }
    }
    return '$'; // Return '$' if all characters repeat
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    char result = nonRepeatingChar(s);
    if (result != '$') {
        cout << "The first non-repeating character is: " << result << endl;
    } else {
        cout << "All characters in the string repeat." << endl;
    }

    return 0;
}
