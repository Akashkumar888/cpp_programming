
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node*temp=head;
        int cntZero=0,cntOne=0,cntTwo=0;
        while(temp){
            if(temp->data==0)cntZero++;
            else if(temp->data==1)cntOne++;
            else if(temp->data==2)cntTwo++;
            temp=temp->next;
        }
        temp=head;
        while(cntZero--){
            temp->data=0;
            temp=temp->next;
        }
        while(cntOne--){
            temp->data=1;
            temp=temp->next;
        }
        while(cntTwo--){
            temp->data=2;
            temp=temp->next;
        }
        return head;
    }
};

// Time Complexity: O(n) (single traversal)
// Space Complexity: O(1)


// stack-allocated dummies
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if (!head || !head->next) return head;

        Node zeroDummy(-1), oneDummy(-1), twoDummy(-1);
        Node *zero = &zeroDummy, *one = &oneDummy, *two = &twoDummy;

        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect lists together
        zero->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = nullptr;

        return zeroDummy.next;
    }
};



// Using new → also works, but you must remember to delete the dummy nodes to avoid memory leaks.
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroDummy = new Node(-1);
        Node* oneDummy  = new Node(-1);
        Node* twoDummy  = new Node(-1);
        
        Node* zero = zeroDummy;
        Node* one  = oneDummy;
        Node* two  = twoDummy;

        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

                // ... rest same ...
        zero->next = (oneDummy->next) ? oneDummy->next : twoDummy->next;
        one->next = twoDummy->next;
        two->next = nullptr;
        
        // store new head before deleting dummy nodes
        Node* newHead = zeroDummy->next;
        
        // Clean up dummy nodes to avoid memory leak
        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;
        
        return newHead;
    }
};

