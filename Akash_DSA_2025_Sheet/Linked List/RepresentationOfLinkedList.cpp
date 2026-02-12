
// list<pair<int,int>> adj[n+1];
// Represents a weighted graph using doubly linked lists
// Each adj[u] stores (v, weight)
// Nodes stored non-contiguously
// Pointer overhead (prev, next)
// Slower traversal → not preferred for graphs


// list<int> ll;
// Represents a doubly linked list of integers
// NOT a graph
// Used for:
// - Linked list operations
// - LRU Cache
// - Frequent insert/delete in middle
// - Stable iterators


// 2️⃣ list<pair<int,int>> adj[n+1];
// 🔹 What it means
// adj is an array of doubly linked lists
// Each node is stored separately in memory
// 🔹 Structure
// adj[u] = (v1, wt1) → (v2, wt2) → (v3, wt3)
// 🔹 Properties
// Non-contiguous memory
// Pointer overhead
// Slower traversal

// 3️⃣ list<int> ll;
// 🔹 What it means
// A single doubly linked list
// Stores only integers
// NOT a graph by itself
// 🔹 Example
// list<int> ll;
// ll.push_back(10);
// ll.push_back(20);


// Used for:
// Queue
// Deque
// LRU Cache
// When frequent insert/delete in middle
