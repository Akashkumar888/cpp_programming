class SpecialQueue {
public:
queue<int>q;
multiset<int>st;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        st.insert(x);
    }

    void dequeue() {
        // Remove element from the queue
        if(q.empty())return;
        int first=q.front();
        st.erase(st.find(first));
       //This removes only one instance of that value.
        q.pop();
    }

    int getFront() {
        // Get front element
        int first=q.front();
        return first;
    }

    int getMin() {
        // Get minimum element
        return *(st.begin());
    }

    int getMax() {
        // Get maximum element
        // return *prev(st.end());  // or *(--st.end())
        return *(st.rbegin());
    // This correctly gives the last (largest) element in the multiset.
    }
};


class SpecialQueue {
public:
queue<int>q;
deque<int> minDeque; // increasing order
deque<int> maxDeque; // decreasing order
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        // maintain increasing order in minDeque
        while (!minDeque.empty() && minDeque.back() > x) {
            minDeque.pop_back();
        }
        minDeque.push_back(x);

        // maintain decreasing order in maxDeque
        while (!maxDeque.empty() && maxDeque.back() < x) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(x);
    }

    void dequeue() {
        // Remove element from the queue
        if (q.empty()) return;
        int first = q.front();
        q.pop();

        if (!minDeque.empty() && minDeque.front() == first) {
            minDeque.pop_front();
        }
        if (!maxDeque.empty() && maxDeque.front() == first) {
            maxDeque.pop_front();
        }
    }

    int getFront() {
        // Get front element
        int first=q.front();
        return first;
    }

    int getMin() {
        // Get minimum element
        return minDeque.front();
    }

    int getMax() {
        // Get maximum element
        return maxDeque.front();
    }
};
