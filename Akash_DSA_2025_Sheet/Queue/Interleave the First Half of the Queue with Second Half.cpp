
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        if(n<=2)return;
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        int mid=n/2;
        int i=0,j=mid;
        while(mid<n){
            q.push(ans[i]);
            i++;
            q.push(ans[mid]);
            mid++;
        }
    }
};


class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        if(n<=2)return;
        int mid=n/2;
        queue<int>firstHalf;
        while(q.size()>mid){
            firstHalf.push(q.front());
            q.pop();
        }
        while(!firstHalf.empty()){
            q.push(firstHalf.front());
            firstHalf.pop();
            q.push(q.front());
            q.pop();
        }
    }
};



class Solution {
public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        if (n <= 1) return;

        queue<int> firstHalf;
        int half = n / 2;

        // Step 1: Move first half into another queue
        for (int i = 0; i < half; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Step 2: Interleave
        while (!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
};



class Solution {
public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        if (n <= 1) return;

        stack<int> st;
        int half = n / 2;

        // Step 1: Push first half into stack
        for (int i = 0; i < half; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue stack elements back
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move first half to back
        for (int i = 0; i < half; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Push first half again into stack
        for (int i = 0; i < half; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 5: Interleave
        while (!st.empty()) {
            q.push(st.top());
            st.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
