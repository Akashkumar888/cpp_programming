#include <iostream>
using namespace std;

class Trie {
public:
    struct trieNode {
        bool isendofword;
        trieNode* children[26];
    };

    trieNode* root;

    Trie() {
        root = getNode();
    }

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isendofword = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(string word) {
        trieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) {
                temp->children[idx] = getNode();
            }
            temp = temp->children[idx];
        }
        temp->isendofword = true;
    }

    bool search(string word) {
        trieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) {
                return false;
            }
            temp = temp->children[idx];
        }
        return (temp != NULL && temp->isendofword == true);
    }

    bool startsWith(string prefix) {
        trieNode* temp = root;
        int i = 0;
        for (; i < prefix.size(); i++) {
            char ch = prefix[i];
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) {
                return false;
            }
            temp = temp->children[idx];
        }
        return (i == prefix.size());
    }
};

int main() {
    Trie* trie = new Trie();

    // Insert words into the trie
    trie->insert("apple");
    trie->insert("app");

    // Search for words
    cout << "Searching for 'apple': " << (trie->search("apple") ? "Found" : "Not Found") << endl;  // Output: Found
    cout << "Searching for 'app': " << (trie->search("app") ? "Found" : "Not Found") << endl;      // Output: Found
    cout << "Searching for 'ap': " << (trie->search("ap") ? "Found" : "Not Found") << endl;        // Output: Not Found

    // Check prefixes
    cout << "Prefix 'app' exists: " << (trie->startsWith("app") ? "Yes" : "No") << endl;           // Output: Yes
    cout << "Prefix 'ap' exists: " << (trie->startsWith("ap") ? "Yes" : "No") << endl;             // Output: Yes
    cout << "Prefix 'b' exists: " << (trie->startsWith("b") ? "Yes" : "No") << endl;               // Output: No

    // Clean up
    delete trie;

    return 0;
}
