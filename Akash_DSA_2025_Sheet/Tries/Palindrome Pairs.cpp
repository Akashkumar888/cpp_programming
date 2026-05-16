
class TrieNode {
public:
    int childCount;
    // index of complete word
    int idx;
    // store indices whose remaining prefix
    // is palindrome
    vector<int> indices;
    TrieNode* children[26];
    TrieNode(){
        childCount = 0;
        idx = -1;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
    ~TrieNode(){
        for(int i = 0; i < 26; i++){
            delete children[i];
        }
    }
};
class Solution {
  public:
    bool isPalindrom(string &s,int left,int right){
        while(left < right){
            if(s[left] != s[right])return false;
            left++;
            right--;
        }
        return true;
    }
    /*
        Insert REVERSED word into trie

        Example:
        abc -> cba
    */
    void insert(string &word,int idx,TrieNode* &root){
        TrieNode* crawler = root;
        int n = word.size();
        // insert reverse direction
        for(int i = n - 1; i >= 0; i--){
            /*
                If remaining prefix is palindrome
                store current word index
            */
            if(isPalindrom(word,0,i)){
                crawler->indices.push_back(idx);
            }
            int childIdx = word[i] - 'a';
            if(crawler->children[childIdx] == NULL){
                TrieNode* newnode = new TrieNode();
                crawler->children[childIdx] = newnode;
                crawler->childCount++;
            }
            crawler = crawler->children[childIdx];
        }
        // complete word end
        crawler->idx = idx;
        crawler->indices.push_back(idx);
    }
    bool search(string &word,int idx,TrieNode* &root){
        TrieNode* crawler = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            /*
                CASE 1
                Trie word ended

                Remaining current suffix
                should be palindrome
            */

            if(crawler->idx >= 0 && crawler->idx != idx && isPalindrom(word,i,n-1)){
                return true;
            }
            int childIdx = word[i] - 'a';
            if(crawler->children[childIdx] == NULL)return false;
            crawler = crawler->children[childIdx];
        }
        /*
            CASE 2

            current word fully traversed

            check all stored palindrome indices
        */
        for(int storedIdx : crawler->indices){
            if(storedIdx != idx)return true;
        }
        return false;
    }
    bool palindromePair(vector<string>& arr) {
        TrieNode* root = new TrieNode();
        int n = arr.size();
        // insert all words
        for(int i = 0; i < n; i++){
            insert(arr[i],i,root);
        }
        // search palindrome pair
        for(int i = 0; i < n; i++){
            if(search(arr[i],i,root))return true;
        }
        return false;
    }
};


class Solution{
    public:
    // Function to check if a string is palindrome
    bool isPalindrome(string &s) {
        int n = s.length();
        int i=0,j=n-1;
        // compare each character from starting
        // with its corresponding character from last
        while (i<j ){
            if (s[i] != s[j])return false;
            i++,j--;
        }
        return true;
    }
    bool palindromePair(vector<string>& arr) {
            // Consider each pair one by one
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j< arr.size(); j++) {
                // concatenate both strings
                string str = arr[i] + arr[j];
    
                // check if str is palindrome
                if (isPalindrome(str))
                    return true;
    
                // check for other combination
                str = arr[j] + arr[i];
                if (isPalindrome(str))
                    return true;
            }
        }
        return false;
    }
};

class Solution {
  public:
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right])return false;
            left++;
            right--;
        }
        return true;
    }
    bool palindromePair(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string,int> mp;
        // store all strings
        for(int i = 0; i < n; i++)mp[arr[i]] = i;
        
        // check every word
        for(int i = 0; i < n; i++){
            string word = arr[i];
            int len = word.size();
            // split at every position
            for(int cut = 0; cut <= len; cut++){
                string prefix = word.substr(0, cut);
                string suffix = word.substr(cut);
                /*
                    Case 1:

                    prefix palindrome

                    need reverse(suffix)
                */
                if(isPalindrome(word, 0, cut - 1)){
                    string revSuffix = suffix;
                    
                    reverse(revSuffix.begin(),revSuffix.end());

                    if(mp.count(revSuffix) && mp[revSuffix] != i)return true;
                }
                /*
                    Case 2:

                    suffix palindrome

                    need reverse(prefix)
                */

                // avoid duplicate checking
                if(cut != len && isPalindrome(word, cut, len - 1)){

                    string revPrefix = prefix;

                    reverse(revPrefix.begin(),revPrefix.end());

                    if(mp.count(revPrefix) && mp[revPrefix] != i)return true;
                }
            }
        }
        return false;
    }
};