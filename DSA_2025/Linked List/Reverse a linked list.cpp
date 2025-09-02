class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        if(!head || !head->next)return head;
        Node*prev=NULL;
        Node*curr=head;
        Node*nextNode=NULL;
        while(curr){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
};