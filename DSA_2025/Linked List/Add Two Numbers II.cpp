
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*first=reverseList(l1);
        ListNode*second=reverseList(l2);
        ListNode*temp1=first;
        ListNode*temp2=second;
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
        ListNode* result = reverseList(dummy->next);
        //There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
          // 🔥 REMOVE LEADING ZEROS
          while (result && result->val == 0) {
              result = result->next;
          }
          // edge case: result is all zeros
          if (result == NULL) {
              return new ListNode(0);
          }
          return result;
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
ListNode*reverse(ListNode*head){
      ListNode*prev=NULL;
      ListNode*curr=head;
      ListNode*nextNode=NULL;
      while(curr){
          nextNode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextNode;
      }
      return prev;
  }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head1=reverse(l1);
        ListNode*head2=reverse(l2);
        ListNode*temp1=head1;
        ListNode*temp2=head2;
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
    ListNode*oldHead=reverse(dummy->next);
    delete dummy;
    while(oldHead->val==0 && oldHead->next)oldHead=oldHead->next;
    return oldHead;
    }
};


/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  Node* reverseList(Node*head){
      Node*prev=NULL;
      Node*curr=head;
      while(curr){
          Node*nextNode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextNode;
      }
      return prev;
  }
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node*first=reverseList(head1);
        Node*second=reverseList(head2);
        Node*temp1=first;
        Node*temp2=second;
        Node*dummy=new Node(-1);
        Node*prev=dummy;
        int carry=0;
        while(temp1 && temp2){
            int sum=carry+(temp1->data)+(temp2->data);
            Node*newNode=new Node(sum%10);
            prev->next=newNode;
            carry=sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
            prev=prev->next;
        }
        while(temp1){
            int sum=carry+(temp1->data);
            Node*newNode=new Node(sum%10);
            prev->next=newNode;
            carry=sum/10;
            temp1=temp1->next;
            prev=prev->next;
        }
        while(temp2){
            int sum=carry+(temp2->data);
            Node*newNode=new Node(sum%10);
            prev->next=newNode;
            carry=sum/10;
            temp2=temp2->next;
            prev=prev->next;
        }
        if(carry){
            prev->next=new Node(carry);
        }
        Node* result = reverseList(dummy->next);
        //There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
          // 🔥 REMOVE LEADING ZEROS
          while (result && result->data == 0) {
              result = result->next;
          }
    
          // edge case: result is all zeros
          if (result == NULL) {
              return new Node(0);
          }
    
          return result;
    }
};
