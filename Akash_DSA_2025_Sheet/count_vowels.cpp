
#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Function to solve the vowel strings problem
vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
    int n = words.size();
    vector<int> ans;
    vector<int> pre_vowel(n, 0);
    int count = 0;

    // Create the prefix array
    for (int i = 0; i < n; i++) {
        if (isVowel(words[i].front()) && isVowel(words[i].back())) {
            count++;
        }
        pre_vowel[i] = count;
    }

    // Process the queries
    for (int i = 0; i < queries.size(); i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        if (left > 0) {
            ans.push_back(pre_vowel[right] - pre_vowel[left - 1]);
        } else {
            ans.push_back(pre_vowel[right]);
        }
    }
    return ans;
}

int main() {
    vector<string> words = {"apple", "orange", "umbrella", "eye", "kite"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {0, 4}};

    vector<int> result = vowelStrings(words, queries);

    // Print the results
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
