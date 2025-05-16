
class Solution {
  public:
  typedef pair<int,pair<int,int>>pip;
    vector<int> findSmallestRange(vector<vector<int>>& nums) {
        // code here
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        int mx=INT_MIN;
        int m=nums.size();
        int n=nums.size();
        for(int i=0;i<m;i++){
            mx=max(mx,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        int mn=pq.top().first;
        int start=mn;
        int end=mx;
        while(true){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col==nums[row].size()-1)break;
            pq.push({nums[row][col+1],{row,col+1}});
            mx=max(mx,nums[row][col+1]);
            mn=pq.top().first;
            if(mx-mn<end-start){
                start=mn;
                end=mx;
            }
        }
       return {start,end};
    }
  };

  