
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

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
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int n1=lenOfList(head1);
        int n2=lenOfList(head2);
        Node*temp1=head1;
        Node*temp2=head2;
        int k;
        if(n1>n2){
            k=n1-n2;
            while(k--){
                temp1=temp1->next;
            }
        }
        else if(n1<n2){
            k=n2-n1;
            while(k--){
                temp2=temp2->next;
            }
        }
        while(temp1 && temp2){
            if(temp1==temp2)return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};