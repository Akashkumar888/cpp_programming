
#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to rotate the linked list
Node* rotate(Node* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }

    // Step 1: Calculate the length of the linked list
    int length = 1;
    Node* curr = head;
    while (curr->next) {
        length++;
        curr = curr->next;
    }

    // Step 2: Update k to handle cases where k >= length
    k = k % length;
    if (k == 0) return head;

    // Step 3: Find the new head after k rotations
    int stepsToNewHead = length - k;
    Node* left = head;
    while (--stepsToNewHead) {
        left = left->next;
    }

    // Step 4: Perform the rotation
    Node* newHead = left->next;
    left->next = nullptr;
    curr->next = head;

    return newHead;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
Node* createList(const int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Main function to test the rotate function
int main() {
    // Input the linked list elements
    int n, k;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of rotations: ";
    cin >> k;

    // Create the linked list
    Node* head = createList(arr, n);

    // Print the original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Rotate the linked list
    head = rotate(head, k);

    // Print the rotated linked list
    cout << "Rotated Linked List: ";
    printList(head);

    return 0;
}
