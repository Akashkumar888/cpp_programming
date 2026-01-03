

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

