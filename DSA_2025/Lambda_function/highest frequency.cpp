
// Comparator: larger freq first, smaller num if tie
        auto cmp = [&](P p1,P p2){ // never use & in this line 
            if(p1.first == p2.first) return p1.second < p2.second;// smaller number if freq same
            return p1.first > p2.first;// larger frequency first
        };

        set<P, decltype(cmp)>s(cmp);

// P p1, P p2 passes by value, so copies of the pairs are made whenever the comparator is called.
// This is safe, but slightly less efficient than passing by reference because each comparison involves copying the pair<int,int>.
// If you want to avoid copies, you can pass by const reference:
// Passes by reference without copying.
// const ensures the comparator doesn’t modify the elements.
// Safe and standard-compliant for priority_queue, set, map, etc.
// ✅ Conclusion: For comparators, always use const & to avoid copies and keep safety.


        // Custom comparator: larger freq first, smaller num if tie
        auto cmp = [](const P &p1, const P &p2){
            if(p1.first != p2.first) return p1.first < p2.first;  // larger freq first
            return p1.second > p2.second;                         // smaller number first if tie
        };
        
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

        