
/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverseList(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        while(curr){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    Node *compute(Node *head) {
        head=reverseList(head);
        int maxi=head->data;
        Node* curr=head;
        while(curr && curr->next){
            if(curr->next->data < maxi){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
                maxi=max(maxi,curr->data);
            }
        }
        return reverseList(head);
    }
};



/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverseList(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        while(curr){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    Node *compute(Node *head) {
        head=reverseList(head);
        Node* temp=head;
        while(temp->next){
            if(temp->next->data < temp->data){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        head=reverseList(head);
        return head;
    }
};