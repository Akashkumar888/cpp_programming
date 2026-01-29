
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>>pq; //k largest elements that's why use min-heap
        // return k largest elements in decreasing order. 
        vector<int>result(k);
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k)pq.pop();
        }
        int j=0;
        while(!pq.empty()){
            result[k-1-j]=(pq.top());
            j++;
            pq.pop();
        }
        return result;
    }
};