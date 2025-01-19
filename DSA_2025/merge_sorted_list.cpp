
#include <iostream>
using namespace std;

// Definition of a Node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to merge two sorted linked lists
Node* sortedMerge(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* temp = dummy;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 == NULL) temp->next = head2;
    else temp->next = head1;

    return dummy->next;
}

// Helper function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input for first linked list
    int n1;
    cout << "Enter the number of elements in the first linked list: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter the elements of the first linked list (sorted): ";
    for (int i = 0; i < n1; i++) cin >> arr1[i];

    // Input for second linked list
    int n2;
    cout << "Enter the number of elements in the second linked list: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter the elements of the second linked list (sorted): ";
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    // Create linked lists from the input arrays
    Node* head1 = createLinkedList(arr1, n1);
    Node* head2 = createLinkedList(arr2, n2);

    // Merge the two sorted linked lists
    Node* mergedHead = sortedMerge(head1, head2);

    // Print the merged linked list
    cout << "Merged linked list: ";
    printLinkedList(mergedHead);

    return 0;
}
