
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
  int lenOfList(Node*head){
      int len=0;
      Node*temp=head;
      while(temp){
          temp=temp->next;
          len++;
      }
      return len;
  }
    int getKthFromLast(Node* head, int k) {
        // code here
        int n=lenOfList(head);
        Node*temp=head;
        k=n-k;
        if(k<0)return -1;
        while(k--){
            temp=temp->next;
        }
        return temp->data;
    }
};