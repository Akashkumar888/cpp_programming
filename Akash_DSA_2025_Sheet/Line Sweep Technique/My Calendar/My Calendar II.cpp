
class MyCalendarTwo {
public:
    map<int,int>events; // sorted based on key,value 

    bool book(int startTime, int endTime) {
        // do 
        events[startTime]++;
        events[endTime]--;

        int active = 0;
        for (auto &it : events) {
            active += it.second;
            if (active >= 3) { // event if adding the event will not cause a triple booking.
                // undo 
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

 class MyCalendarTwo {
public:
    vector<pair<int,int>> events;

    bool book(int startTime, int endTime) {
        pair<int,int> s = {startTime, +1};
        pair<int,int> e = {endTime, -1};

        events.push_back(s);
        events.push_back(e);

        sort(events.begin(), events.end());

        int active = 0;
        for (auto &x : events) {
            active += x.second;
            if (active >= 3) {
                // rollback SAFELY
                auto it2 = find(events.begin(), events.end(), e);
                auto it1 = find(events.begin(), events.end(), s);

                // erase larger index first
                if (it1 > it2) {
                    events.erase(it1);
                    events.erase(it2);
                } else {
                    events.erase(it2);
                    events.erase(it1);
                }
                return false;
            }
        }
        return true;
    }
};
