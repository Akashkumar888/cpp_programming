
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)return NULL;
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
        if(slow)slow_prev->next=slow->next;
        return head;
    }
};