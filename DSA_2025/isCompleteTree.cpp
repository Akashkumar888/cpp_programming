
class Solution {
  public:
  bool bfs(Node*root){
      queue<Node*>q;
      q.push(root);
      bool foundnull=false;
      while(!q.empty()){
              Node* curr=q.front();
              q.pop();
              if(curr->left)
              {
                if(foundnull)return false;
                if(curr->data<curr->left->data)return false;
                q.push(curr->left);
              }
              else foundnull=true;
              
              if(curr->right){
                  if(foundnull)return false;
                if(curr->data<curr->right->data)return false;
                q.push(curr->right);
              }
              else foundnull=true;
      }
    return true;  
  }
    bool isHeap(Node* tree) {
        // code here
        return bfs(tree);
    }
  };