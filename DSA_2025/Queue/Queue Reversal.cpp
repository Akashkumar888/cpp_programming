
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        vector<int>que;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            que.push_back(val);
        }
        for(int i=que.size()-1;i>=0;i--){
            q.push(que[i]);
        }
    }
};

// Time: O(n) (each element is popped and pushed once).
// Space: O(n) recursion stack (but no extra data structure like vector).

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        // base case
        if (q.empty()) return;

        // take out the front element
        int val = q.front();
        q.pop();

        // recursive call on remaining queue
        reverseQueue(q);

        // insert the element at the back after recursion finishes
        q.push(val);
    }
};


class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        deque<int>d;
        // Transfer to deque
        while(!q.empty()){
            d.push_front(q.front());
            q.pop();
        }
        // Reverse using deque (O(1) extra space)
        while(!d.empty()){
            q.push(d.front());
            d.pop_front();
        }
    }
};

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        deque<int>d;
        // Transfer to deque
        while(!q.empty()){
            d.push_back(q.front());
            q.pop();
        }
        // Reverse using deque (O(1) extra space)
        while(!d.empty()){
            q.push(d.back());
            d.pop_back();
        }
    }
};
