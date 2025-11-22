
/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
  Node* findmiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next; // find left middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* mergeTwoList(Node* list1, Node* list2) {
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        while(list1 && list2){
            if(list1->data <= list2->data){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
                
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1==NULL)temp->next=list2;
        else temp->next=list1;
        return dummy->next;
    }
    Node* insertionSort(struct Node* head_ref) {
        // code here
        if (head_ref == NULL || head_ref->next == NULL) return head_ref;
        Node* first = head_ref;
        Node* middle = findmiddle(head_ref); 
        Node* last = middle->next;
        middle->next = NULL;
        
        first = insertionSort(first);
        last = insertionSort(last);
        
        return mergeTwoList(first, last);  // Corrected function name
    }
};

class Solution {
public:
    Node* insertionSort(Node* head) {
        if (!head || !head->next) return head;

        Node* dummy = new Node(-1);  // new sorted list head
        Node* current = head;

        while (current) {
            Node* nextNode = current->next;

            // find position to insert current inside sorted list
            Node* prev = dummy;
            Node* temp = dummy->next;

            while (temp && temp->data < current->data) {
                prev = temp;
                temp = temp->next;
            }

            // insert current between prev and temp
            current->next = temp;
            prev->next = current;

            current = nextNode;
        }

        return dummy->next;
    }
};
