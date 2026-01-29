
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)return NULL;
        int len=0; // length of ll
        ListNode*temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len==n)return head->next;
        int k=len-n-1;
        ListNode*prev=head;
        ListNode*curr=head->next;
        while(k--){
          prev=curr;
          curr=curr->next;
        }
      prev->next=curr->next;
      //delete node
      delete(curr);
      return head;
    }
};



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
// Follow up: Could you do this in one pass?
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize two pointers, fast and slow
    ListNode* fast = head;
    ListNode* slow = head;

    // Move fast pointer N steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) return head; 
        fast = fast->next;
    }

    // If fast is null, remove the head node
    if (fast == nullptr) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both pointers until fast reaches the end
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the Nth node from the end
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;
    return head;
    }
};