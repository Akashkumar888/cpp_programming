
// 🌳 Binary Indexed Tree (BIT) / Fenwick Tree — Full Explanation
// A Binary Indexed Tree (BIT) is a data structure used to:

// ✔ efficiently update values
// ✔ efficiently query prefix sums
// ✔ both in O(log n) time

// It uses clever bit-manipulation (LSB logic).

// 🚀 WHY do we need BIT?
// Suppose you have an array:

// A = [a1, a2, a3, ..., an]
// You want to support:

// 1. Update a value:
// A[i] += x

// 2. Query prefix sum:
// sum(L..R) = prefix(R) - prefix(L-1)
// Data structure	Update	Query
// Normal array	O(1)	O(n)
// Prefix array	O(n)	O(1)
// BIT	O(log n)	O(log n)

// BIT gives balanced efficiency.
// 🔥 Core BIT Concept: Lowest Set Bit (LSB)

// LSB (i) = i & (-i)
// 🌟 BIT Structure Logic

// BIT array bit[] stores partial sums.
// For index i, BIT stores:

// bit[i] = sum of range [i - LSB(i) + 1 ... i]
// 🧠 How to Query Prefix Sum?

// To compute:
// prefix(i)


// Keep subtracting LSB(i):
// while(i > 0):
//     sum += bit[i]
//     i -= LSB(i)


// Because each bit[i] covers a chunk of the prefix.
// ✔ BIT supports:
// 1. Point Update
// 2. Range Query
// 3. Range Update + Point Query (with tricks)
// 4. Inversion Count
// 5. Coordinate Compression
// 6. 2D BIT (for matrices)

// ⭐ BIT vs Segment Tree
// Feature	BIT	Segment Tree
// Code complexity	Very simple	More complex
// Space	O(n)	O(4n)
// Update	O(log n)	O(log n)
// Query	O(log n)	O(log n)
// Range update	Harder	Easy

// BIT is perfect when:
// Point update + prefix sum query
// Frequency counting
// Inversion count
// Dynamic prefix sums

class BIT {
public:
    vector<int> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.resize(n+1, 0);
    }
    // add value at index i
    void update(int i, int val) {
        while(i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }
    // prefix sum
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    // range sum L..R
    int rangeQuery(int L, int R) {
        return query(R) - query(L - 1);
    }
};

    




// ✔ BIT uses LSB to jump across segments
// ✔ update moves upward (i += LSB(i))
// ✔ query moves downward (i -= LSB(i))
// ✔ Supports prefix sums & point updates in log n
// ✔ Code is short, fast, and used in CP frequently