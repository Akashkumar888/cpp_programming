
/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
public:
    // Partition function
    Node* partition(Node* head, Node* last) {
        Node* pivot = head;     // choose head as pivot
        Node* i = head;         // keeps track of smaller element boundary
        Node* j = head->next;   // scanning pointer

        while (j != last) {
            if (j->data < pivot->data) {
                i = i->next;
                swap(i->data, j->data);
            }
            j = j->next;
        }
        swap(i->data, pivot->data);
        return i;
    }

    // Recursive QuickSort
    void quickSortUtil(Node* head, Node* last) {
        if (!head || head == last || head->next == last) return;

        Node* p = partition(head, last);
        quickSortUtil(head, p);
        quickSortUtil(p->next, last);
    }

    // Main function
    Node* quickSort(Node* head) {
        quickSortUtil(head, nullptr);
        return head;
    }
};