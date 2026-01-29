// C++ code for the deleting a node from end
// in two traversal

class Node {
public:
Node* deleteNthNodeFromEnd(Node* head, int n) {
    
    Node* fast = head;
    Node* slow = head;

    // Move the fast pointer n nodes
    for (int i = 0; i < n; i++)
        fast = fast->next;

    // If fast becomes NULL, then head 
    // is the nth node from end.
    if (fast == nullptr)
        return head->next;

    // Move both pointers until fast reaches the end
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    slow->next = slow->next->next;
    return head;
}
};
