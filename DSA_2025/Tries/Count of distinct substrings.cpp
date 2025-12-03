
class TrieNode {
public:
    int childcount;
    bool isendof;
    string word;
    TrieNode* children[26];

    TrieNode() {
        childcount = 0;
        isendof=false;
        word="";
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    ~TrieNode(){
    for(int i=0;i<26;i++){
       delete children[i];
    }
    }
};
class Solution {
public:
    void insert(TrieNode* root, string &s, int start,int &totalNodes) {
        TrieNode* crawler = root;
        for (int i = start; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = new TrieNode();
                totalNodes++;  // count distinct path created
            }
            crawler = crawler->children[idx];
        }
        crawler->isendof = true;
    }
    int countSubs(string& s) {
        TrieNode* root = new TrieNode();
        int totalNodes = 0;
        int n=s.size();
        for (int i = 0; i < n; i++) {
            insert(root, s, i,totalNodes);
        }
        return totalNodes;
    }
};
