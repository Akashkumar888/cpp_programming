
// If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

class Solution {
  public:
  // Helper function to reverse nodes from head until stop (excluded)
  Node* reverse(Node*head,Node*stop){
      Node*prev=NULL;
      Node*curr=head;
      while(curr!=stop){
          Node*nextNode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextNode;
      }
      return prev;
  }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head || k<=1)return head;
        Node*curr=head;
        int count=0;
        while(curr && count<k){
            count++;
            curr=curr->next;
        }
        // DO NOT return when count < k – we'll reverse whatever remains
        // Reverse first k nodes
        Node*newHead=reverse(head,curr);
        // Recursively reverse next groups
        head->next=reverseKGroup(curr,k);
        return newHead;
    }
};


class Solution {
public:
// Helper function to reverse nodes from head until stop (excluded)
  ListNode* reverse(ListNode*head,ListNode*stop){
      ListNode*prev=NULL;
      ListNode*curr=head;
      while(curr!=stop){
          ListNode*nextNode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextNode;
      }
      return prev;
  }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*curr=head;
        int count=0;
        while(curr && count<k){
            count++;
            curr=curr->next;
        }
        // Less than k nodes left, return as is
        if(count<k)return head;
        // Reverse first k nodes
        ListNode*newHead=reverse(head,curr);
        // Recursively reverse next groups
        head->next=reverseKGroup(curr,k);
        return newHead;
    }
};
