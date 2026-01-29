
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node*curr=head;
        Node*prev=NULL;
        Node *last=head;
        while(last->next!=head){
            if(curr->data< data){
            prev=curr;
            curr=curr->next;
            }
            last=last->next;
        }
        if(curr->data< data){
            prev=curr;
            curr=curr->next;
            }
        Node*dummy=new Node(data);
        Node* newHead=dummy;
        if(prev==NULL){
            dummy->next=curr;
            last->next=newHead;
            return newHead;
        }
        prev->next=dummy;
        prev=dummy;
        prev->next=curr;
        return head;
    }
};


class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
         Node* newNode = new Node(data);
         
        Node* curr = head;

        // Case 2: Insert before head (smallest element)
        if (data <= head->data) {
            // Find the last node
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            return newNode;  // New node is the new head
        }

        // Case 3: Insert in between or at end
        Node* temp = head;
        while (temp->next != head && temp->next->data < data) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        return head;  // Head remains the same
    }
};