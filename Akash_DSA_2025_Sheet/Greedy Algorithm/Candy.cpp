
// This is the Candy Distribution problem.
// Rule:
// Every child gets at least 1 candy.
// If arr[i] > neighbor, then candy[i] > candy[neighbor].
// You’ve written three correct approaches—they represent levels of optimization. In an interview, this is gold.

// 🔹 Approach 1: Two Arrays (L2R & R2L)
// vector<int> L2R(n,1), R2L(n,1);
// Idea:
// Left → Right
// If arr[i] > arr[i-1], then L2R[i] = L2R[i-1] + 1
// Right → Left
// If arr[i] > arr[i+1], then R2L[i] = R2L[i+1] + 1
// Final candy for each child = max(L2R[i], R2L[i])
// Why it works:
// Each pass enforces one side’s rule. max ensures both neighbors are satisfied.
// Complexity:
// Time: O(n)
// Space: O(2n)
// How to remember:
// “Handle left neighbor and right neighbor separately → two passes → take max.”
// This is the most intuitive and safest interview solution.

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>L2R(n,1);
        vector<int>R2L(n,1);
        // left to right assign 
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                L2R[i]=L2R[i-1]+1;
            }
        }
        // right to left assign 
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                R2L[i]=R2L[i+1]+1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            count+=max(L2R[i],R2L[i]);
        }
        return count;
    }
};

// 🔹 Approach 2: Single Array Optimization
// vector<int> count(n,1);
// Same logic, but reuse one array.
// Left → Right: fix left neighbor condition
// Right → Left: fix right neighbor using max
// count[i] = max(count[i], count[i-1] + 1);
// count[i] = max(count[i], count[i+1] + 1);
// Complexity:
// Time: O(n)
// Space: O(n)
// How to remember:
// “Same two-pass idea, just merge L2R and R2L into one array.”
// Tell interviewer:
// “We can reduce space by using a single array and applying both passes with max.”

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>count(n,1);
        // left to right assign 
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                count[i]=max(count[i],count[i-1]+1);
            }
        }
        // right to left assign 
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                count[i]=max(count[i],count[i+1]+1);
            }
        }
        return accumulate(count.begin(),count.end(),0);
    }
};


// 🔹 Approach 3: Greedy Slope Method (O(1) Space)
// This is the advanced one.
// Idea:
// Start with n candies (1 per child).
// Traverse and detect:
// Increasing slope → add 1, 2, 3...
// Decreasing slope → add 1, 2, 3...
// A mountain shape counts the peak twice → subtract min(peak, dip).
// candy = n;  // everyone has 1
// You simulate hills and valleys:
// Rising: 1,2,3...
// Falling: 1,2,3...
// Fix double-count at peak.
// Complexity:
// Time: O(n)
// Space: O(1)
// How to remember:
// “Think of ratings as mountains: count up on rise, count up on fall, fix the peak.”

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n=arr.size();
        int candy=n;
        int i=1;
        while(i<n){
            if(arr[i]==arr[i-1]){
                i++;
                continue;
            }
            // increasing slope -peak
            int peak=0;
            while(arr[i]>arr[i-1]){
                peak++;
                candy+=peak;
                i++;
                if(i==n)return candy;
            }
            // decreasing slope
            int dip=0;
            while(i<n && arr[i]<arr[i-1]){
                dip++;
                candy+=dip;
                i++;
            }
         candy-=min(peak,dip);
        }
        return candy;
    }
};
