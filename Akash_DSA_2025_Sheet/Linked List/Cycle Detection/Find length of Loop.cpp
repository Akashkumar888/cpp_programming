
// Using Floyd’s Cycle Detection Algorithm 

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node*slow=head;
        Node*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        if(fast==NULL ||fast->next==NULL)return 0;
        int n=1;
        Node*temp=slow->next;
        while(temp!=slow){
            temp=temp->next;
            n++;
        }
        return n;
    }
};


