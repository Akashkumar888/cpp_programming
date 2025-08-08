
class TrieNode{
    public:
    TrieNode* children[26];
    int iscount;
    string word;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        iscount=0;
        word="";
    }
    ~TrieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
    }
};
class Solution {
  public:
  void insert(TrieNode*root,string &s){
      TrieNode*crawl=root;
      for(char &ch:s){
          int idx=ch-'a';
          if(crawl->children[idx]==NULL){
              crawl->children[idx]=new TrieNode();
          }
          crawl=crawl->children[idx];
      }
      crawl->iscount++;
      crawl->word=s;
  }
  int search(TrieNode*root,string &s){
      TrieNode*crawl=root;
      for(char &ch:s){
          int idx=ch-'a';
          if(crawl->children[idx]==NULL)return 0;
          crawl=crawl->children[idx];
      }
      return crawl->iscount;
  }
    int getLPSLength(string &s) {
    int n = s.size();
    TrieNode *suffixTrie = new TrieNode();

    // Insert all reversed suffixes
    for (int i = 1; i < n; i++) { // i=1 skips the whole string
        string suffix = s.substr(i);
        reverse(suffix.begin(), suffix.end());
        insert(suffixTrie, suffix);
    }

    int count = 0;
    for (int i = 0; i < n-1; i++) {
        string prefix = s.substr(0, i+1);
        reverse(prefix.begin(), prefix.end());
        if (search(suffixTrie, prefix)) {
            count = max(count, i+1);
        }
    }

    delete suffixTrie;
    return count;
}
};



class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n=s.size();
        vector<int>lps(n,0);
        int pre=0,suf=1;
        while(suf<n){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++,suf++;
            }
            else{
                if(pre==0){
                lps[suf]=0;    
                suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps[n-1];
    }
};

// Time Complexity
// The while loop runs until suf < n, and inside it, pre moves back using the lps array without re-checking characters unnecessarily.
// This ensures each character is processed at most twice (once moving forward, once moving back).
// Time: O(n)

// Space Complexity
// You store an lps array of size n.
// Space: O(n) (extra space for lps)
