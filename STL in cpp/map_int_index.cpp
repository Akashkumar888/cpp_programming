#include <bits/stdc++.h>
using namespace std;

int main() {
    string t = "AKASHAKASH";
    unordered_map<char, int> mp;

    for (char &ch : t) {
        mp[ch]++;
    }

    // Now you can print the map
    for (const auto &pair : mp) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
