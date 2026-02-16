
// 🔥 RULE 1 — If interval is [start, end] (inclusive)
// Meaning:
// It includes end.
// Then use:
// events[start] += 1;
// events[end + 1] -= 1;

// Because the interval stops AFTER end.
// Example:
// Interval = [1,5]
// Active at:
// 1 2 3 4 5

// So at index 6 it should stop.
// Hence:
// +1 at 1
// -1 at 6

// ✅ That’s why end+1
// 🔥 RULE 2 — If interval is [start, end) (half-open)
// Meaning:
// Includes start
// Excludes end
// Then use:
// events[start] += 1;
// events[end] -= 1;

// Because it already stops at end.
// 🧠 Why Some Use end+1 Trick?
// Because sometimes:
// Problem states inclusive intervals
// Or you convert inclusive to half-open
// You convert:
// [start, end]  →  [start, end+1)
// So that you can use standard half-open logic.

// You are given an array of intervals arr[][], where each interval is represented by two integers [start, end] (inclusive)
class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {

        map<int,int> events;

        for(auto &event : arr){
            int start = event[0];
            int end   = event[1];

            events[start] += 1;
            events[end + 1] -= 1;   // FIXED HERE
        }

        int maxCount = 0;
        int count = 0;

        for(auto &it : events){
            count += it.second;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
// this cause tle for larges test cases 




class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        // i used here line sweep algorithm
        int n=arr.size();
        // step - 1 
        vector<pair<int,int>>events;
        for(auto &event:arr){
            int start=event[0];
            int end=event[1];
            events.push_back({start,+1});
            events.push_back({end+1,-1});
        }
        // step - 2
        // sort the events
        sort(events.begin(),events.end());
        
        // step - 3
        int maxCount=0;
        int count=0;
        for(auto &it:events){
            count+=it.second;
            if(count>maxCount){
                maxCount=count;
            }
        }
        return maxCount;
    }
};
