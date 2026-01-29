
class Solution {
  public:
//  choosing the one that gives minimum absolute difference from target.
// that's why we use max-heap
  typedef pair<int,int>P;
  void inorderTraversal(Node*root,int tr,int k,priority_queue<P>&pq){
      if(root==NULL)return;
      inorderTraversal(root->left,tr,k,pq);
      int originalValue=root->data;
      pq.push({abs(tr-originalValue),originalValue});
      if(pq.size()>k)pq.pop();
      inorderTraversal(root->right,tr,k,pq);
  }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        priority_queue<P>pq;
        inorderTraversal(root,target,k,pq);
        vector<int>result;
        while(!pq.empty()){
            int val=pq.top().second;
            pq.pop();
            result.push_back(val);
        }
        return result;
    }
};

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
//  choosing the one that gives minimum absolute difference from target.
// that's why we use max-heap
  typedef pair<int,int>P;
  void MorrisInorderTraversal(Node*root,int tr,int k,priority_queue<P>&pq){
      if(root==NULL)return;
      Node*curr=root;
      while(curr){
          if(curr->left==NULL){
          int originalValue=curr->data;
          pq.push({abs(tr-originalValue),originalValue});
          if(pq.size()>k)pq.pop();
          curr=curr->right;      
          }
          else{
              Node*pre=curr->left;
              while(pre->right && pre->right!=curr){
                  pre=pre->right;
              }
              if(pre->right==NULL){ // pre jb null ho 
                  pre->right=curr;  // pre->right me curr dal do
                  curr=curr->left;  // curr ko curr le left me le jao
              }
              else{             // pre jb null na ho 
                  pre->right=NULL;// pre->right me null dal do
                  int originalValue=curr->data;
                  pq.push({abs(tr-originalValue),originalValue});
                  if(pq.size()>k)pq.pop();
                  curr=curr->right;// curr ko curr le right me le jao
              }
          }
      }
  }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        priority_queue<P>pq;
        MorrisInorderTraversal(root,target,k,pq);
        vector<int>result;
        while(!pq.empty()){
            int val=pq.top().second;
            pq.pop();
            result.push_back(val);
        }
        return result;
    }
};


class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> arr;
        inorder(root, arr); // BST → sorted array

        // Binary search to find closest element to target
        int n = arr.size();
        int pos = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        int left = pos - 1, right = pos;
        vector<int> result;

        // pick k closest elements
        while (k-- > 0) {
            if (left < 0) result.push_back(arr[right++]);
            else if (right >= n) result.push_back(arr[left--]);
            else {
                if (abs(arr[left] - target) <= abs(arr[right] - target))
                    result.push_back(arr[left--]);
                else
                    result.push_back(arr[right++]);
            }
        }
        return result;
    }
};