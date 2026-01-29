
// Solution class with quickSort function
class Solution {
  public:
 struct Node* partition(struct Node* head, struct Node* last){
      struct Node* pos = head;
      struct Node* temp = head->next;
      while(temp!=last){
          if(temp->data < head->data){
              pos=pos->next;
              swap(pos->data,temp->data);
          }
          temp=temp->next;
      }
      swap(pos->data,head->data);
      return pos;
  }
   void Quick_Sort(struct Node* head, struct Node* last){
      if(head == last || head->next == last){
          return;
      }
      struct Node* p = partition(head,last);
      Quick_Sort(head,p);
      Quick_Sort(p->next,last);
  }
    struct Node* quickSort(struct Node* head) {
        Quick_Sort(head,NULL);
        return head;
    }
};


class Solution {
public:
    // Function to get tail of a linked list
    Node* getTail(Node* head) {
        while (head && head->next) head = head->next;
        return head;
    }

    // Partition the list around a pivot
    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = nullptr;
        Node* curr = head;
        Node* tail = pivot;

        // During partition, nodes less than pivot are moved before it
        while (curr != pivot) {
            if (curr->data < pivot->data) {
                if (!(*newHead)) *newHead = curr;
                prev = curr;
                curr = curr->next;
            } else {
                // Move curr node to after tail
                if (prev) prev->next = curr->next;
                Node* tmp = curr->next;
                curr->next = nullptr;
                tail->next = curr;
                tail = curr;
                curr = tmp;
            }
        }

        if (!(*newHead)) *newHead = pivot;

        *newEnd = tail;
        return pivot;
    }

    // Recursive quicksort
    Node* quickSortRecur(Node* head, Node* end) {
        if (!head || head == end) return head;

        Node *newHead = nullptr, *newEnd = nullptr;

        // Partition list, newHead and newEnd will be updated
        Node* pivot = partition(head, end, &newHead, &newEnd);

        // If pivot is smallest, no need to recur left side
        if (newHead != pivot) {
            // Recur for left part before pivot
            Node* tmp = newHead;
            while (tmp->next != pivot) tmp = tmp->next;
            tmp->next = nullptr;

            newHead = quickSortRecur(newHead, tmp);

            // Join pivot after sorted left list
            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        // Recur for right part after pivot
        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    // Main function
    Node* quickSort(Node* head) {
        Node* tail = getTail(head);
        return quickSortRecur(head, tail);
    }
};



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

