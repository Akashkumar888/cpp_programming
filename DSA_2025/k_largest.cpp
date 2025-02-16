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
