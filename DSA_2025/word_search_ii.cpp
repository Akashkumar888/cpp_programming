
#include <vector>
#include <string>
using namespace std;

int m, n;
vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class TrieNode {
public:
    bool endofword;
    string word;
    TrieNode* children[26];

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        endofword = false;
        word = "";
    }

    ~TrieNode() {  // Destructor to free memory
        for (int i = 0; i < 26; i++) {
            if (children[i]) delete children[i];
        }
    }
};

void insert(TrieNode* root, string &word) {
    TrieNode* crawler = root;
    for (char ch : word) {
        int idx = ch - 'a';
        if (!crawler->children[idx]) {
            crawler->children[idx] = new TrieNode();
        }
        crawler = crawler->children[idx];
    }
    crawler->endofword = true;
    crawler->word = word;
}

void findword(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& result) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL)
        return;

    char ch = board[i][j];
    root = root->children[ch - 'a'];

    if (root->endofword) {
        result.push_back(root->word);
        root->endofword = false;  // Prevent duplicate results
        root->word = "";  // Clear stored word
    }

    board[i][j] = '$'; // Mark visited

    for (auto &dir : directions) {
        findword(board, i + dir[0], j + dir[1], root, result);
    }

    board[i][j] = ch; // Restore character
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;  // ✅ Now result is local, not global
        m = board.size();
        n = board[0].size();
        TrieNode* root = new TrieNode();

        for (string &word : words) {
            insert(root, word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (root->children[board[i][j] - 'a']) {
                    findword(board, i, j, root, result);
                }
            }
        }

        delete root;  // ✅ Free Trie memory
        return result;
    }
};
