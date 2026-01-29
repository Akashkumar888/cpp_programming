

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
    void insert(TrieNode* root, string &word) {
        TrieNode* crawler = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) {
                TrieNode* newnode = new TrieNode();
                crawler->children[idx] = newnode;
            crawler->childcount++;
            }
            crawler = crawler->children[idx];
        }
        crawler->isendof=true;
    }

    void search(TrieNode* root, string &word,string&ans) {
        TrieNode* crawler = root;
        for (char &ch : word) {
            int idx = ch - 'a';
            if (crawler->childcount==1) {
                ans+=ch;
            crawler = crawler->children[idx];
            } else {
                break;
            }
        if(crawler->isendof)break;
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
       for(string &word:strs){
        if(word=="")return "";
       } 

        TrieNode* root = new TrieNode();
        for (string &word : strs) {
            insert(root, word);
        }

        string ans = "";
            search(root,strs[0],ans);
        return ans;
    }
};
