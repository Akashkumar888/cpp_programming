
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>events; // sorted based on key,value 
        for(auto &trip:trips){
            int numPassengers=trip[0];
            int from=trip[1];
            int to=trip[2];
            events[from] += numPassengers;  // pick up, instead of +1
            events[to]   -= numPassengers;  // drop off, instead of -1
        }

        int activePassengers = 0;
        for (auto &it : events) {
            activePassengers += it.second;
            if (activePassengers > capacity) {
                return false;
            }
        }
        return true;
    }
};