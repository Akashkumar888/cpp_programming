
Node* findFirstNode(Node* head) {
    if (head == NULL || head->next == NULL) return NULL; // No cycle possible

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect the loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; // Loop detected
    }

    // Step 2: Check if no loop exists
    if (fast == NULL || fast->next == NULL) return NULL;

    // Step 3: Find the first node of the loop
    slow = head; // Reset slow to head
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // First node of the loop
}
