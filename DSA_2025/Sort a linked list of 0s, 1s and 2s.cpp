
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // code here
        int zero=0;
        int one=0;
        int two=0;
        Node*temp=head;
        while(temp){
            if(temp->data==0)zero++;
            else if(temp->data==1)one++;
            else if(temp->data==2)two++;
            temp=temp->next;
        }
        Node *dummy=new Node(-1);
        temp=dummy;
        while(zero--){
            Node*NewNode=new Node(0);
            temp->next=NewNode;
            temp=temp->next;
        }
        while(one--){
            Node*NewNode=new Node(1);
            temp->next=NewNode;
            temp=temp->next;
        }
        while(two--){
            Node*NewNode=new Node(2);
            temp->next=NewNode;
            temp=temp->next;
        }
        temp->next=NULL;
        return dummy->next;
    }
  };

  