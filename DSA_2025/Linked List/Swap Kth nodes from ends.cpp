
class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
       int n = 0;
        Node* temp = head;
        // count length
        while(temp){
            n++;
            temp = temp->next;
        }
        // if k is invalid or both are same node
        if(k > n) return head;
        if(2*k - 1 == n) return head;
        // find kth from start
        Node* start = head;
        for(int i = 1; i < k; i++) start = start->next;
        // find kth from end
        Node* end = head;
        // The kth node from the end is at position (n - k + 1) (1-based index).
        for(int i = 1; i < n-k+1; i++) end = end->next;
        // swap their data
        swap(start->data, end->data);
        // from the beginning and the kth node from the end of the linked list.
        return head;
    }
};
