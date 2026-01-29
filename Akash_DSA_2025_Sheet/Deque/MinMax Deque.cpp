
class SpecialDeque {
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
};

