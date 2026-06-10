class Solution {
  public:
    int lowerbound(vector<int>&arr,int x){
        int l=0,r=arr.size()-1;
        int ans=arr.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>=x){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>&arr,int x){
        int l=0,r=arr.size()-1;
        int ans=arr.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>x){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> freqInRange(vector<int>& arr,vector<vector<int>>& queries) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        // store indices of every element
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>result;
        for(auto &que:queries){
            int l=que[0];
            int r=que[1];
            int ele=que[2];
            if(mp.find(ele)==mp.end()){
                result.push_back(0);
                continue;
            }
            vector<int>&positions=mp[ele];
            int left=lowerbound(positions,l);
            int right=upperbound(positions,r);
            result.push_back(right-left);
        }
        return result;
    }
};




class Solution {
public:
int lowerbound(vector<int> arr, int x){
      int l=0,r=arr.size()-1;
      int first=-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]==x){
              first=mid;
              r=mid-1;
          }
          else if(arr[mid]<x)l=mid+1;
          else if(arr[mid]>x)r=mid-1;
      }
      return first;
  }
  int upperbound(vector<int> arr, int x){
      int l=0,r=arr.size()-1;
      int last=-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]==x){
              last=mid;
              l=mid+1;
          }
          else if(arr[mid]<x)l=mid+1;
          else if(arr[mid]>x)r=mid-1;
      }
      return last;
  }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowerbound(nums,target);
        int last=upperbound(nums,target);
        return {first,last};
    }
};
