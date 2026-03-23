

// bfs ke two template 
// 🔥 BFS Templates — When to Use Which?

// There are mainly 3 practical BFS patterns used in industry + DSA:

// ✅ 1️⃣ Normal BFS (Single Loop Template)
// while(!q.empty()){
//     auto node = q.front();
//     q.pop();
// }

// 📌 When to use?
// When you don’t care about levels
// When you just need:
// Traversal
// Reachability
// Visited marking
// 🔹 Example Problems:
// Graph traversal
// Connected components
// Checking cycle in undirected graph
// Flood fill (without time tracking)

// ✅ 2️⃣ Level Order BFS (Two Loop Template)
// while(!q.empty()){
//     int sz = q.size();
//     for(int i=0;i<sz;i++){
//         auto node = q.front();
//         q.pop();
//     }
// }
// 📌 When to use?
// When level matters.
// 👉 Each loop = 1 level = 1 minute / 1 distance step
// 🔥 Use this when:
// You need minimum distance
// You need time taken
// You need multi-source BFS
// Binary tree level order traversal
// 🔹 Example Problems:
// Rotting Oranges 🍊
// Word Ladder
// Shortest Path in Unweighted Graph
// Binary Tree Level Order

// ✅ 3️⃣ BFS with Time Stored in Queue
// queue<pair<pair<int,int>,int>> q; 
// // {{i,j}, time}
// 📌 When to use?
// When:
// Time per node can differ
// You don’t want level loop
// Cleaner implementation
// This avoids:
// int sz = q.size();
// Instead you push:
// q.push({{ni,nj}, t+1});
// 🔥 Used in:
// Grid problems
// Spread problems
// Shortest path with equal weight edges


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
// minimum time required to burn the entire tree -> use bfs 
// every graph is a tree but every tree is not graph
// tree is directed graph from parent to child
// here we need to undirected graph that's why convert tree to undirected graph 
void buildGraph(TreeNode*root,unordered_map<int,vector<int>>&graph){
    if(root==NULL)return ;
    if(root->left){
       graph[root->val].push_back(root->left->val);
       graph[root->left->val].push_back(root->val);
       buildGraph(root->left,graph); 
    }
    if(root->right){
       graph[root->val].push_back(root->right->val);
       graph[root->right->val].push_back(root->val);
       buildGraph(root->right,graph);
    }
}
void bfs(unordered_map<int,vector<int>>&graph,TreeNode* target,vector<int>&result,int k){
    queue<int>q;
    unordered_set<int>visited;
    int minTime = 0;
    q.push(target->val);//All the values Node.val are unique.
    visited.insert(target->val);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
        int curr=q.front();
        q.pop();
        if(minTime==k)result.push_back(curr);
            for(auto &ngbr:graph[curr]){
            if(visited.find(ngbr)==visited.end()){
                q.push(ngbr);
                visited.insert(ngbr);
            }
        }
    }
       minTime++;
    }
    return minTime;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>graph;
        vector<int>result;
        buildGraph(root,graph);
        bfs(graph,target,result,k);
        return result;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// undirected graph 
void makegraph(TreeNode*root,unordered_map<TreeNode*,vector<TreeNode*>>&adj){
    if(root==NULL)return;
    if(root->left){
        adj[root->left].push_back(root);
        adj[root].push_back(root->left);
        makegraph(root->left,adj);
    }
    if(root->right){
        adj[root->right].push_back(root);
        adj[root].push_back(root->right);
        makegraph(root->right,adj);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>visited;
        makegraph(root,adj);
        queue<TreeNode*>q;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(k==0)ans.push_back(curr->val);
                for(auto &ngbr:adj[curr]){
                    if(visited.find(ngbr)==visited.end()){
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            if(k==0) break; // already collected nodes at distance k
            k--;
        }
        return ans;
    }
};



class Solution {
public:
// minimum time required to burn the entire tree -> use bfs 
// every graph is a tree but every tree is not graph
// tree is directed graph from parent to child
// here we need to undirected graph that's why convert tree to undirected graph 
void buildGraph(TreeNode*root,unordered_map<int,vector<int>>&graph){
    if(root==NULL)return ;
    if(root->left){
       graph[root->val].push_back(root->left->val);
       graph[root->left->val].push_back(root->val);
       buildGraph(root->left,graph); 
    }
    if(root->right){
       graph[root->val].push_back(root->right->val);
       graph[root->right->val].push_back(root->val);
       buildGraph(root->right,graph);
    }
}
void bfs(unordered_map<int,vector<int>>&graph,TreeNode* target,vector<int>&result,int k){
    typedef pair<int,int>P;
    queue<P>q;
    unordered_set<int>visited;
    int maxTime = 0;
    q.push({0,target->val});//All the values Node.val are unique.
    visited.insert(target->val);
    while(!q.empty()){
        int tm=q.front().first;
        int curr=q.front().second;
        q.pop();
        maxTime=max(maxTime,tm);
        if(maxTime==k)result.push_back(curr);
            for(auto &ngbr:graph[curr]){
            if(visited.find(ngbr)==visited.end()){
                q.push({tm+1,ngbr});
                visited.insert(ngbr);
            }
    }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>graph;
        vector<int>result;
        buildGraph(root,graph);
        bfs(graph,target,result,k);
        return result;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// minimum time required to burn the entire tree -> use bfs 
// every graph is a tree but every tree is not graph
// tree is directed graph from parent to child
// here we need to undirected graph that's why convert tree to undirected graph 

// Step 1: store parent mapping
void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    markParent(root, parent);

    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;

    q.push(target);
    visited.insert(target);

    int level = 0;

    while (!q.empty()) {
        int size = q.size();

        // when we reach level k → collect answer
        if (level == k) {
            vector<int> result;
            while (!q.empty()) {
                result.push_back(q.front()->val);
                q.pop();
            }
            return result;
        }

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            // left
            if (curr->left && !visited.count(curr->left)) {
                visited.insert(curr->left);
                q.push(curr->left);
            }

            // right
            if (curr->right && !visited.count(curr->right)) {
                visited.insert(curr->right);
                q.push(curr->right);
            }

            // parent
            if (parent[curr] && !visited.count(parent[curr])) {
                visited.insert(parent[curr]);
                q.push(parent[curr]);
            }
        }

        level++;
    }
    return {};
}
};