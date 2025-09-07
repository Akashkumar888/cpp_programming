
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        int n=arr.size();
        typedef pair<int,Node*>P;
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<n;i++){
            if(arr[i]!=NULL)pq.push({arr[i]->data,arr[i]});
        }
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        while(!pq.empty()){
            int val1=pq.top().first;
            Node*curr=pq.top().second;
            pq.pop();
            temp->next=curr;
            temp=temp->next;
            if(curr->next) pq.push({curr->next->data,curr->next});
        }
        temp->next=NULL;
        return dummy->next;
    }
};
// 📊 Time Complexity
// Let:
// k = number of linked lists
// N = total number of nodes across all lists
// Pushing initial heads into heap → O(klogk)
// Each insertion into priority queue takes O(logk).
// Processing all nodes → O(Nlogk)
// Each node is pushed once and popped once from heap.
// Each push/pop costs O(logk).
// 🔹 Total = O(Nlogk)(since 𝑁 N ≫ 𝑘
// k, the dominating part is Nlogk).

// 📊 Space Complexity
// Priority queue stores at most 𝑘
// k nodes at a time → O(k).
// Dummy node & pointers → O(1).
// No extra data structures storing all nodes (you reuse given ones).
// 🔹 Total = O(k) auxiliary space.

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        typedef pair<int,Node*>P;
        priority_queue<P,vector<P>,greater<P>>pq;
        int n=arr.size();
        for(Node* &curr:arr){
            if(curr)pq.push({curr->data,curr});
        }
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        while(!pq.empty()){
            int val=pq.top().first;
            Node*curr=pq.top().second;
            pq.pop();
            temp->next=curr;
            temp=temp->next;
            if(curr->next)pq.push({curr->next->data,curr->next});
        }
        temp->next=NULL;
        return dummy->next;
    }
};

