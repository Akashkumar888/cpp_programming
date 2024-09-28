#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    return 0;
}

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     pq.push(nums[i]);
        // }
        while(k--){
            int val=pq.top();
            pq.pop();
            pq.push(-val);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};