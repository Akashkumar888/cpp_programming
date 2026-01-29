
// User function Template for C++

class Solution {
  public:
    bool valid(vector<int>&arr,int mid,int k){
        int n=arr.size();
        int cnt=1,prev=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-prev>=mid){
                prev=arr[i];
                cnt++;
                if(cnt>=k)return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // Write your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int l=0,r=arr[n-1]-arr[0];
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(valid(arr,mid,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};