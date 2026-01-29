class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        // line sweep algorithm
        int n=start.size();
        // step - 1 
        vector<pair<int,int>>events;
        for(int i=0;i<n;i++){
            events.push_back({start[i],  +1});
            events.push_back({end[i], -1});
        }
       // step - 2
       sort(events.begin(),events.end());
       
       // step - 3
        int maxRooms=0;
        int currRooms=0;
        for(auto &e:events){
            currRooms+=e.second;
            if(currRooms>maxRooms){
                maxRooms=currRooms;
            }
        }
        return maxRooms;
    }
};




// 🔹 Approach 1: Two Pointer (same logic as Java, in C++)
class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int n = start.size();
        int i = 0, j = 0;
        int currRooms = 0, maxRooms = 0;

        while(i < n && j < n){
            if(start[i] < end[j]){
                currRooms++;                 // new meeting starts
                maxRooms = max(maxRooms, currRooms);
                i++;
            } 
            else {
                currRooms--;                 // meeting ends
                j++;
            }
        }
        return maxRooms;
    }
};


// Idea:
// Sort start and end times.
// If a meeting starts before the previous ends → need a new room.
// Else, free a room.
// Track the maximum rooms needed.

// 🔹 Approach 2: Line Sweep (Events Method)


class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        vector<pair<int,int>> events;

        // Step 1: create events
        for(int i = 0; i < n; i++){
            events.push_back({start[i], +1}); // meeting starts
            events.push_back({end[i],   -1}); // meeting ends
        }

        // Step 2: sort events
        sort(events.begin(), events.end());

        // Step 3: sweep
        int currRooms = 0, maxRooms = 0;
        for(auto &e : events){
            currRooms += e.second;
            maxRooms = max(maxRooms, currRooms);
        }

        return maxRooms;
    }
};


// Idea:
// +1 for start, -1 for end.
// Sort by time (end comes before start at same time).
// Prefix sum gives rooms in use.
// Maximum value is the answer.
// Both are O(n log n) and interview-ready.
