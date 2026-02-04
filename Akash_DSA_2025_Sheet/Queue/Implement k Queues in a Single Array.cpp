class kQueues {
  public:
    int n, k;
    vector<int> arr;      // stores actual elements
    vector<int> front;    // front of each queue
    vector<int> rear;     // rear of each queue
    vector<int> next;     // next free / next element
    int freeSpot;         // starting index of free list

    // Constructor
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr.resize(n);
        front.resize(k, -1);
        rear.resize(k, -1);
        next.resize(n);

        // initialize free list
        for (int i = 0; i < n - 1; i++)next[i] = i + 1;
        
        next[n - 1] = -1;

        freeSpot = 0;
    }

    // enqueue element x into queue i
    void enqueue(int x, int i) {
        if (isFull()) return;

        int index = freeSpot;           // get free index
        freeSpot = next[index];         // update freeSpot

        // first element in queue i
        if (front[i] == -1) {
            front[i] = index;
        } 
        else {
            next[rear[i]] = index;
        }

        next[index] = -1;
        rear[i] = index;
        arr[index] = x;
    }

    // dequeue element from queue i
    int dequeue(int i) {
        if (isEmpty(i)) return -1;

        int index = front[i];
        front[i] = next[index];

        // if queue becomes empty
        if (front[i] == -1) rear[i] = -1;

        // add index back to free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // check if queue i is empty
    bool isEmpty(int i) {
        return front[i] == -1;
    }

    // check if array is full
    bool isFull() {
        return freeSpot == -1;
    }
};
