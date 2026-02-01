
class MyCalendarThree {
public:
map<int,int>events; // sorted based on key,value 
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        // do 
        events[startTime]++;
        events[endTime]--;

        int active = 0;
        int maxValue=-1;
        for (auto &it : events) {
            active += it.second;
                // undo 
                maxValue=max(maxValue,active);
                // events[startTime]--;
                // events[endTime]++;
        }
        return maxValue;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */