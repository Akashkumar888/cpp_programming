// 2385. Amount of Time for Binary Tree to Be Infected 

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
// minimum time required to burn the entire tree -> use bfs 
// every graph is a tree but every tree is not graph
// tree is directed graph from parent to child
// here we need to undirected graph that's why convert tree to undirected graph 
void buildGraph(Node*root,unordered_map<int,vector<int>>&graph){
    if(root==NULL)return ;
    if(root->left){
       graph[root->data].push_back(root->left->data);
       graph[root->left->data].push_back(root->data);
       buildGraph(root->left,graph); 
    }
    if(root->right){
       graph[root->data].push_back(root->right->data);
       graph[root->right->data].push_back(root->data);
       buildGraph(root->right,graph);
    }
}
int bfs(unordered_map<int,vector<int>>&graph,int target){
    queue<int>q;
    unordered_set<int>visited;
    int minTime = -1; // start with -1 because first level (target) is 0 seconds
    q.push(target);
    visited.insert(target);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
        int curr=q.front();
        q.pop();
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
    int minTime(Node* root, int target) {
        // code here
        unordered_map<int,vector<int>>graph;
        buildGraph(root,graph);
        return bfs(graph,target);
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
int bfs(unordered_map<int,vector<int>>&graph,int target){
    queue<int>q;
    unordered_set<int>visited;
    int minTime = -1; // start with -1 because first level (target) is 0 seconds
    q.push(target);
    visited.insert(target);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
        int curr=q.front();
        q.pop();
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;
        buildGraph(root,graph);
        return bfs(graph,start);
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// undirected graph 
void makegraph(TreeNode*root,unordered_map<int,vector<int>>&adj){
    if(root==NULL)return;
    if(root->left){
        adj[root->left->val].push_back(root->val);
        adj[root->val].push_back(root->left->val);
        makegraph(root->left,adj);
    }
    if(root->right){
        adj[root->right->val].push_back(root->val);
        adj[root->val].push_back(root->right->val);
        makegraph(root->right,adj);
    }
}
    int amountOfTime(TreeNode* root, int start) {
        int time=0;
        // int ka map yaha start int ka diya hai 
        unordered_map<int,vector<int>>adj;
        unordered_set<int>visited;
        makegraph(root,adj);
        queue<int>q;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int curr=q.front();
                q.pop();
                for(auto &ngbr:adj[curr]){
                    if(visited.find(ngbr)==visited.end()){
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};
