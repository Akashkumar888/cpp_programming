
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node*slow=head;
        Node*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        if(fast==NULL || fast->next==NULL)return 0;
        Node*temp=slow->next;
        int length=1;
        while(temp!=slow){
            length++;
            temp=temp->next;
        }
        return length;
    }
  };
  