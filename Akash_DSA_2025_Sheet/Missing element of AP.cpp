

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size();
        int d=min(arr[1]-arr[0],arr[n-1]-arr[n-2]);
        for(int i=0;i<n-1;i++){
            if(arr[i]+d!=arr[i+1])return arr[i]+d;
        }
        return arr[n-1]+d;
    }
};


class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size();
        int d=min(arr[1]-arr[0],arr[n-1]-arr[n-2]);  // Safe difference
        int l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int expected =arr[0]+mid*d;
            if (arr[mid]==expected){
                l=mid+1;
            } 
            else{
                r= mid-1;
            }
        }
        return arr[0]+l*d;
    }
  };
  
