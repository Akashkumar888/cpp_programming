
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int dfs(Node* root,long long currSum,int k,unordered_map<long long,int>&mp){
        if(root==NULL)return 0;
        currSum+=root->data;
        int count=0;
        if(mp.find(currSum-k)!=mp.end())count+=mp[currSum-k];
        mp[currSum]++;
        count+=dfs(root->left,currSum,k,mp);
        count+=dfs(root->right,currSum,k,mp);
        mp[currSum]--;
        return count;
    }
    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int>mp;
        mp[0]=1;
        return dfs(root,0,k,mp);
    }
};


// 1️⃣ Why we use mp[0] = 1 in this problem
// In Path Sum K in a Tree, we are counting how many paths have sum = k.
// We use prefix sum idea:
// currSum - k
// If this value existed before, a valid path exists.
// But what if the path starting from the root itself equals k?

// Example:

//     5
//    /
//   2
// k = 7
// Path:
// 5 → 2 = 7
// When we reach node 2:
// currSum = 7
// currSum - k = 7 - 7 = 0
// Now we check:
// mp[0]
// So we must already have 0 prefix sum counted once.
// That is why we initialize:
// mp[0] = 1;
// Meaning:
// Empty path sum = 0 exists once
// So root-to-node paths are counted correctly.
// if(mp.find(currSum-k)!=mp.end())count+=mp[currSum-k];

// 2️⃣ When we use mp[0] = -1
// This is used in array problems when storing index of prefix sum.
// Example problem:
// Longest subarray with sum = k
// Code idea:
// if(mp.find(prefixSum-k)!=mp.end())
//     length = i - mp[prefixSum-k];
// Here we store index.
// Example:
// Array
// [1,2,3]
// k = 3
// Prefix sums:
// i=0 → 1
// i=1 → 3
// At i=1
// prefixSum = 3
// prefixSum - k = 0
// If mp[0] = -1:
// length = 1 - (-1) = 2
// Subarray:
// [1,2]
// Correct.
// So:
// mp[0] = -1
// means:
// prefix sum 0 occurred before array started

// if(mp.find(preSum-1)!=mp.end())maxlen=max(maxlen,i-mp[preSum-1]);
// if(mp.find(preSum)==mp.end())mp[preSum]=i;


// if(mp.find(preSum-k)!=mp.end())maxlen=max(maxlen,i-mp[preSum-k]);
// if(mp.find(preSum)==mp.end())mp[preSum]=i;


// 3️⃣ Quick Rule (Very Important for Interviews)
// When counting number of subarrays / paths
// Use:
// mp[0] = 1
// because we count frequency.
// When finding longest length / index
// Use:
// mp[0] = -1
// because we store index.
