
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        ListNode*dummy=new ListNode(-1);
        ListNode*prev=dummy;
        int carry=0;
        while(temp1 && temp2){
            int sum=carry+(temp1->val)+(temp2->val);
            ListNode*newNode=new ListNode(sum%10);
            prev->next=newNode;
            carry=sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
            prev=prev->next;
        }
        while(temp1){
            int sum=carry+(temp1->val);
            ListNode*newNode=new ListNode(sum%10);
            prev->next=newNode;
            carry=sum/10;
            temp1=temp1->next;
            prev=prev->next;
        }
        while(temp2){
            int sum=carry+(temp2->val);
            ListNode*newNode=new ListNode(sum%10);
            prev->next=newNode;
            carry=sum/10;
            temp2=temp2->next;
            prev=prev->next;
        }
        if(carry){
            prev->next=new ListNode(carry);
        }
        return dummy->next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*newHead=dummy;
        while(temp1 || temp2 ||carry){
           int sum=carry;
            if(temp1){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            newHead->next=new ListNode(sum%10);
            newHead=newHead->next;
            carry=sum/10;
        }
        return dummy->next;
    }
};