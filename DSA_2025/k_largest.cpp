
lass Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          // Your code here
          vector<int>ans;
          sort(arr.begin(),arr.end(),greater<>());
          int i=0;
          while(i<k){
              ans.push_back(arr[i]);
              i++;
          }
          return ans;
      }
  };




class{
  public:
      vector<int> kLargest(vector<int>& arr, int k) {
          // Your code here
          vector<int>ans;
          priority_queue<int>pq;
          for(int &num:arr)pq.push(num);
          while(!pq.empty() && k>0){
              ans.push_back(pq.top());
              pq.pop();
              k--;
          }
          return ans;
      }
};





vector<int> kLargest(vector<int>& arr, int k) {
    // Your code here
    vector<int>ans(k);
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();
    }
    int i=k-1;
    while(!pq.empty()){
        ans[i]=pq.top();
        pq.pop();
        i--;
    }
    return ans;
} 