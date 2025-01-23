#include <iostream>
using namespace std;

// Definition for a Node
struct Node {
    int data;
    Node* next;
    Node* random;
    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

// Function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node data: " << temp->data;
        if (temp->random) {
            cout << ", Random points to: " << temp->random->data;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

// Function to clone the linked list
Node* cloneLinkedList(Node* head) {
    if (head == NULL) return head;

    Node* curr = head;

    // Step 1: Interleave new nodes with original nodes
    while (curr) {
        Node* nextNode = curr->next;
        Node* temp = new Node(curr->data);
        curr->next = temp;
        temp->next = nextNode;
        curr = nextNode;
    }

    // Step 2: Assign random pointers to the cloned nodes
    curr = head;
    while (curr) {
        if (curr->random == NULL) {
            curr->next->random = NULL;
        } else {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate the two lists
    curr = head;
    Node* newHead = curr->next;
    Node* newNode = curr->next;

    while (curr) {
        curr->next = curr->next->next;
        if (newNode->next) newNode->next = newNode->next->next;
        curr = curr->next;
        newNode = newNode->next;
    }

    return newHead;
}

// Function to create a linked list from input
Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;

        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to set random pointers for the linked list
void setRandomPointers(Node* head, int n) {
    Node* nodes[n];
    Node* temp = head;
    int i = 0;

    // Store all nodes in an array
    while (temp) {
        nodes[i++] = temp;
        temp = temp->next;
    }

    // Assign random pointers
    for (int i = 0; i < n; i++) {
        int randomIndex;
        cout << "Enter random pointer index for node " << i + 1 << " (0-based, -1 for NULL): ";
        cin >> randomIndex;

        if (randomIndex == -1) {
            nodes[i]->random = NULL;
        } else {
            nodes[i]->random = nodes[randomIndex];
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node* head = createLinkedList(n);

    setRandomPointers(head, n);

    cout << "\nOriginal Linked List:\n";
    printList(head);

    Node* clonedHead = cloneLinkedList(head);

    cout << "\nCloned Linked List:\n";
    printList(clonedHead);

    return 0;
}
