
class Solution {
  public:
    int maxProfit(int x, int y,vector<int> &arr,vector<int> &brr) {
        int n = arr.size();
        vector<pair<int,int>> tasks;
        /*
            Store:
            { absolute difference , index }

            Why difference?

            Larger difference means:
            assigning to wrong machine
            causes larger loss.

            So process important tasks first.
        */
        for(int i = 0; i < n; i++){
            int diff = abs(arr[i] - brr[i]);
            tasks.push_back({diff, i});
        }
        /*
            Sort by maximum difference descending
        */
        sort(tasks.begin(),tasks.end(),greater<pair<int,int>>());
        int totalProfit = 0;
        
        // Process tasks greedily
        for(auto &it : tasks){
            int idx = it.second;
            /*
                If Machine A gives more profit
            */
            if(arr[idx] >= brr[idx]){
                // Assign to A if capacity available
                if(x > 0){
                    totalProfit += arr[idx];
                    x--;
                }
                // Otherwise assign to B
                else{
                    totalProfit += brr[idx];
                    y--;
                }
            }
            /*
                If Machine B gives more profit
            */
            else{
                // Assign to B if capacity available
                if(y > 0){
                    totalProfit += brr[idx];
                    y--;
                }
                // Otherwise assign to A
                else{
                    totalProfit += arr[idx];
                    x--;
                }
            }
        }
        return totalProfit;
    }
};


class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int,pair<int,int>>>p;
        for(int i=0;i<arr.size();i++){
            p.push_back({abs(arr[i]-brr[i]), {arr[i], brr[i]}});
        }
        sort(p.rbegin(), p.rend());
        
        long long ans=0;
        for(int i=0;i<p.size();i++){
            if(x==0){
                ans+=p[i].second.second;
            }
            else if(y==0){
                ans+=p[i].second.first;
            }
            else{
                if(p[i].second.first > p[i].second.second){
                    x--;
                    ans+=p[i].second.first;
                }
                else{
                    y--;
                    ans+=p[i].second.second;
                }
            }
        }
        return ans;
    }
};



class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &arr, vector<int> &brr) {
        int n = arr.size();
        vector<pair<int,int>> tasks;
        // {difference, index}
        for(int i = 0; i < n; i++){
            tasks.push_back({abs(arr[i] - brr[i]), i});
        }
        // sort by maximum difference descending
        sort(tasks.begin(), tasks.end(), greater<pair<int,int>>());
        int totalProfit = 0;
        for(auto &it : tasks){
            int idx = it.second;
            // prefer machine A
            if(arr[idx] >= brr[idx]){
                if(x > 0){
                    totalProfit += arr[idx];
                    x--;
                }
                else{
                    totalProfit += brr[idx];
                    y--;
                }
            }
            // prefer machine B
            else{
                if(y > 0){
                    totalProfit += brr[idx];
                    y--;
                }
                else{
                    totalProfit += arr[idx];
                    x--;
                }
            }
        }
        return totalProfit;
    }
};

