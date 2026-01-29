
// ✅ 7 Coding Interview For Beginners 💼👨‍💻
// 1️⃣ Master DSA Basics First  
// – Focus on arrays, strings, recursion, linked lists, trees, and graphs.
// 2️⃣ Practice on LeetCode/CodeStudio  
// – Start with easy, move to medium. Learn patterns, not just solutions.
// 3️⃣ Understand the Problem Before You Code  
// – Don’t rush. Clarify inputs/outputs, edge cases, and constraints.
// 4️⃣ Explain Your Thought Process Aloud  
// – Interviewers care more about your logic than a perfect answer.
// 5️⃣ Write Clean, Readable Code  
// – Use proper variable names and indentation. Avoid shortcuts.
// 6️⃣ Revise Core CS Concepts  
// – Know time/space complexity, OOP basics, DBMS, OS, and networks.
// 7️⃣ Mock Interviews Help a Lot  
// – Use platforms like Pramp or interview with a friend for real-time practice.


class Solution {
  public:
    // Given a 2D array jobs[][] of size n × 3, where each row represents a single job with the following details:
    // jobs[i][0] : Start time of the job
    // jobs[i][1] : End time of the job
    // jobs[i][2] : Profit earned by completing the job
    // binarySearch for finding nextIndex
    int getNextIndex(int l,int currentJobEnd,vector<vector<int>>&jobs){
        int r=jobs.size()-1;
        int nextIdx = jobs.size(); // ✅ default = n (no job)
        while(l<=r){
            int mid=l+(r-l)/2;
            if(jobs[mid][0]>=currentJobEnd){
                nextIdx=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return nextIdx;
    }
    int solve(int i,int n,vector<vector<int>>&jobs,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int nextIdx=getNextIndex(i+1,jobs[i][1],jobs); // it check no need of this if(endTime<=jobs[i][0])
        // pick: always at least take current profit
        int pick = jobs[i][2];
        if (nextIdx < n) pick += solve(nextIdx, n, jobs, dp);

        int notpick = solve(i + 1, n, jobs, dp);
        return dp[i]= max(pick,notpick);
    }
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        int n=jobs.size();
        int m=jobs[0].size(); // 3
        // sort(jobs.begin(), jobs.end(), greater<vector<int>>()); // descending order me
        auto cmp=[&](const vector<int>&a,const vector<int>&b){
          return a[0]<b[0];  
        };
        sort(jobs.begin(), jobs.end(), cmp);
        vector<int>dp(n+1,-1);
        return solve(0,n,jobs,dp);
    }
};


// ✅ Why ascending sorting is NECESSARY?
// Because compatibility checking in weighted interval scheduling is:
// find job j > i such that jobs[j].start >= jobs[i].end
// This only works if jobs are sorted in increasing start time.
// ✅ Important truth:
// ❌ DESCENDING + nextIndex DP is mathematically impossible for this problem
// ✅ Only ASCENDING sort works
// This is not a coding issue.
// It is the fundamental property of weighted interval scheduling.


class Solution {
public:
int getNextIndex(int l,int currentJobEnd,vector<vector<int>>&jobs){
        int r=jobs.size()-1;
        int nextIdx = jobs.size(); // ✅ default = n (no job)
        while(l<=r){
            int mid=l+(r-l)/2;
            if(jobs[mid][0]>=currentJobEnd){
                nextIdx=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return nextIdx;
    }
    int solve(int i,int n,vector<vector<int>>&jobs,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int nextIdx=getNextIndex(i+1,jobs[i][1],jobs); // it check no need of this if(endTime<=jobs[i][0])
        // pick: always at least take current profit
        int pick = jobs[i][2];
        if (nextIdx < n) pick += solve(nextIdx, n, jobs, dp);

        int notpick = solve(i + 1, n, jobs, dp);
        return dp[i]= max(pick,notpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        jobs.reserve(n);
        for(int i=0;i<profit.size();i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        int m=jobs[0].size(); // 3
        // sort(jobs.begin(), jobs.end(), greater<vector<int>>()); // descending order me
        auto cmp=[&](const vector<int>&a,const vector<int>&b){
          return a[0]<b[0];  
        };
        sort(jobs.begin(), jobs.end(), cmp);
        vector<int>dp(n+1,-1);
        return solve(0,n,jobs,dp);
    }
};


class Solution {
  public:
    // Given a 2D array jobs[][] of size n × 3, where each row represents a single job with the following details:
    // jobs[i][0] : Start time of the job
    // jobs[i][1] : End time of the job
    // jobs[i][2] : Profit earned by completing the job
    // binarySearch for finding nextIndex
    // find previous non-overlapping job in DESC sorted jobs
    int getNextIndex(int l,int currentJobEnd,vector<vector<int>>&jobs){
        int r=jobs.size()-1;
        int nextIdx = jobs.size(); // ✅ default = n (no job)
        while(l<=r){
            int mid=l+(r-l)/2;
            if(jobs[mid][0]>=currentJobEnd){
                nextIdx=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return nextIdx;
    }
    int maxProfit(vector<vector<int>>& jobs) {
        int n = jobs.size();

        // sort DESCENDING by start time
        sort(jobs.begin(), jobs.end(), [&](auto &a, auto &b) {
            return a[0] < b[0];
        });
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
        int nextIdx=getNextIndex(i+1,jobs[i][1],jobs); // it check no need of this if(endTime<=jobs[i][0])
        // pick: always at least take current profit
        int pick = jobs[i][2];
        if (nextIdx < n) pick += dp[nextIdx];

        int notpick =dp[i+1];
        dp[i]= max(pick,notpick);
        }
        return dp[0];
    }
};

class Solution {
public:
int getNextIndex(int l,int currentJobEnd,vector<vector<int>>&jobs){
        int r=jobs.size()-1;
        int nextIdx = jobs.size(); // ✅ default = n (no job)
        while(l<=r){
            int mid=l+(r-l)/2;
            if(jobs[mid][0]>=currentJobEnd){
                nextIdx=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return nextIdx;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        jobs.reserve(n);
        for(int i=0;i<profit.size();i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        // sort DESCENDING by start time
        sort(jobs.begin(), jobs.end(), [&](auto &a, auto &b) {
            return a[0] < b[0];
        });
        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
        int nextIdx=getNextIndex(i+1,jobs[i][1],jobs); // it check no need of this if(endTime<=jobs[i][0])
        // pick: always at least take current profit
        int pick = jobs[i][2];
        if (nextIdx < n) pick += dp[nextIdx];

        int notpick =dp[i+1];
        dp[i]= max(pick,notpick);
        }
        return dp[0];
    }
};


class Solution {
public:

    int solve(int i, vector<vector<int>>& jobs, vector<int>& dp, vector<int>& prevJob) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        // pick the job
        int pick = jobs[i][2] + solve(prevJob[i], jobs, dp, prevJob);

        // not pick
        int notpick = solve(i - 1, jobs, dp, prevJob);

        return dp[i] = max(pick, notpick);
    }

    int maxProfit(vector<vector<int>>& jobs) {
        int n = jobs.size();

        // ✅ Sort by END time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // ✅ Build prevJob[] using binary search
        vector<int> prevJob(n, -1);
        vector<int> endTimes(n);
        for(int i = 0; i < n; i++) endTimes[i] = jobs[i][1];

        for (int i = 0; i < n; i++) {
            int start = jobs[i][0];

            // find last job which ends <= this job's start
            int idx = upper_bound(endTimes.begin(), endTimes.end(), start) - endTimes.begin() - 1;
            prevJob[i] = idx;
        }

        vector<int> dp(n, -1);
        return solve(n - 1, jobs, dp, prevJob);
    }
};
