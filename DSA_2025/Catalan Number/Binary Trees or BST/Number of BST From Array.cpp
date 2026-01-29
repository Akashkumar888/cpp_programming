
class Solution {
  public:
// We are given a sorted array of distinct elements, say:
// arr = [2, 1, 3]
// When a particular element arr[i] is chosen as the root of a Binary Search Tree (BST):
// All smaller elements go to the left subtree
// All greater elements go to the right subtree
// We must find how many unique BSTs can be formed with that root.
// ⚙️ Core Idea (Catalan Concept)
// For any set of n distinct numbers,
// the total number of unique BSTs = Catalan number Cₙ = (2n)! / ((n+1)! n!)
// But here, instead of total BSTs, we are finding for each element how many BSTs are possible when that element is the root.
// 🧮 Approach
// Sort the array (if not already sorted) — BST structure depends on relative order.
// For each element arr[i]:
// Elements to the left of it → can form L nodes in the left subtree.
// Elements to the right of it → can form R nodes in the right subtree.
// The number of unique BSTs when arr[i] is root = count(i)=Catalan(L)×Catalan(R)
// because:
// Left subtree can be formed in Catalan(L) ways.
// Right subtree can be formed in Catalan(R) ways.
// Combine both sides (independent choices multiply).

    // Function to compute Catalan numbers using DP
    vector<long long> computeCatalan(int n) {
        vector<long long> catalan(n + 1, 0);
        catalan[0] =1 ;
        catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan;
    }
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> result(n, 0);

        // store original order
        vector<int> original = arr;

        // Step 1: Sort the array (for BST logic)
        sort(arr.begin(), arr.end());

        // Step 2: Precompute Catalan numbers
        vector<long long> catalan = computeCatalan(n);

        // Step 3: Map element → count
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int L = i; // curr 
            int R = n - 1 -i; // last 
            mp[arr[i]] = catalan[L] * catalan[R];
        }

        // Step 4: Rebuild result in original order
        for (int i = 0; i < n; i++) {
            result[i] = mp[original[i]];
        }

        return result;
    }
};