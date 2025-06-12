
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        typedef pair<int,int>P;
    // Custom comparator: sort by distance first, if equal, prefer larger value
    auto cmp=[&x](pair<int,int>&a,pair<int,int>&b) {
        if(abs(a.first-x)==abs(b.first-x))
            return a.first<b.first; // prefer larger value
        return abs(a.first-x)>abs(b.first-x);
    };
    priority_queue<P,vector<P>,decltype(cmp)>pq(cmp);
    for (int &num:arr) {
        if(num==x)continue; // exclude x
        pq.push({num,num});
    }
    vector<int>ans;
    while (!pq.empty()&&k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
    }
};
