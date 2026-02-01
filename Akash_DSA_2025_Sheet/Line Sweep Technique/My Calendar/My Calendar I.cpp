
class MyCalendar {
public:
map<int,int>events; // sorted based on key,value 
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        // do 
        events[startTime]++;
        events[endTime]--;

        int active = 0;
        for (auto &it : events) {
            active += it.second;
            if (active >= 2) {//if adding the event will not cause a double booking.
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

 class MyCalendar {
public:
vector<pair<int,int>>ans;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &event:ans){
            if(event.second>start && event.first<end)return false;
        }
        ans.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */