#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;
    int m, n;

    struct trieNode {
        bool endofword;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endofword = false;
        newNode->word = "";
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string& word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endofword = true;
        crawler->word = word;
    }

    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void findword(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL) return;

        root = root->children[board[i][j] - 'a'];
        if (root->endofword == true) {
            result.push_back(root->word);
            root->endofword = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            findword(board, new_i, new_j, root);
        }
        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        trieNode* root = getNode();

        for (string& word : words) {
            insert(root, word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                int idx = ch - 'a';
                if (root->children[idx] != NULL) {
                    findword(board, i, j, root);
                }
            }
        }

        return result;
    }
};

int main() {
    // Define the board
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    // Define the words to search
    vector<string> words = {"oath", "pea", "eat", "rain"};

    // Create an object of the Solution class
    Solution solution;

    // Find words in the board
    vector<string> foundWords = solution.findWords(board, words);

    // Output the found words
    cout << "Found words: " << endl;
    for (string& word : foundWords) {
        cout << word << endl;
    }

    return 0;
}
