#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to detect a loop in a linked list
bool detectLoop(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true; // Loop detected
    }

    return false; // No loop
}

// Helper function to create a linked list with a loop
Node* createLinkedListWithLoop() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creating a loop

    return head;
}

// Main function
int main() {
    Node* head = createLinkedListWithLoop();

    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop in the linked list." << endl;
    }

    return 0;
}
