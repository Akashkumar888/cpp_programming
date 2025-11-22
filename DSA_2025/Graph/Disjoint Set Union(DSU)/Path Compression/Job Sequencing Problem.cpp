
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();
        vector<vector<int>> jobs; 
        // jobs[i] = {start, end, profit}

        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        vector<int> dp(n);  // dp[i] = max profit upto job i
        dp[0] = jobs[0][2];

        for(int i = 1; i < n; i++){
            int includeProfit = jobs[i][2];

            // binary search for last non-conflicting job
            int l = 0, r = i - 1, last = -1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(jobs[mid][1] <= jobs[i][0]){
                    last = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(last != -1) 
                includeProfit += dp[last];

            dp[i] = max(dp[i-1], includeProfit);
        }

        return dp[n-1];
    }
};



class Solution {
public:
    int find(int x, vector<int> &parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        vector<pair<int,int>> jobs;
        
        int maxD = 0;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxD = max(maxD, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());  // sort by profit desc

        vector<int> parent(maxD + 1);
        for (int i = 0; i <= maxD; i++)
            parent[i] = i;

        int count = 0;
        int totalProfit = 0;

        for (auto &job : jobs) {
            int profit = job.first;
            int dead = job.second;

            int availableSlot = find(dead, parent);

            if (availableSlot > 0) {
                parent[availableSlot] = find(availableSlot - 1, parent);
                count++;
                totalProfit += profit;
            }
        }

        return {count, totalProfit};
    }
};
