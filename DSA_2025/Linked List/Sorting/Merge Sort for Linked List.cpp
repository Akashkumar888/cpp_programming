
class Solution {
  public:
  // Merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (left==NULL) return right;
        if (right==NULL) return left;

        Node* result = NULL;

        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }
    // Find middle of linked list
    Node* getMiddle(Node* head) {
        if (head==NULL) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* mergeSort(Node* head) {
        // base case: empty or single element
        if (head==NULL || head->next==NULL) return head;

        // find middle
        Node* middle = getMiddle(head);
        Node* rightHead = middle->next;
        middle->next = NULL;  // split the list into two halves

        // recursive merge sort on both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        // merge sorted halves
        return merge(left, right);
    }
};









class Solution {
  public:
  // Merge two sorted linked lists
    Node* mergeTwoList(Node* list1,Node* list2) {
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        while(list1 && list2){
            if(list1->data <= list2->data){
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
    // Find middle of linked list
    Node* getMiddle(Node* head) {
        if (head==NULL) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* mergeSort(Node* head) {
        // base case: empty or single element
        if (head==NULL || head->next==NULL) return head;

        // find middle
        Node* middle = getMiddle(head);
        Node* rightHead = middle->next;
        middle->next = NULL;  // split the list into two halves

        // recursive merge sort on both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        // merge sorted halves
        return mergeTwoList(left, right);
    }
};





