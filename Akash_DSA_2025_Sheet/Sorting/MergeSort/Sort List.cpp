
class Solution {
public:
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // find left middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
                
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1==NULL)temp->next=list2;
        else temp->next=list1;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* first = head;
        ListNode* middle = findmiddle(head); 
        ListNode* last = middle->next;
        middle->next = NULL;
        
        first = sortList(first);
        last = sortList(last);
        
        return mergeTwoList(first, last);  // Corrected function name
    }
};
