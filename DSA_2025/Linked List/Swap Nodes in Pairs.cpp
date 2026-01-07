

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
          ListNode*temp=head;
         int n=0;
         while(temp){
             n++;
             temp=temp->next;
         }
         int k=2;
         if(n<k || !head) return head;
       ListNode*dummy=new  ListNode(0);
       dummy->next=head;
        ListNode*prev=dummy;
         ListNode*curr=dummy;
          ListNode*nex=dummy;
          while(n>=k){
              curr=prev->next;
              nex=curr->next;
              for(int i=1;i<=k-1;i++){
                   curr->next=nex->next;
                   nex->next=prev->next;
                   prev->next=nex;
                   nex=curr->next;
              }
              prev=curr;
              n-=k;
          }
          return dummy->next;
    }
};

// ✅ Correct Thinking (Simple & Interview-Friendly)
// We swap pairs directly using pointers:
// Before: prev -> a -> b -> next
// After : prev -> b -> a -> next
// No value swap. Only pointer swap.


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;

            // swap
            a->next = b->next;
            b->next = a;
            prev->next = b;

            // move prev
            prev = a;
        }

        return dummy->next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* a = curr;
            ListNode* b = curr->next;

            // swap
            a->next = b->next;
            b->next = a;
            prev->next = b;

            // move pointers
            prev = a;
            curr = a->next;
        }

        return dummy->next;
    }
};
