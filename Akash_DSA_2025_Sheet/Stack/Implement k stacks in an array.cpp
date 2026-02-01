
class kStacks {
public:
    int n, k;
    vector<int> arr;      // stores actual elements
    vector<int> top;      // top index of each stack
    vector<int> next;     // next free / next element
    int freeSpot;         // starting index of free list

    kStacks(int n, int k) {
        this->n = n;
        this->k = k;

        arr.resize(n);
        top.resize(k, -1);
        next.resize(n);

        // initialize free list
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    // push x into stack i (0-based index)
    void push(int x, int i) {
        if (isFull()) return;

        int index = freeSpot;       // get free index
        freeSpot = next[index];     // update freeSpot

        arr[index] = x;
        next[index] = top[i];       // link to previous top
        top[i] = index;             // update top
    }

    // pop from stack i
    int pop(int i) {
        if (isEmpty(i)) return -1;

        int index = top[i];
        top[i] = next[index];       // move top

        next[index] = freeSpot;     // add index back to free list
        freeSpot = index;

        return arr[index];
    }

    bool isEmpty(int i) {
        return top[i] == -1;
    }

    bool isFull() {
        return freeSpot == -1;
    }
};


// ✅ Approach: Implement K Stacks in a Single Array
// 🔹 Problem

// Implement k stacks using one array such that push and pop work in O(1) time.

// 🔹 Data Structures Used

// arr[n]
// Stores actual elements of all stacks.

// top[k]
// top[i] stores the index of the top element of stack i.

// next[n]

// Acts as next pointer for stack elements

// Also maintains a free list of available indexes

// freeTop
// Points to the first free index in arr.

// 🔹 Initialization

// All stacks are initially empty → top[i] = -1

// Free list is created using next[]

// freeTop = 0 (first free index)

// 🔹 Push Operation (push(x, i))

// Check if freeTop == -1 → array full

// Take free index from freeTop

// Update freeTop to next free index

// Store element in arr[index]

// Link new element to stack i

// Update top[i]

// ⏱ Time Complexity: O(1)

// 🔹 Pop Operation (pop(i))

// Check if top[i] == -1 → stack empty

// Get top index of stack i

// Move top[i] to next element

// Add freed index back to free list

// Return popped element

// ⏱ Time Complexity: O(1)

// 🔹 Why this works?

// Efficient space sharing between stacks

// No shifting of elements

// Constant time push & pop

// 🔹 Complexity

// Time: O(1) per operation

// Space: O(n + k)

class kStacks {
public:
    vector<int>arr;     // main array
    vector<int> top;     // top of each stack
    vector<int>next;    // next free or next element
    int freeTop;  // beginning of free list
    int n, k;

    kStacks(int n, int k) {
        this->n = n;
        this->k = k;

        arr.resize(n);
        top.resize(k,-1);
        next.resize(n);
        
        // initialize free list
        for (int i=0;i<n-1;i++)next[i]=i+1;
        
        next[n - 1] = -1;

        freeTop = 0;
    }

    // push x into stack i (0-based index)
    bool push(int x, int i) {
        if (freeTop == -1) return false; // array full

        int index = freeTop;       // free index
        freeTop = next[index];     // update freeTop

        arr[index] = x;
        next[index] = top[i];
        top[i] = index;

        return true;
    }

    // pop from stack i
    int pop(int i) {
        if (top[i] == -1) return -1; // stack empty

        int index = top[i];
        top[i] = next[index];

        next[index] = freeTop;
        freeTop = index;

        return arr[index];
    }
};
