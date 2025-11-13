
class TrieNode{
public:
    bool isendof;
    string word;
    TrieNode * children[26];
    TrieNode(){
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    isendof=false;
    word="";
    }
    ~TrieNode(){
    for(int i=0;i<26;i++){
       delete children[i];
    }
    }
};
class Trie {
    private:
    TrieNode*root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*crawler=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                TrieNode*newnode=new TrieNode();
                crawler->children[idx]=newnode;
            }
            crawler=crawler->children[idx];
        }
        crawler->isendof=true;
    }
    
    bool search(string word) {
        TrieNode*crawler=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawler->children[idx]==NULL)return false;
        crawler=crawler->children[idx];
        }
        return (crawler!=NULL && crawler->isendof==true);
    }
    
    bool startsWith(string prefix) {
        TrieNode*crawler=root;
        for(char &ch:prefix){
            int idx=ch-'a';
            if(crawler->children[idx]==NULL)return false;
            crawler=crawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
