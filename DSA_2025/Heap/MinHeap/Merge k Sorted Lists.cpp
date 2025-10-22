
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int,ListNode*>P;
        priority_queue<P,vector<P>,greater<P>>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)pq.push({lists[i]->val,lists[i]});
        }
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        while(!pq.empty()){
            int val=pq.top().first;
            ListNode*curr=pq.top().second;
            pq.pop();
            temp->next=curr;
            temp=temp->next;
            if(curr->next)pq.push({curr->next->val,curr->next});
        }
        temp->next=NULL;
        return dummy->next;
    }
};
