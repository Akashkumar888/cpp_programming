
class TrieNode{
public:
    int childcount;
    bool isendof;
    TrieNode* children[26];
    TrieNode(){
        childcount=0;
        isendof=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
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
    void insert(TrieNode* root,string &word){
        TrieNode* crawler=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=new TrieNode();
            }
            crawler=crawler->children[idx];
            // Number of words passing through this node
            crawler->childcount++;
        }
        crawler->isendof=true;
    }
    string search(TrieNode* root,string &word){
        TrieNode* crawler=root;
        string ans="";
        for(char &ch:word){
            int idx=ch-'a';
            crawler=crawler->children[idx];
            ans+=ch;
            // First node visited by only one word
            if(crawler->childcount==1) break;
        }
        return ans;
    }
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root=new TrieNode();
        for(string &word:arr){
            insert(root,word);
        }
        vector<string> result;
        for(string &word:arr){
            result.push_back(search(root,word));
        }
        delete root;
        return result;
    }
};