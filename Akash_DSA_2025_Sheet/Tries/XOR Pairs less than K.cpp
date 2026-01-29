
class Solution {
  public:
    int cntPairs(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[i]^arr[j])<k)count++;
            }
        }
        return count;
    }
};



// Trie is combination of linklist and binary Tree
class TrieNode {
public:
    int childCount;
    bool isendof;
    string word;
    TrieNode* children[2];
    TrieNode() {
        childCount = 0;
        isendof=false;
        word="";
        for (int i=0;i<2;i++) {
            children[i]=NULL;
        }
    }
    ~TrieNode(){
    for(int i=0;i<2;i++){
       delete children[i];
    }
  }
};
class Solution {
  public:
  void insert(TrieNode* root,int num) {
        TrieNode* crawler = root;
        for(int i=31;i>=0;i--) { // beacuse msb here i check < k that's why we start from right to left 
// Using RIGHT SHIFT
// (num >> i) & 1
// Using LEFT MASK
// (num & (1 << i))
// Expression	            Meaning	                                    Returns
// (num >> i) & 1	        Extract i-th bit (0 or 1)	                0 or 1
// num & (1 << i)	        Check if i-th bit is set	0 or            non-zero
            int bit=(num >> i) & 1;
            if(crawler->children[bit]==NULL) {
                crawler->children[bit]=new TrieNode();
            }
            crawler = crawler->children[bit];
            crawler->childCount++;
        }
        crawler->isendof=true;
    }
  // Count numbers already in trie that satisfy (num XOR y) < k
  // insert function always same only search function change hota hai.
    int countLessThanK(TrieNode* root, int num, int k) {
        TrieNode* crawler=root;
        int count=0;
        for(int i=31;i>=0;i--){
            if(crawler==NULL) break;
            int bitX = (num >> i) & 1;
            int kth_bit = (k >> i) & 1;
            if (kth_bit == 1) {
                // Case 1: Take branch where XOR = 0 (free contribution)
                TrieNode* sameBit = crawler->children[bitX];
                if (sameBit) count += sameBit->childCount;
                // Case 2: Continue matching in XOR = 1 path
                int oppositeBit=1 - bitX;
                crawler = crawler->children[oppositeBit];
            } 
            else {
                // Must continue in branch where XOR = 0
                crawler = crawler->children[bitX];
            }
        }
        return count;
    }
    int cntPairs(vector<int>& arr, int k) {
        // code here
        TrieNode* root = new TrieNode();
        int result = 0;
        for (int &num : arr) {
            result += countLessThanK(root,num,k);
            insert(root, num);// ek ek element pusk krte jao
        }
        return result;
    }
};


// ✅ ⏳ Time Complexity
// We insert each number into a 32-bit trie, and for each number, we also search through 32 bits.
// 🔹 Insert operation
// For each number → 32 steps
// So: O(32) ≈ O(1)
// 🔹 Search (countLessThanK)
// Again 32 steps → O(32) ≈ O(1)
// 🔹 For n numbers
// Total = n × (Insert + Search) 
//       = n × (32 + 32)
//       = 64n
//       = O(n)
// ⭐ Final Time Complexity:
// ✅ O(n)
// This is a massive improvement over brute-force O(n²).
// 🧠 Why O(n) and not O(n log n)?
// Trie height is constant (32 bits) → does NOT grow with n
// Each operation is bounded
// So total operations grow linearly with n
// → O(n)
// 🗂 📦 Space Complexity
// Trie stores bits of all inserted numbers.
// Each number contributes 32 nodes, unless shared.
// Worst-case (all bit patterns unique):
// Space = n × 32 nodes
// Each node stores:
// 2 child pointers
// count
// some metadata
// So total space:
// ✅ O(32 × n) → O(n)