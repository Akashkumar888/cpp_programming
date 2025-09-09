
class Solution {
public:
    ListNode* getMiddle(ListNode* head) {
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
        ListNode* middle = getMiddle(head); 
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        

        ListNode*left = sortList(head);
        ListNode*right = sortList(rightHead);
        
        return mergeTwoList(left, right);  // Corrected function name
    }
};





class Solution {
  public:
    Node* sortList(Node* head) {
        if (!head || !head->next) return head;

        vector<int> vals;
        Node* temp = head;

        while (temp) {
            vals.push_back(temp->data);
            temp = temp->next;
        }

        sort(vals.begin(), vals.end());

        temp = head;
        int i = 0;
        while (temp) {
            temp->data = vals[i++];
            temp = temp->next;
        }

        return head;
    }
};


