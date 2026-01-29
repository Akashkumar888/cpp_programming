
typedef pair<int,int>P;
        auto cmp=[&](const P&p1,const P&p2){
        // smaller length has higher priority
            if(p1.first == p2.first)return p1.second > p2.second; 
            // smaller number has higher priority
            return p1.first > p2.first;  
        };
        // Min-heap stores pairs:
    //{number, length of subsequence ending with this number}
        priority_queue<P,vector<P>,decltype(cmp)>pq(cmp);
        