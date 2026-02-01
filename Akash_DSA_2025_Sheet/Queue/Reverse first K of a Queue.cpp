
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(q.size()<k)return q;
        stack<int>st;
        while(k--){
            st.push(q.front());
            q.pop();
        }
        int n=q.size();
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        while(n--){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};

class Solution {
  public:
    void reverseK(queue<int>& q, int k){
        if(k==0) return;
        int x = q.front();
        q.pop();
        reverseK(q, k-1);// pahle sabse last me jao using recusrion se call pe call 
        q.push(x);
    }

    queue<int> reverseFirstK(queue<int> q, int k) {
        if(q.size() < k) return q;

        reverseK(q, k);

        int rem = q.size() - k;
        while(rem--){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};


class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(q.size() < k) return q;

        deque<int> dq;
        while(!q.empty()){
            dq.push_back(q.front());
            q.pop();
        }

        reverse(dq.begin(), dq.begin() + k);

        for(int x : dq) q.push(x);
        return q;
    }
};


class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(q.size() < k) return q;

        vector<int> v;
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }

        reverse(v.begin(), v.begin() + k);

        for(int x : v) q.push(x);
        return q;
    }
};

