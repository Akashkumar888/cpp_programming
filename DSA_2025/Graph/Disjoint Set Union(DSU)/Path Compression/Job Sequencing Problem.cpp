
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
