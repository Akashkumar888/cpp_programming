
/* Linked list Node structure
struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};
*/

// Compare two strings represented as linked lists
class Solution {
  public:
  string solve(Node*head){
      string result;
      Node*temp=head;
      while(temp){
          result.push_back(temp->data);
          temp=temp->next;
      }
      return result;
  }
    int compare(Node *head1, Node *head2) {
        // Code Here
        string first=solve(head1);
        string second=solve(head2);
        if(first>second)return 1;
        else if(first<second)return -1;
        return 0;
    }
};


// ✅ 1️⃣ Using string(1, ch) (BEST & MOST USED)
// char ch = 'A';
// string s(1, ch);
// cout << s;   // A

// ✔️ Clean
// ✔️ Safe
// ✔️ Interview-approved

// ✅ 2️⃣ Using push_back() (When building strings)
// char ch = 'B';
// string s = "";
// s.push_back(ch);
// cout << s;   // B

// ✔️ Best when adding chars one by one
// ✅ 3️⃣ Using += operator
// char ch = 'C';
// string s = "";
// s += ch;
// cout << s;   // C

// ✔️ Short & readable
