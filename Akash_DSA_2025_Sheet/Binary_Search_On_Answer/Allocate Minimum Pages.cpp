class Solution {
  public:
   // binary search on answer hai 
  bool isPossible(vector<int>&arr,int mid,int k){
      int count=1;
      int sum=0;
      for(int &num:arr){
          sum+=num;
          if(sum>mid){
              count++;
              sum=num;
          }
          if(count>k)return false;
      }
      return true;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        // Each student is assigned a contiguous sequence of books. that's why not sort array
        int n=arr.size();
        if(n<k)return -1;
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int minPages=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(arr,mid,k)){
            // minimize the maximum number of pages
                minPages=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return minPages;
    }
};


#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int W, int mid) {
    int sum = 0;
    int count = 1;

    for(int i = 0; i < n; i++) {

        if(arr[i] > mid)
            return false;

        if(sum + arr[i] > mid) {
            count++;
            sum = arr[i];

            if(count > W)
                return false;
        }
        else {
            sum += arr[i];
        }
    }

    return true;
}

int user_logic(int n, vector<int> tasks, int W) {

    if(W > n) return -1;

    int l = *max_element(tasks.begin(), tasks.end());
    int r = accumulate(tasks.begin(), tasks.end(), 0);
    int ans = r;

    while(l <= r) {
        int mid = l + (r - l) / 2;

        if(isPossible(tasks, n, W, mid)) {
            ans = mid;
            r = mid - 1;   // minimize maximum
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}


int main() {
    int n;
    std::cin >> n;  // First input is the integer n
    std::vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tasks[i];  // Next n inputs are the tasks array
    }
    int W;
    std::cin >> W;  // The last input is the number of workers

    // Call user logic function and print the output
    int result = user_logic(n, tasks, W);
    std::cout << result << std::endl;
    return 0;
}