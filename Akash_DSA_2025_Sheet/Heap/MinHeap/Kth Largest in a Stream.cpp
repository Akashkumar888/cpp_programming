
class Solution {
  public:
  //Kth largest element (not Kth largest unique element) after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion. 
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        vector<int>result;
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            int topElement=-1;
            while(pq.size()>=k){
                topElement=pq.top();
                pq.pop();
            }
            result.push_back(topElement);
            if(topElement!=-1)pq.push(topElement);
        }
        return result;
    }
};


class Solution {
  public:
  //Kth largest element (not Kth largest unique element) after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion. 
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        vector<int>result;
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int &x : arr){
            pq.push(x);

            if(pq.size() > k){
                pq.pop();
            }

            if(pq.size() < k) result.push_back(-1);
            else result.push_back(pq.top());
        }
        return result;
    }
};