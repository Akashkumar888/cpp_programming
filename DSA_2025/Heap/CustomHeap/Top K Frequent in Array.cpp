class Solution {
  public:
//   return the top k elements which have the highest frequency in the array.
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n=arr.size();
        vector<int>result;
        typedef pair<int,int>P;
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
        unordered_map<int,int>mp; // element and freq
        for(int &num:arr)mp[num]++;
        for(auto &it:mp){
            pq.push({it.second,it.first}); // freq and element 
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
// When the heap calls cmp(p1, p2), you cannot assume p1 is “bottom” and p2 is “top.”
// p1 = first element being compared by heap internally
// p2 = second element being compared
// What matters is: the comparator returns true if p1 is “less priority” than p2.”
// The heap will maintain the highest-priority element at pq.top().
// In short for your example:
// Sort (lambda) → s1 and s2 are just two elements being compared; not necessarily beginning or end.
// Heap (cmp) → p1 and p2 are elements being compared internally by the heap; p1 is not necessarily bottom, p2 is not necessarily top. The heap ensures pq.top() is the element with highest priority according to your comparator.

// p1 = first element to compare
// p2 = second element to compare
// Important: You don’t control which elements are p1 and p2 during heap operations. The heap will internally call cmp multiple times between elements as it builds the heap.
// When the heap calls cmp(x, y), it’s checking: “should x be ordered before y?”
// If cmp(x, y) == true, it treats x as less priority than y (in the context of priority_queue), because priority_queue always puts the largest-priority element at the top.

// Number	 Frequency
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


class Solution {
public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        vector<int> result;  // Vector to store the final top k frequent elements
        typedef pair<int,int> P;  // Alias for pair<frequency, element>

        // Count the frequency of each element in the array
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
        for(auto &it : mp) 
            pq.push({it.second, it.first}); // Push pair {frequency, element} into heap

        // Extract top k elements from the heap
        for(int i = 0; i < k; i++){
            result.push_back(pq.top().second); // Add element with highest frequency to result
            pq.pop(); // Remove the top element from the heap
        }

        return result; // Return the list of top k frequent elements
    }
};
