
class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if(start==end)return 0;
        int MOD=1000;
        vector<int>dist(MOD,INT_MAX);
        queue<int>q;
        q.push(start);
        dist[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &ngbr:arr){
                int adjNode=(node*ngbr)%MOD;
                if(dist[node]+1 < dist[adjNode]){
                    dist[adjNode]=dist[node]+1;
                    if(adjNode==end){
                        return dist[adjNode];
                    }
                    q.push(adjNode);
                }
            }
        }
        return -1;
    }
};

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        typedef pair<int,int>P;
        int MOD=1000;
        vector<int>dist(MOD,INT_MAX);
        dist[start]=0;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,start});
        while(!pq.empty()){
            int step=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(node==end) return step;
            // skip old entries
            if(step>dist[node]){
                continue;
            }
            for(int i=0;i<arr.size();i++){
              int adjNode=(node*arr[i])%MOD;
              if(step + 1 < dist[adjNode]){
                  dist[adjNode]=step + 1;
                  pq.push({step +1 , adjNode});
              }
            }
        }
        if(dist[end]==INT_MAX) return -1;
    }
};


// User function Template for C++

class Solution {
  public:
  typedef pair<int,int>P;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=100000;
        vector<int>dist(mod,INT_MAX);
        dist[start]=0;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,start});
        while(!pq.empty()){
            int step=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            
            if(x==end) return step;
            
            for(int i=0;i<arr.size();i++){
              int newx=(x*arr[i])%mod;
              if(step + 1 <dist[newx]){
                  dist[newx]=step + 1;
                  pq.push({step+1 , newx});
              }
            }
        }
        if(dist[end]==INT_MAX) return -1;
    }
};