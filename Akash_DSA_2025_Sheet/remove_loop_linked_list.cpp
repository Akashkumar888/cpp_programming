void removeLoop(Node* head) {
    if (!head || !head->next) return; // No loop if the list is empty or has only one node

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect the loop using Floyd's algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; // Loop detected
    }

    // If no loop is detected, return
    if (!fast || !fast->next) return;

    // Step 2: Remove the loop
    slow = head;

    // Case 1: If the loop starts at the head
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL; // Remove the loop
        return;
    }

    // Case 2: General case, find the loop's starting point
    Node* prev = NULL;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Break the loop
    if (prev) prev->next = NULL;
}
