
class MyCircularQueue {
public:
    int frontIdx;     // points to front element
    int rearIdx;      // points to next insertion position
    int size;         // current number of elements
    int capacity;     // maximum capacity
    vector<int> data;

    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        frontIdx = 0;
        rearIdx = 0;
        size = 0;
    }

    // Insert element at rear
    bool enQueue(int value) {
        if (size == capacity) return false; // queue full

        data[rearIdx] = value;
        rearIdx = (rearIdx + 1) % capacity;
        size++;
        return true;
    }

    // Remove element from front
    bool deQueue() {
        if (size == 0) return false; // queue empty

        frontIdx = (frontIdx + 1) % capacity;
        size--;
        return true;
    }

    // Get front element
    int Front() {
        if (size == 0) return -1;
        return data[frontIdx];
    }

    // Get last element
    int Rear() {
        if (size == 0) return -1;
        return data[(rearIdx - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */