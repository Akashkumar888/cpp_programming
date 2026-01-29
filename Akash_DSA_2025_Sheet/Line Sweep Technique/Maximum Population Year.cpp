
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

