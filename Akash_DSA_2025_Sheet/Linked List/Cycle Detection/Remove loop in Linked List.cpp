
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // No cycle
        if (fast == NULL || fast->next == NULL) return;

        // Step 2: Find start of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Find last node of loop (node whose next points to 'slow')
        Node* loopStart = slow;
        Node* ptr = loopStart;
        while (ptr->next != loopStart) {
            ptr = ptr->next;
        }

        // Break the loop
        ptr->next = NULL;
    }
};

