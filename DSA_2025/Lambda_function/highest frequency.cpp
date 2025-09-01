
// Comparator: larger freq first, smaller num if tie
        auto cmp = [&](P p1,P p2){ // never use & in this line 
            if(p1.first == p2.first) return p1.second < p2.second;// smaller number if freq same
            return p1.first > p2.first;// larger frequency first
        };



        set<P, decltype(cmp)>s(cmp);



        // Custom comparator: larger freq first, smaller num if tie
        auto cmp = [](const P &p1, const P &p2){
            if(p1.first != p2.first) return p1.first < p2.first;  // larger freq first
            return p1.second > p2.second;                         // smaller number first if tie
        };
        
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

        