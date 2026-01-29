typedef pair<int,char> P;
// Custom comparator: 
auto cmp=[&](const P&p1,const P&p2){// always use const here  
  if(p1.first==p2.first)return p2.second<p1.second;
  return p1.first < p2.first;
};

priority_queue<P,vector<P>,decltype(cmp)>p(cmp);// custom heap  



typedef pair<int,char> P;

// Custom comparator for the priority_queue
auto cmp = [&](const P &p1, const P &p2) { // ✅ use const to avoid modifying elements
    // If the first values are equal, compare by second
    if (p1.first == p2.first)
        return p2.second < p1.second;  
        // This means: higher 'char' has higher priority
        // (because priority_queue expects "return true" if p1 should come *after* p2)
    
    // Otherwise, order by the first element
    return p1.first < p2.first; 
    // This means: larger 'first' value has higher priority
};

// Make a priority_queue (max-heap like structure but with our custom comparator)
priority_queue<P, vector<P>, decltype(cmp)> p(cmp);


