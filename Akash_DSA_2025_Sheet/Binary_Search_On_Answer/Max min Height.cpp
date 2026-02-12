// 🧠 Step 1: How to Identify Topic?
// Whenever you see:
// “Maximize the minimum”
// “Minimize the maximum”
// “Given k operations”
// “Check if possible”
// 👉 Think Binary Search on Answer
// Because:
// If we can achieve height = H
// Then we can also achieve any height < H.
// That monotonic property ⇒ Binary Search works.

// 🧠 Step 2: Decide Search Range (l and r)
// Minimum height we can achieve:
// l = min(arr)
// Maximum possible height:
// Worst case: all k days water same flower
// r = min(arr) + k
// Why not max element?
// Because minimum height cannot exceed min + k.

// 🧠 Step 3: isPossible(targetHeight)
// We check:
// Can we make all flowers ≥ target using ≤ k watering days?
// Key idea:
// If arr[i] < target
// We must increase it.
// But watering affects w continuous flowers.
// So we simulate efficiently using a difference array.
// 🔥 Core Trick (Very Important)
// We maintain:
// extraWater[i] → how much added so far
// Sliding window effect
// Instead of updating w elements every time
// We use prefix sum technique.


// 🧠 PART 1 — Understanding Difference Array Technique
// First let’s understand normal difference array.
// 🔹 Normal Range Update
// If we want to add val to range [l, r]:
// Instead of:
// for i = l to r:
//    arr[i] += val

// We do:
// diff[l] += val
// diff[r+1] -= val

// Then prefix sum.
// That’s it.
// 🧠 PART 2 — Why We Need It Here
// In this problem:
// If flower i is below target,
// we must water from i to i + w - 1.
// That means:
// Add need to range [i, i+w-1].
// Instead of updating w elements each time,
// we use difference array.


class Solution {
public:

    /*
        Check if we can make ALL flowers >= target
        using at most k watering operations.
    */
    bool isPossible(vector<int>& arr, int n, int k, int w, int target) {

        // Difference array to simulate range increment
        vector<long long> diff(n + 1, 0);

        long long currAdd = 0;      // cumulative water effect till current index
        long long totalUsed = 0;    // total watering operations used

        for(int i = 0; i < n; i++) {

            // Apply prefix sum effect
            currAdd += diff[i];

            // Current height after previous waterings
            long long currentHeight = arr[i] + currAdd;

            // If height is still less than target
            if(currentHeight < target) {

                long long need = target - currentHeight;

                totalUsed += need;

                // If we exceed allowed watering days
                if(totalUsed > k) return false;

                // Apply watering from index i to i + w - 1
                currAdd += need;

                // Remove effect after window ends
                if(i + w < n)
                    diff[i + w] -= need;
            }
        }

        return true;
    }


    int maxMinHeight(vector<int> &arr, int k, int w) {

        int n = arr.size();

        // Minimum possible height
        int l = *min_element(arr.begin(), arr.end());

        // Maximum possible height
        int r = l + k;

        int ans = l;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            // If we can achieve this minimum height
            if(isPossible(arr, n, k, w, mid)) {

                ans = mid;     // store answer
                l = mid + 1;   // try to increase it //maximize the minimum height of all flowers after  k days of watering.
            }
            else {
                r = mid - 1;   // try smaller height
            }
        }

        return ans;
    }
};


// 🧠 🔥 UNIVERSAL isPossible() Framework
// Whenever doing Binary Search on Answer, ALWAYS follow this structure:
// ✅ STEP 1: Identify the Resource
// Ask:
// What is LIMITED?

// Examples:
// Problem Type	                   Limited Resource
// Operations allowed	                k
// Time allowed	                      T
// Budget allowed	                    money
// Days allowed	                      D
// Painters	                          P

// ✅ STEP 2: Identify What We Are Testing
// Binary search tests:
// Can we achieve "mid" ?
// So isPossible must answer:
// If answer = mid,
// can we do it within limit?

// ✅ STEP 3: Simulation Pattern
// Universal structure:

bool isPossible(mid) {

    resourceUsed = 0;

    for(each element) {

        compute requirement for this element;

        resourceUsed += required;

        if(resourceUsed > limit)
            return false;
    }

    return true;
}


// That’s the universal skeleton.
// 🧠 5 Universal Binary Search Patterns
// 🔹 Pattern 1: Minimize Maximum
// Example:
// Allocate books
// Painter partition
// Capacity to ship packages
// isPossible:

bool isPossible(maxLoad) {

    int usedPartitions = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {

        if(arr[i] > maxLoad)
            return false;

        if(currentSum + arr[i] <= maxLoad)
            currentSum += arr[i];
        else {
            usedPartitions++;
            currentSum = arr[i];
        }
    }

    return usedPartitions <= k;
}

// 🔹 Pattern 2: Maximize Minimum
// Example:
// Aggressive cows
// Place magnets
// This flower problem
// isPossible:

bool isPossible(minDistance) {

    int placed = 1;
    int last = arr[0];

    for(int i = 1; i < n; i++) {

        if(arr[i] - last >= minDistance) {
            placed++;
            last = arr[i];
        }
    }

    return placed >= k;
}

// 🔹 Pattern 3: Resource Distribution
// Example:
// This flower watering problem

bool isPossible(targetHeight) {

    simulate changes;

    if(resourceUsed <= k)
        return true;

    return false;
}

// 🔹 Pattern 4: Time-Based
// Example:
// Minimum speed to arrive
// Koko eating bananas

bool isPossible(speed) {

    totalTime = 0;

    for(each pile)
        totalTime += ceil(pile / speed); 
         // ceil(a / b) = (a + b − 1) / b
          // (arr[i]/mid)=(arr[i]+mid-1 / mid)
    return totalTime <= h;
}

// 🔹 Pattern 5: Feasibility Check
// Example:
// Can we make graph connected?
// Can we finish tasks?
// Simulate and check condition.

// 🎯 UNIVERSAL CHECKLIST (MEMORIZE THIS)
// When writing isPossible:
// What does mid represent?
// What resource is limited?
// For each element, how much resource needed?
// If resource exceeds limit → false
// Otherwise → true
// That’s it.

// 🚀 MASTER FORMULA
// Every Binary Search on Answer problem reduces to:
// We guess answer = mid
// We check feasibility
// If feasible → try better
// If not → reduce
// 🧠 How To Know It's Binary Search on Answer?
// Look for keywords:
// Maximize minimum
// Minimize maximum
// At most k
// At least k
// Within limit
// Possible or not
// If YES → Binary Search on Answer.
