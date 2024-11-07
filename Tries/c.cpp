
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie {
public:
    struct TrieNode {
        bool isEndOfNumber;
        TrieNode* children[10];
    };

    TrieNode* root;

    Trie() {
        root = getNode();
    }

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();
        newNode->isEndOfNumber = false;
        for (int i = 0; i < 10; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    // Insert number into the Trie as string
    void insert(int num) {
        TrieNode* currentNode = root;
        string strNum = to_string(num);  // Convert number to string to insert into Trie

        for (char ch : strNum) {
            int idx = ch - '0';
            if (currentNode->children[idx] == NULL) {
                currentNode->children[idx] = getNode();
            }
            currentNode = currentNode->children[idx];
        }
        currentNode->isEndOfNumber = true;
    }

    // DFS-like function to get lexicographical order numbers
    void collectNumbers(TrieNode* node, string currentNumber, vector<int>& result) {
        if (node->isEndOfNumber) {
            result.push_back(stoi(currentNumber));
        }
        for (int i = 0; i < 10; i++) {
            if (node->children[i]) {
                collectNumbers(node->children[i], currentNumber + to_string(i), result);
            }
        }
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie trie;
        vector<int> result;

        // Insert numbers from 1 to n into Trie
        for (int i = 1; i <= n; i++) {
            trie.insert(i);
        }

        // Collect numbers in lexicographical order
        trie.collectNumbers(trie.root, "", result);

        return result;
    }
};

int main() {
    // Create the Solution object
    Solution solution;

    // Define the input number n
    int n = 25;

    // Get the lexicographical order of numbers
    vector<int> result = solution.lexicalOrder(n);

    // Output the result
    cout << "Lexicographical order of numbers from 1 to " << n << ":" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
