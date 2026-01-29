
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
ListNode* reverseList(ListNode*head){
      ListNode*prev=NULL;
      ListNode*curr=head;
      while(curr){
          ListNode*nextNode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextNode;
      }
      return prev;
  }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            slow=slow->next;// it goes 1 step
            fast=fast->next->next;// it goes 2 step
            //if(slow==fast)break;// it is use for cycle detection 
        }
        // thats's slow always at middle 
        // even then right middle
        // odd then middle
        // 2️⃣ Split & reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;                 // 🔥 CRITICAL
        second = reverseList(second);
        // 3️⃣ Merge alternately
        ListNode* first = head;
        while (first && second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};