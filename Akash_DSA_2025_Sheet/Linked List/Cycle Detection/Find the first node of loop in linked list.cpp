
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        if(head==NULL ||head->next==NULL)return NULL;
        Node*slow=head;
        Node*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        if(fast==NULL || fast->next==NULL)return NULL;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};



class Solution {
  public:
    int cycleStart(Node* head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // No cycle
        if (fast == NULL || fast->next == NULL) return -1;

        // Step 2: Find the start of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow (or fast) is at the start of the loop
        return slow->data;
    }
};