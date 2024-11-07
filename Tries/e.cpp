
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    struct trieNode {
        bool isendofword;
        trieNode* children[26];
    };

    trieNode* root;

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isendofword = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    // Function to insert a word into the Trie
    void insert(string& word) {
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

    // Function to search for the root form of a word
    string search(string& word) {
        trieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) return word;

            temp = temp->children[idx];
            if (temp->isendofword == true) return word.substr(0, i + 1);
        }
        return word;
    }

    // Function to replace words with their root forms
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = getNode();
        int n = dictionary.size();

        // Insert all dictionary words into the Trie
        for (int i = 0; i < n; i++) {
            string word = dictionary[i];
            insert(word);
        }

        // Replace words in the sentence
        stringstream ss(sentence);
        string result = "";
        string temp;
        while (getline(ss, temp, ' ')) {
            result += search(temp) + ' ';
        }

        // Remove the last extra space and return the result
        result.pop_back();
        return result;
    }
};

int main() {
    // Create the solution object
    Solution solution;

    // Example dictionary and sentence
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    // Call the replaceWords function and store the result
    string result = solution.replaceWords(dictionary, sentence);

    // Output the result
    cout << "Original sentence: " << sentence << endl;
    cout << "Modified sentence: " << result << endl;

    return 0;
}
