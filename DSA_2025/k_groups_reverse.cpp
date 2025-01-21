
#include <iostream>
using namespace std;

// Definition of a linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list in groups of size k
Node* reverseKGroup(Node* head, int k) {
    if (head == NULL || k == 1) {
        return head;
    }

    Node* curr = head;
    Node* newHead = NULL;
    Node* group_last_node = NULL;

    while (curr) {
        Node* group_first_node = curr;
        Node* prev = NULL;
        Node* nextNode = NULL;
        int count = 0;

        // Reverse k nodes in the current group
        while (curr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // Set the new head of the reversed list
        if (newHead == NULL) {
            newHead = prev;
        }

        // Connect the previous group's last node to the current group's first node
        if (group_last_node != NULL) {
            group_last_node->next = prev;
        }

        // Update the last node of the current group
        group_last_node = group_first_node;

        // If there are fewer than k nodes left, do not reverse them
        if (curr == NULL && count < k) {
            Node* temp = prev;
            prev = NULL;
            while (temp) {
                nextNode = temp->next;
                temp->next = prev;
                prev = temp;
                temp = nextNode;
            }
            if (group_last_node) {
                group_last_node->next = prev;
            }
            break;
        }
    }

    return newHead;
}

// Function to create a linked list from an array
Node* createList(const int arr[], int size) {
    if (size == 0) return NULL;
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
    // Example input
    const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;

    // Create linked list
    Node* head = createList(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "Original List: ";
    printList(head);

    // Reverse in groups of k
    head = reverseKGroup(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    printList(head);

    return 0;
}
