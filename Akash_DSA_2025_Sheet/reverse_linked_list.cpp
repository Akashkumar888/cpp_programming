
#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;  
    Node* curr = head;  
    Node* nextnode = NULL;  
    
    while (curr) {  
        nextnode = curr->next;  // Store the next node  
        curr->next = prev;      // Reverse the pointer  
        prev = curr;            // Move prev forward  
        curr = nextnode;        // Move curr forward  
    }  
    
    return prev;  // New head of the reversed list  
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function with input and output
int main() {
    // Input: Creating a linked list 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
