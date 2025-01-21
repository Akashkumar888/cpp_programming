
#include <iostream>
using namespace std;

// Definition of a linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to add two linked lists
Node* addTwoLists(Node* num1, Node* num2) {
    Node* head1 = reverse(num1);
    Node* head2 = reverse(num2);
    Node* dummy = new Node(-1); // Dummy node for the result list
    Node* current = dummy;
    int carry = 0;

    while (head1 || head2 || carry) {
        int sum = carry;
        if (head1) {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2) {
            sum += head2->data;
            head2 = head2->next;
        }
        current->next = new Node(sum % 10); // Add a new node with the digit
        carry = sum / 10;                   // Update the carry
        current = current->next;
    }

    return reverse(dummy->next); // Reverse the result list before returning
}

// Function to create a linked list from an array
Node* createList(const int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < size; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the implementation
int main() {
    // Example Input: Two linked lists with 6 digits each
    const int arr1[] = {9, 9, 9, 9, 9, 9};
    const int arr2[] = {1};

    // Creating linked lists from arrays
    Node* num1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    Node* num2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));

    cout << "First List: ";
    printList(num1);

    cout << "Second List: ";
    printList(num2);

    // Adding the two linked lists
    Node* result = addTwoLists(num1, num2);

    cout << "Result List: ";
    printList(result);

    return 0;
}
