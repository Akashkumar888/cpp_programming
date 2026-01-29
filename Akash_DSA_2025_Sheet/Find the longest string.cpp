
class Solution {
  public:
    string longestString(vector<string> &arr) {
        sort(arr.begin(), arr.end());  // lexicographical sort
        unordered_set<string>st;
        string ans = "";

        for (string &word : arr) {
            if (word.length()==1 || st.find(word.substr(0,word.size()-1))!=st.end()) {
                st.insert(word);
                if (word.length() > ans.length() || 
                   (word.length() == ans.length() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
// 🔹 Time and Space Complexity:
// Part	Complexity
// Sorting	O(n log n)
// Processing words	O(n·L)
// Hash set storage	O(n·L)

// ✅ Final Time Complexity: O(n·L + n log n) → still efficient
// ✅ Space Complexity: O(n·L)




class TrieNode{
    public:
    TrieNode* children[26];
    bool endOfWord;
    string word;
    TrieNode(){ //  constructor 
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        endOfWord=false;
        word="";
    }  
    ~ TrieNode(){ // destructor
        for(int i=0;i<26;i++){
           delete children[i];
        }
    }  
};
class Solution {
public:
void insert(TrieNode * root,string &str){
    TrieNode*crawl=root;
    for(char &ch:str){
        int idx=ch-'a';
        if(crawl->children[idx]==NULL){
            crawl->children[idx]=new TrieNode();
        }
        crawl=crawl->children[idx];
    }
    crawl->endOfWord=true;
    crawl->word=str;
}
// insert function always same only search function changes 
bool search(TrieNode*root,string &str){
    TrieNode*crawl=root;
    for(char &ch:str){
        int idx=ch-'a';
        crawl = crawl->children[idx];
        if(crawl==NULL || crawl->endOfWord==false) return false;
    }
    return true;
}
    string longestString(vector<string> &arr) {
        TrieNode* root = new TrieNode();
        for(string &word : arr) insert(root,word);
        string ans = "";
        for(string &word :arr) {
            if(search(root, word)) {
                // If multiple strings have the same maximum length, return the lexicographically smallest one.
                if(word.length()>ans.length()||
                (word.length()==ans.length()&&word<ans)) {
                    ans = word;
                }
            }
        }
        delete root;
        return ans;
    }
};




// ✅ Time Complexity:
// Insert All Strings into Trie:
// Each string takes O(L) time (where L = length of string).
// For n strings:
// O(n * L)
// Search all Prefixes for each Word:
// For each word, you check each character (and ensure prefix is valid), again O(L) per string.
// Total:
// O(n * L)
// Final Comparison for Longest + Lexicographically Smallest:
// Done in O(1) per string (constant-time comparisons using length() and operator<)
// ✅ Final Time Complexity:
// O(n * L)
// Where:
// n = number of strings
// L = maximum length of a string in arr[]

// ✅ Space Complexity:
// Trie Space:
// At most one node per unique character in all strings.
// In worst-case (no shared prefixes), you create n * L nodes.
// Other Auxiliary Space:
// string ans (O(1) for storage)
// Function call stack is O(1), no recursion or deep stack use.
// ✅ Final Space Complexity:
// O(n * L)

