class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        if(!head || !head->next)return head;
        Node*prev=NULL;
        Node*curr=head;
        Node*nextNode=NULL;
        while(curr){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ||  head->next==NULL)return head;
       ListNode*last=reverseList(head->next);
       head->next->next=head;
       head->next=NULL;
       return last; 
    }
};


/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        if (head == NULL || head->next == NULL)return head;

        // reverse the rest of linked list and put
        // the first element at the end
        Node *rest = reverseList(head->next);
    
        // Make the current head as last node of
        // remaining linked list
        head->next->next = head;
    
        // Update next of current head to NULL
        head->next = NULL;
    
        return rest;
    }
};

class Node {
    constructor(newData) {
        this.data = newData;
        this.next = null;
    }
}
 
function reverseList(head) {
    let stack = [];
    let temp = head;
 
    // push all nodes into stack
    while (temp !== null) {
        stack.push(temp);
        temp = temp.next;
    }
 
    // make the last node as new head of the linked list
    if (stack.length > 0) {
        head = stack.pop();
        temp = head;
 
        // pop all the nodes and append to the linked list
        while (stack.length > 0) {
            
            temp.next = stack.pop();
 
            temp = temp.next;
        }
 
        temp.next = null;
    }
 
    return head;
}
 
function printList(node) {
    let result = [];
    while (node !== null) {
        result.push(node.data);
        node = node.next;
    }
    console.log(result.join(" -> "));
}
 
// driver code
 
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);
head.next.next.next = new Node(4);
head.next.next.next.next = new Node(5);

head = reverseList(head);
printList(head);