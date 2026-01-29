#include <iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list node
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        // Reverse both input lists
        Node* head1 = reverse(num1);
        Node* head2 = reverse(num2);

        int carry = 0;
        Node* dummy = new Node(-1); // Dummy node
        Node* newHead = dummy;

        // Add corresponding digits of the two lists
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

            // Create a new node with the current digit
            newHead->next = new Node(sum % 10);
            newHead = newHead->next;
            carry = sum / 10;
        }

        // Reverse the result list and remove leading zeros
        Node* oldHead = reverse(dummy->next);
        delete dummy; // Clean up the dummy node
        while (oldHead->data == 0 && oldHead->next) {
            oldHead = oldHead->next;
        }
        return oldHead;
    }
};

// Utility function to create a linked list from a vector of integers
Node* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return NULL;
    Node* head = new Node(nums[0]);
    Node* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new Node(nums[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print a linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Example input lists
    vector<int> list1 = {2, 4, 3}; // Represents 342
    vector<int> list2 = {5, 6, 4}; // Represents 465

    // Create linked lists from input vectors
    Node* num1 = createLinkedList(list1);
    Node* num2 = createLinkedList(list2);

    cout << "Input List 1: ";
    printLinkedList(num1);

    cout << "Input List 2: ";
    printLinkedList(num2);

    // Add the two lists
    Solution solution;
    Node* result = solution.addTwoLists(num1, num2);

    // Print the result
    cout << "Resultant List: ";
    printLinkedList(result);

    return 0;
}
