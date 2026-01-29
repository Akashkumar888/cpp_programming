// lambda function 
        // comparorators should bot modify elements
        // avoids unnecessary copies
        // matches stl requirements &
        auto cmp = [&](const P &p1, const P &p2) {
        if (p1.first == p2.first) 
        return p1.second > p2.second; // If frequencies are equal, put the larger number first in the heap
        return p2.first < p1.first; // Otherwise, put the number with larger frequency first (max-heap by frequency)
        };
        // if two numbers have the same frequency, 
        //the larger number should be given the higher priority
        priority_queue<P,vector<P>,decltype(cmp)>pq(cmp); // custom This is meant to be a min-heap of size k, keeping top k frequent numbers.


// Number	Frequency
// 5	      3
// 7	      2
// 10	      1
// 11	      1
// 2	      1
// 8	      1
// 9	      1

// Step 1: Push {3,5}
// Heap:
// [(3,5)]
// Heap size = 1 ≤ k → no pop.

// Step 2: Push {2,7}
// Heap before size adjustment:
// [(3,5),(2,7)]
// Comparator: min-heap by frequency.
// 2 < 3 → 2,7 is top.
// Heap after min-heap adjustment:
// [(2,7),(3,5)]
// Heap size = 2 ≤ k → no pop.

// Step 3: Push {1,10}
// Heap before adjustment:
// [(2,7),(3,5),(1,10)]
// Min-heap by freq → smallest frequency at top.
// (1,10) has freq=1 → becomes new top.
// Heap after adjustment:
// [(1,10),(2,7),(3,5)]
// Heap size = 3 ≤ k → no pop.

// Step 4: Push {1,11}
// Heap before adjustment:
// [(1,10),(2,7),(3,5),(1,11)]
// Frequencies of (1,10) and (1,11) are equal.
// Comparator: p1.second > p2.second → larger number has higher priority in heap?
// Min-heap in C++: cmp(x,y) == true → x is less priority.
// (1,10) vs (1,11) → 10 > 11? false → ordering okay.
// Heap after adjustment (min-heap by freq, tie-breaks by number):
// [(1,10),(1,11),(3,5),(2,7)]
// Heap size = 4 = k → no pop yet.

// Step 5: Push {1,2}
// Heap before adjustment:
// [(1,10),(1,11),(3,5),(2,7),(1,2)]
// Size = 5 > k → need to pop top (smallest freq).
// Top = (1,2) or (1,10) depending on tie-breaks.
// Step by step:
// Heap elements: (1,10),(1,11),(3,5),(2,7),(1,2)
// Smallest frequency = 1 → candidates: (1,10),(1,11),(1,2)
// Comparator: p1.second > p2.second → larger number first → in min-heap, smaller number pops first
// Among 10, 11, 2 → 2 is smallest → popped.
// Heap after pop:
// [(1,10),(1,11),(3,5),(2,7)]
// Heap size = 4 → okay.

// Step 6: Push {1,8}
// Heap before adjustment:
// [(1,10),(1,11),(3,5),(2,7),(1,8)]
// Pop top (smallest freq with smallest number) → freq=1, numbers = 10,11,8 → 8 smallest → pop 8
// Heap after pop:
// [(1,10),(1,11),(3,5),(2,7)]
// Heap size = 4 → okay.

// Step 7: Push {1,9}
// Heap before adjustment:
// [(1,10),(1,11),(3,5),(2,7),(1,9)]
// Pop top (smallest freq, smallest number) → freq=1, numbers = 10,11,9 → 9 smallest → pop 9
// Heap after pop:
// [(1,10),(1,11),(3,5),(2,7)]
// Heap size = 4 → okay.
// ✅ Final heap (min-heap by frequency, tie-breaks by number):
// [(1,10),(1,11),(3,5),(2,7)]

// Step 8: Pop to get result
// Pop elements → push pq.top().second:
// Pop (1,10) → result: 10
// Pop (1,11) → result: 10,11
// Pop (2,7) → result: 10,11,7
// Pop (3,5) → result: 10,11,7,5
// Reverse result to get highest frequency first:
// result = [5,7,11,10]


        unordered_map<int,int> mp;
        for(int &num : arr) mp[num]++; // mp[num] stores frequency of num

        // Custom comparator for the priority queue (max-heap by frequency)
        auto cmp = [&](const P &p1, const P &p2) {
            if(p1.first == p2.first) 
                return p1.second < p2.second; // If frequencies are equal, larger number has higher priority
            return p1.first < p2.first; // Otherwise, larger frequency has higher priority
        };

        // Priority queue (heap) to store elements based on frequency and value
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        