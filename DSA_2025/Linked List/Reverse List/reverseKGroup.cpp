
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        // Step 1: check if we have at least k nodes
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head; // 🚨 not enough nodes → leave as is
            check = check->next;
        }

        // Step 2: reverse k nodes
        int count = 0;
        while (curr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // Step 3: recursive call
        if (nextNode) {
            head->next = reverseKGroup(nextNode, k);
        }

        return prev;
    }
};






class Solution {
public:
    // Helper function: reverse [head, stop) → stop is excluded
    ListNode* reverse(ListNode* head, ListNode* stop) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != stop) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // new head of reversed section
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: check if we have at least k nodes ahead
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head; // less than k → leave as is
            curr = curr->next;
        }

        // Step 2: reverse first k nodes
        ListNode* newHead = reverse(head, curr);

        // Step 3: recursively reverse remaining list
        head->next = reverseKGroup(curr, k);

        return newHead;
    }
};



