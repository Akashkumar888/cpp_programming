
class Solution {
  public:
  // -10^7 ≤ arr[i], k ≤ 10^7 dp nhi lagega 
  int solve(int i,vector<int>&ans,vector<int>&arr,int tr){
      if(i<0){
          if(accumulate(ans.begin(),ans.end(),0)==tr)return 1;
          return 0;
      }
      int count=0;
      ans.push_back(arr[i]);// pick
      count+=solve(i-1,ans,arr,tr);// explore
      ans.pop_back();// notpick
      count+=solve(i-1,ans,arr,tr);
      return count;
  }
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans;
        return solve(n-1,ans,arr,k);
    }
};
// i got tle 

class Solution {
  public:
  // -10^7 ≤ arr[i], k ≤ 10^7 dp nhi lagega 
  int solve(int i,int sum,vector<int>&arr,int tr){
      if(i<0){
          if(sum==tr)return 1;
          return 0;
      }
      int count=0;
      // pick
      count+=solve(i-1,sum+arr[i],arr,tr);
      // notpick
      count+=solve(i-1,sum,arr,tr);
      
      return count;
  }
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        return solve(n-1,0,arr,k);
    }
};
// i got tle. 