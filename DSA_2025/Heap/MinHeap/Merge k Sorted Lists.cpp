
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        typedef pair<int,ListNode*>P;
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            if(temp!=NULL)pq.push({temp->val,temp});
        }
       ListNode*dummy=new ListNode(-1);
       ListNode*prev=dummy;
       while(!pq.empty()){
        int data=pq.top().first;
        ListNode* curr=pq.top().second;
        pq.pop();
        prev->next=curr;
        prev=prev->next;
        ListNode* nextPointer=curr->next;
        if(nextPointer)pq.push({nextPointer->val,nextPointer});
       }
       return dummy->next;;
    }
};