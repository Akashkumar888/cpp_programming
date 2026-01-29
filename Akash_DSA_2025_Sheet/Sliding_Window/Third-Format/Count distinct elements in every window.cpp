
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int>result;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[arr[j]]++;
            if(j-i+1==k){
                result.push_back(mp.size());
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};

// mp[arr[j]]++ → average O(1)
// mp[arr[i]]-- → average O(1)
// mp.erase() → average O(1)
// mp.size() → O(1)

// Time Complexity O(n)
	// ​Space Complexity O(k) because at most k distinct elements can be stored in the map.

//   1️⃣ map (Ordered Map)
// 🔹 What it is
// Stores key–value pairs
// Keys are unique
// Elements are stored in sorted order of keys
// Implemented using Red-Black Tree (self-balancing BST)
// 🔹 Properties
// Automatically sorted (ascending by default)
// Deterministic performance
// Slower than unordered_map but predictable
// 🔹 Example
// map<int,int> mp;
// mp[5] = 10;
// mp[2] = 20;
// mp[8] = 30;
// Output order:
// 2 → 20
// 5 → 10
// 8 → 30
// ⏱ Time Complexity
// Operation	Complexity
// Insert	O(log n)
// Search	O(log n)
// Delete	O(log n)
// Traversal	O(n)

// 2️⃣ unordered_map
// 🔹 What it is
// Stores key–value pairs
// Keys are unique
// No ordering of elements
// Implemented using Hash Table
// 🔹 Properties
// Fastest in practice
// Order is random
// Performance depends on hash function
// 🔹 Example
// unordered_map<int,int> mp;
// mp[5] = 10;
// mp[2] = 20;
// mp[8] = 30;
// Output order (may vary):
// 5 → 10
// 8 → 30
// 2 → 20
// ⏱ Time Complexity
// Operation	Average	Worst Case
// Insert	O(1)	O(n)
// Search	O(1)	O(n)
// Delete	O(1)	O(n)
// Traversal	O(n)	O(n)
// ⚠ Worst case happens due to hash collisions

// 3️⃣ multimap (Ordered Multi Map)
// 🔹 What it is
// Stores key–value pairs
// Duplicate keys allowed
// Elements stored in sorted order
// Implemented using Red-Black Tree
// 🔹 Properties
// Useful when one key has multiple values
// No [] operator
// Slower than unordered_multimap
// 🔹 Example
// multimap<int,int> mp;
// mp.insert({2, 100});
// mp.insert({2, 200});
// mp.insert({3, 300});
// Output:
// 2 → 100
// 2 → 200
// 3 → 300
// ⏱ Time Complexity
// Operation	Complexity
// Insert	O(log n)
// Search	O(log n)
// Delete	O(log n)
// Traversal	O(n)
// 🎯 When to Use What?
// ✅ Use unordered_map when:
// Order doesn’t matter
// Need fastest lookup
// Competitive programming / sliding window / frequency count
// ✅ Use map when:
// Sorted output needed
// Range queries (lower_bound, upper_bound)
// Predictable performance required
// ✅ Use multimap when:
// Duplicate keys required
// Sorted data with repeated keys
// 🧠 Interview Tip (Very Important)
// unordered_map is faster but unsafe in worst case
// map is slower but always safe
// That’s why:
// CP → unordered_map
// System / Interview → map (sometimes preferred)

  class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=arr.size();
        int i=0,j=0;
        while(j<k){
            mp[arr[j]]++;
            j++;
        }
        ans.push_back(mp.size());
        while(j<n){
            mp[arr[j]]++;
            mp[arr[i]]--;
            if(mp[arr[i]]==0)mp.erase(arr[i]);
            i++;
            j++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};
