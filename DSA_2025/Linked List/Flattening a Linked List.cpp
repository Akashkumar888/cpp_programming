
/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  Node*mergeTwosortedlist(Node*l1 ,Node* l2){
        if(!l1)return l2;
        if(!l2)return l1;
        Node*result;
        if(l1->data<l2->data){
             result=l1;
             result->bottom=mergeTwosortedlist(result->bottom,l2);
        }
        else{
            result=l2;
            result->bottom=mergeTwosortedlist(l1,result->bottom);
        }
        return result;
    }
    Node *flatten(Node *root) {
        // code here
        if(root==NULL)return NULL;
        Node *head2 =flatten(root->next);
        return mergeTwosortedlist(root,head2);
    }
};

// ⏱️ Time Complexity
// O(m * n²)

// Which matches:
// O(n * n * m)
// 🧠 Space Complexity
// Recursive stack depth = O(n)


// 3️⃣ Better Approach 🚀 (Using Min Heap)
// Instead of merging lists one by one, merge all lists simultaneously using a min-heap (priority queue).
// Steps
// Push the head of every vertical list into a min heap
// Extract the smallest node
// Push its bottom into heap
// Repeat until heap is empty

// 4️⃣ Optimized Complexity ✅
// ⏱️ Time Complexity
// O(n*m * log n)

// Much better than O(n²*m)
// 🧠 Space Complexity
// O(n)
// (for heap)

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* flatten(Node* root) {
        if(!root) return NULL;

        typedef pair<int, Node*> P;
        priority_queue<P, vector<P>, greater<P>> pq;

        // Push all vertical list heads
        for(Node* curr = root; curr!=NULL; curr = curr->next) {
            pq.push({curr->data, curr});
        }

        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while(!pq.empty()) {
            int val = pq.top().first;
            Node* curr = pq.top().second;
            pq.pop();

            // attach using bottom pointer
            temp->bottom = curr;
            temp = temp->bottom;

            if(curr->bottom)pq.push({curr->bottom->data, curr->bottom});
        }

        // Important cleanup
        temp->bottom = NULL;
        return dummy->bottom;
    }
};