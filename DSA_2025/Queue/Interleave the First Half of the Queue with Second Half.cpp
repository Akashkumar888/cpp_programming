
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        if(n<=2)return;
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        int mid=n/2;
        int i=0,j=mid;
        while(mid<n){
            q.push(ans[i]);
            i++;
            q.push(ans[mid]);
            mid++;
        }
    }
};

