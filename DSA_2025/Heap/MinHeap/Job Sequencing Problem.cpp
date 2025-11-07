

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        typedef pair<int,int>P;
        int n=profit.size();
        vector<P>ans;
        for(int i=0;i<n;i++)ans.push_back({deadline[i],profit[i]});
        sort(ans.begin(),ans.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            if(ans[i].first>pq.size()){
                pq.push(ans[i].second);
            }
            else{
                if( !pq.empty() && ans[i].second>pq.top()){
                    pq.pop();
                    pq.push(ans[i].second);
                }
            }
        }
        int maxJob=0,maxProfit=0;
        while(!pq.empty()){
            maxJob++;
            maxProfit+=pq.top();
            pq.pop();
        }
        return {maxJob,maxProfit};
    }
};