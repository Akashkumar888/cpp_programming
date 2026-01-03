
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
// The number of nodes in the list is an even integer in the range [2, 105].
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
    int pairSum(ListNode* head) {
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
        ListNode* second = slow;
        second = reverseList(second);
        int maxSum=INT_MIN;
        ListNode* first = head;
        while(first && second){
            int sum=first->val + second->val;
            maxSum=max(maxSum,sum);
            first=first->next;
            second=second->next;
        }
        return maxSum;
    }
};