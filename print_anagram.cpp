
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> anagrams(vector<string>& arr) {
    int n = arr.size();
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;

    for (string &str : arr) {
        string temp = str;
        sort(str.begin(), str.end());      // Sort the string to create the key
        mp[str].push_back(temp);          // Group anagrams
    }

    for (auto &it : mp) {
        result.push_back(it.second);      // Collect all groups of anagrams
    }

    return result;
}

int main() {
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = anagrams(arr);

    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

