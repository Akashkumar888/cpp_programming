

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {          // store node before slow
            slow = slow->next;          // slow moves 1 step
            fast = fast->next->next;    // fast moves 2 steps
        }
        return slow;
    }
};


// 1 Correct code for finding LEFT middle
ListNode* slow = head;
ListNode* fast = head->next;
ListNode* slow_prev = NULL;

while (fast && fast->next) {
    slow_prev = slow;
    slow = slow->next;
    fast = fast->next->next;
}

// ✅ 2. Finding RIGHT Middle (your current approach)
ListNode* slow = head;
ListNode* fast = head;
ListNode* slow_prev = NULL;

// For even length, slow will stop at the RIGHT middle.
// Example: 1 → 2 → 3 → 4
// slow → 3 (right middle)
while (fast && fast->next) {
    slow_prev = slow;           // store node before slow
    slow = slow->next;          // slow moves 1 step
    fast = fast->next->next;    // fast moves 2 steps
}