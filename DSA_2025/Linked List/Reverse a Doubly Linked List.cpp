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



Node* reverse(Node* head) {
    if (!head || !head->next) return head;

    Node* curr = head;
    Node* prev = NULL;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        curr->prev = nextNode; // fix prev pointer too
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Time Complexity:
// Each node is visited once → O(n).

// Space Complexity:
// Uses only a few pointers (prev, curr, nextNode) → O(1).

class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node*temp=head;
        int n=0;
        while(temp->next){
        temp=temp->next;
            n++;
        }
        int k=(n/2) + (n%2);
        Node*tail=head;
        while(k--){
            swap(tail->data,temp->data);
            tail=tail->next;
            temp=temp->prev;
        }
        return head;
    }
};

