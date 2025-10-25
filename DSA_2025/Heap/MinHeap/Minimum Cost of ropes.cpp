
class Solution {
  public:
//   all ropes into a single rope with the minimum total cost. 
// The cost to connect two ropes is the sum of their lengths. 
    int minCost(vector<int>& arr) {
        // code here
        int totalCost=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int &num:arr)pq.push(num);
        while(pq.size()>=2){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            totalCost+=(first+second);
            pq.push(first+second);
        }
        return totalCost;
    }
};