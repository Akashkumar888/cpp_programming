
class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        //find the minimum number of operations required to make the sum of its elements less than 
        //or equal to half of the original sum. In one operation, you may replace 
        //any element with half of its value (with floating-point precision).
        double totalSum=accumulate(arr.begin(),arr.end(),0.0);
        double half=totalSum/2.0;
        priority_queue<double>pq; // minSteps chahiye totalSum<=half krne ke maximum element ko half minus kr do that's why we use max-heap
        int minSteps=0;
        for(int &num:arr)pq.push(num);
        while(totalSum>half){
            double val=pq.top();
            pq.pop();
            val=val/2.0;
            totalSum-=val;
            pq.push(val);
            minSteps++;
        }
        return minSteps;
    }
};
