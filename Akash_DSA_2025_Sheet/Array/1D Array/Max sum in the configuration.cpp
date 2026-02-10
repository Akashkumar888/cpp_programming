// 🔹 Key Observation (Very Important)
// Let:
// arrSum = sum of all elements of the array
// currVal = value of ∑i×arr[i] for the current rotation
// If we rotate the array clockwise by 1, then:
// nextVal=currVal+arrSum−n×lastElement
// This formula lets us compute the next rotation value in O(1) time.
// 🔹 Why this works
// After rotation:
// Every element shifts right → its index increases by 1
// The last element moves to index 0 → contributes 0
// So total change:
// +arrSum (because all indices increase by 1)
// −n * lastElement (because last element loses its contribution)

// 🔹 Step-by-Step Algorithm
// Compute arrSum
// Compute currVal for the original array
// Set maxVal = currVal
// For each rotation:
// Update currVal using the formula
// Update maxVal
// Return maxVal


class Solution {
public:
//The only operation allowed is to rotate(clockwise or counterclockwise) the array any number of times.
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        
        int arrSum = 0;   // Sum of all elements
        int currVal = 0;  // Value of i*arr[i] for current rotation
        
        // Step 1: Compute arrSum and initial currVal
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += i * arr[i];
        }
        
        int maxVal = currVal;
        
        // Step 2: Compute values for other rotations
        for (int i = 0; i < n; i++) {
            currVal = currVal + arrSum - n * arr[n - 1- i];//The only operation allowed is to rotate(clockwise or counterclockwise) the array any number of times.
            maxVal = max(maxVal, currVal);
        }
        
        return maxVal;
    }
};


// The Line to Remember
// currVal = currVal + arrSum - n * lastElement;
// (where lastElement = arr[n-1-i] for successive clockwise rotations)

// 🧠 The Memory Trick (MOST IMPORTANT)
// Remember just 3 words
// “ALL + SUM, ONE − n×value”
// That’s it.
// 🔹 Visual Intuition (Why the formula exists)
// When you rotate clockwise by 1:
// What happens?
// 1️⃣ Every element shifts right by 1
// Index of every element increases by +1
// So contribution increases by:
// + (sum of all elements) = +arrSum

// 2️⃣ The last element jumps to index 0
// It previously contributed:
// (lastElement × (n−1))
// After rotation, it contributes 0
// Net loss = (n−1)×lastElement + 1×lastElement = n×lastElement
// So total change:
// + arrSum
// − n × lastElement
// Hence:
// nextVal = currVal + arrSum - n * lastElement
// 🧩 Why arr[n-1-i]?
// Because on each clockwise rotation:
// The element that moves to index 0 changes
// First rotation → arr[n-1]
// Second → arr[n-2]
// Third → arr[n-3]
// So:
// lastElement = arr[n-1-i];
// 🧠 How to Memorize (Exam & Interview Friendly)
// ✅ Rule 1: NEVER memorize the full formula
// Memorize this sentence:
// “Rotation increases everything by arrSum, but the last element loses n times.”
// From this sentence, the formula automatically appears.
// ✅ Rule 2: Write it in words first
// Before code, think:
// newValue = oldValue
//          + totalSum
//          − n × (element that moved to index 0)
// Then convert to code.

// ✅ Rule 3: One-line chant (Very effective)
// “Add total sum, subtract n times the dropped element.”
// ✍️ Short Exam Note (You can write this in theory answers)
// On rotating the array clockwise by one position, the contribution of all elements increases by the sum of array elements, while the last element moves to index 0 and loses n times its contribution. Hence:
// nextVal = currVal + arrSum − n × lastElement
// 🧪 Tiny Example (Locks it in memory)
// Array: [3,1,2,8], n=4
// Initial:
// currVal = 0*3 + 1*1 + 2*2 + 3*8 = 29
// arrSum = 14
// lastElement = 8

// Next:
// currVal = 29 + 14 − 4×8
//         = 11
// Your brain now believes the formula, not memorizes it.
// 🧠 Final Memory Hook (Golden)
// Rotation Formula = Old + Total − n×Fallen

// 🔄 Case-wise Answer
// The core idea does NOT change.
// Only which element “falls” and how we update changes.

// 🔹 Case 1: Only CLOCKWISE rotation allowed
// What happens?
// [ a0, a1, a2, ..., a(n−2), a(n−1) ]             ↓
// [ a(n−1), a0, a1, ..., a(n−2) ]
// Observation
// Every element’s index increases by +1
// Last element goes to index 0

// Formula (CLOCKWISE)
// nextVal = currVal + arrSum - n * lastElement
// Where:
// lastElement = arr[n - 1 - i];
// ✅ This is exactly what you already used
// ✔ Works perfectly
// ✔ O(n) total time
// ✔ Most commonly asked version

// 🔹 Case 2: Only ANTI-CLOCKWISE rotation allowed
// What happens?
// [ a0, a1, a2, ..., a(n−1) ]
// [ a1, a2, ..., a(n−1), a0 ]
// Observation
// Every element’s index decreases by 1
// First element moves to index (n−1)
// 🔑 Derivation (Anti-clockwise)
// Change in value:
// All elements shift left → index −1 → −arrSum
// First element goes from index 0 to (n−1) → + n × firstElement
// Formula (ANTI-CLOCKWISE)
// nextVal = currVal - arrSum + n * firstElement
// Where:
// firstElement = arr[i];
// 🧠 MEMORY TRICK (Very Important)
// 🌀 Clockwise
// “Add SUM, subtract n × LAST”
// + arrSum − n × last
// 🔁 Anti-clockwise
// “Subtract SUM, add n × FIRST”
// − arrSum + n × first
// That’s it.
// Two sentences → two formulas → zero confusion.
// 🧩 Final Code Comparison
// 🔹 Clockwise only
// currVal = currVal + arrSum - n * arr[n - 1 - i];
// 🔹 Anti-clockwise only
// currVal = currVal - arrSum + n * arr[i];

