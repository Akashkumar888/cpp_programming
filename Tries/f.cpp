
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
public:
    struct TrieNode {
        bool isEndOfWord;
        int frequency;  // Store frequency of each word
        TrieNode* children[26];
    };

    TrieNode* root;

    Trie() {
        root = getNode();
    }

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isEndOfWord = false;
        newNode->frequency = 0;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    // Insert word into Trie and update its frequency
    void insert(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) {
                temp->children[idx] = getNode();
            }
            temp = temp->children[idx];
        }
        temp->isEndOfWord = true;
        temp->frequency++;  // Increment frequency on insert
    }

    // Search for the frequency of a word
    int searchFrequency(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) return 0;
            temp = temp->children[idx];
        }
        return (temp != NULL && temp->isEndOfWord) ? temp->frequency : 0;
    }
};

class Solution {
public:
    typedef pair<string, int> P;

    // Function to find the top K frequent words
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;

        Trie trie;
        unordered_map<string, int> mp;

        // Insert words into the Trie and record frequencies
        for (string& word : words) {
            trie.insert(word);
            mp[word]++;
        }

        // Custom comparator for sorting the heap
        auto cmp = [&](P& a, P& b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        };

        // Custom heap for storing top K frequent words
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

        // Insert elements from the map into the heap
        for (auto& it : mp) {
            pq.push({it.first, it.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Collect results from the heap
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());  // Reverse to get the correct order
        return ans;
    }
};

// Main function
int main() {
    Solution solution;

    // Test case 1
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    // Call the topKFrequent function
    vector<string> result = solution.topKFrequent(words, k);

    // Output the result
    cout << "Top " << k << " frequent words: ";
    for (string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
