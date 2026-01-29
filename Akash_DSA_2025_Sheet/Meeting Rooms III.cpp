class Solution {
  public:
  typedef pair<long long,int>P;
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        int m=meetings.size();
        vector<int>roomUsedCount(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<P,vector<P>,greater<P>>usedRooms;
        priority_queue<int,vector<int>,greater<int>>availableRooms;
        for(int i=0;i<n;i++)availableRooms.push(i);
        for(auto &meet:meetings){
            int start=meet[0];
            int end=meet[1];
            int duration=end-start;
            while(!usedRooms.empty() && usedRooms.top().first<=start){
                int room=usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }
            if(!availableRooms.empty()){
                int roomFree=availableRooms.top();
                usedRooms.push({end,roomFree});
                availableRooms.pop();
                roomUsedCount[roomFree]++;
            }
            else{
                int roomEarly=usedRooms.top().second;
                long long EndTime=usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({EndTime+duration,roomEarly});
                roomUsedCount[roomEarly]++;
            }
        }
        int roomNumber=-1;
        int maxiCount=0;
       for(int i=0;i<n;i++){
           if(maxiCount<roomUsedCount[i]){
               maxiCount=roomUsedCount[i];
               roomNumber=i;
           }
       }
       return roomNumber;
    }
  };
