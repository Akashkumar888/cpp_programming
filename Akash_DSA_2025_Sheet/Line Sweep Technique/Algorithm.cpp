
// 🔹 Line Sweep Technique + Delta Concept (in C++)

// The Line Sweep Technique is an efficient algorithmic approach used to process interval-based problems such as:
// Instead of thinking in terms of full intervals like [l, r], we break each interval into events:

// Start Event → something begins
// End Event → something ends

// Each event carries a delta (change in state).

// For an interval [l, r]:

// Event at l       → +1   (start)
// Event at r + 1   → -1   (end)


// These events are stored, sorted, and then processed from left to right.

// Overlapping intervals
// Maximum number of guests at a time
// Range addition queries
// Meeting room problems
// Traffic / event simulations

// It works by converting ranges into events and then “sweeping” a virtual line from left to right while updating a running state.

// The Delta concept is used to mark:

// +1 → start of an interval

// -1 → end of an interval

// Instead of processing each range fully, we just store changes at boundaries.

// Example Problem

// Given intervals:

// [1, 5], [2, 6], [4, 8]




// Find the maximum number of overlapping intervals.


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // line sweep algorithm
        // step - 1 
        vector<pair<int,int>>events;
        for(auto &log:logs){
            events.push_back({log[0],  +1});
            events.push_back({log[1], -1});
        }
       // step - 2
       sort(events.begin(),events.end());

       // step - 3
        int minYear=2050;
        int maxPop=0;
        int currPop=0;
        for(auto &e:events){
            currPop+=e.second;
            if(currPop>maxPop){
                maxPop=currPop;
                minYear=e.first;
            }
        }
        return minYear;
    }
};

// 👉 map is the BEST choice for line sweep in MyCalendarTwo.
// The vector<pair> version works in theory, but is fragile, slower, and risky in practice.
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // line sweep algorithm
        // step - 1 
        map<int,int>events;
        for(auto &log:logs){
            events[log[0]]++;
            events[log[1]]--;
        }
       

       // step - 3
        int minYear=2050;
        int maxPop=0;
        int currPop=0;
        for(auto &it:events){
            currPop+=it.second;
            if(currPop>maxPop){
                maxPop=currPop;
                minYear=it.first;
            }
        }
        return minYear;
    }
};


// Why This is Powerful
// Avoids O(N²) brute force
// Works in O(N log N)
// Perfect for competitive programming
// Used in calendar problems, prefix ranges, event counting, etc.
// This is essentially a prefix sum over events, combined with sorting — that’s the heart of Line Sweep + Delta.



// 🔹 Difference Array Technique
// Used when:
// You have a fixed array size N
// You need to perform multiple range updates
// After all updates, you want the final array values

// Typical problem:
// Given N zeros, perform many operations like
// “add x to range [l, r]”, then print final array.

// Idea
// Instead of updating every index in [l, r], do:

// diff[l]   += x
// diff[r+1] -= x

// Then build the array using prefix sum.



// 🔹 Line Sweep Algorithm
// Used when:
// You are dealing with intervals or events
// Coordinates can be large (e.g., up to 10⁹)
// You only care about aggregates like:
// max overlap
// number of active intervals
// time with most events
// We don’t build a full array.
// We store only event points and sweep them in sorted order.
// In One Line
// Difference Array → “I need the final array after many range updates.”
// Line Sweep → “I need statistics over intervals without building the whole array.”
// Conceptually similar, but applied to different problem types.

