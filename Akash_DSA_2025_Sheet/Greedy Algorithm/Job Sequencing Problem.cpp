
class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = profit.size();

        // Step 1: Prepare job list {profit, deadline}
        vector<pair<int,int>> jobs;
        int maxD = 0;
        for(int i = 0; i < n; i++){
            jobs.push_back({profit[i], deadline[i]});
            maxD = max(maxD, deadline[i]);
        }

        // Step 2: Sort by profit (descending)
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

        // Step 3: Slot array to track used days
        vector<int> slot(maxD + 1, -1);

        int count = 0;
        int totalProfit = 0;

        // Step 4: For each job, find a free slot
        for (int i = 0; i < n; i++) {

            int d = jobs[i].second;
            int p = jobs[i].first;

            // Try to place job at latest free day ≤ deadline
            for (int day = d; day >= 1; day--) {

                if (slot[day] == -1) {     // free slot
                    slot[day] = p;         // place job
                    count++;
                    totalProfit += p;
                    break;
                }

            }
        }

        return {count, totalProfit};
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