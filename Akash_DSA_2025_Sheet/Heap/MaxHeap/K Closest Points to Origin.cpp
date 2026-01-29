
class Solution {
  public:
// where each point is represented as points[i] = [xi, yi] on the X-Y plane.
// Return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance, defined as:
// distance = sqrt( (x2 - x1)2 + (y2 - y1)2 )
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        typedef pair<int,pair<int,int>>P;
        priority_queue<P>pq; // K Closest Points to Origin means nearest then i use max-heap
        vector<vector<int>>result;
        int m=points.size();
        for(int i=0;i<m;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int dist=x1*x1+y1*y1;
            pq.push({dist,{x1,y1}});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            result.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return result;
    }
};
