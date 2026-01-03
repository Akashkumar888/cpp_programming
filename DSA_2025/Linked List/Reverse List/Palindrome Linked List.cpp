
/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

// ✅ Correct Way (FIXING YOUR CODE, NOT REPLACING IT)
// 🔑 Key Fix
// Find middle
// Reverse only second half
// Compare first half & second half
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
    bool isPalindrome(Node *head) {
        //  code here
        Node*slow=head;
        Node*fast=head;
        while(fast &&fast->next){
            slow=slow->next;// it goes 1 step
            fast=fast->next->next;// it goes 2 step
            //if(slow==fast)break;// it is use for cycle detection 
        }
        // thats's slow always at middle 
        // even then right middle
        // odd then middle
        Node*newHead=reverseList(slow);
        Node*temp1=head;
        Node*temp2=newHead;
        while(temp1 && temp2){
            if(temp1->data!=temp2->data)return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};

// 🔵 LeetCode – Palindrome Linked List Problems
// ✅ Core / Must-Do
// Palindrome Linked List
// 👉 LeetCode #234
// Check whether a singly linked list is a palindrome
// Techniques:
// Slow & fast pointer
// Reverse second half
// O(1) extra space (important!)
// 🔁 Variations & Related Patterns
// Reverse Linked List – #206
// Foundation for palindrome checking
// Middle of the Linked List – #876
// Used to split list into halves
// Reorder List – #143
// Uses middle + reverse logic (same building blocks)
// Maximum Twin Sum of a Linked List – #2130
// Reverse second half + two-pointer comparison
// Remove Nth Node From End – #19
// Uses fast–slow pointer idea
// Linked List Cycle – #141
// Pointer mastery (indirectly useful)
// 🟢 GeeksforGeeks – Palindrome Linked List Problems
// ✅ Core Problems
// Check if Linked List is Palindrome
// GFG classic
// Expected: O(n) time, O(1) space
// Check if Doubly Linked List is Palindrome
// Two-pointer (head & tail)
// 🔁 GFG Variations & Helpers
// Reverse a Linked List
// Find Middle of Linked List
// Compare Two Linked Lists
// Delete Middle of Linked List
// Reverse Linked List in Groups
// (All are often used as sub-steps in palindrome problems)
// 🧠 Common Techniques You MUST Know
// Technique	Used In
// Slow & Fast Pointer	Find middle
// Reverse Linked List	Compare halves
// Two Pointer Compare	Palindrome check
// Stack (extra space)	Alternate solution
// Recursion	Advanced (not optimal)
// 🔥 Best Interview-Ready Approach (Single List)
// Optimal Method (Most Asked):
// Find middle
// Reverse second half
// Compare both halves
// (Optional) Restore list
// ⏱ Time: O(n)
// 🧠 Space: O(1)
// 🎯 Recommended Practice Order
// Reverse Linked List
// Middle of Linked List
// Palindrome Linked List (LC + GFG)
// Maximum Twin Sum
// Reorder List

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // 🔹 Step 1: Find middle (slow & fast)
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 🔹 Step 2: Reverse second half
        Node* second = reverseList(slow);

        // 🔹 Step 3: Compare
        Node* first = head;
        while (second) {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
