
class TrieNode{
  public:
  TrieNode*children[26];
  bool endofword;
  TrieNode(){
      for(int i=0;i<26;i++){
          children[i]=NULL;
      }
      endofword=false;
  }
};
class Trie {
  public:
   TrieNode*root;
    Trie() {
        // implement Trie
        root=new TrieNode();
    }

    void insert(string &word) {
        // insert word into Trie
        TrieNode*crawl=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=new TrieNode();
            }
            crawl=crawl->children[idx];
        }
        crawl->endofword=true;
    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode*crawl=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl=crawl->children[idx];
        }
        return (crawl->endofword==true);
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        TrieNode*crawl=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL)return false;
            crawl=crawl->children[idx];
        }
        return true;
    }
  };

  