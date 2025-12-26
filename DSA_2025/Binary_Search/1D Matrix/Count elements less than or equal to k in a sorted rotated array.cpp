class Solution {
    public:
    int partition(int n,vector<int>&arr){
        int l=0,r=n-1;
        //arr[] containing distinct positive integers
        while(l<r){// jb target na pta ho tb 
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[r]){
                l=mid+1; // always remembers
            }
            else r=mid;// else me rahega
        }
        return r;
    }
    int binarySearch(int l,int r,vector<int>&arr,int tr){
        int idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]<=tr){
                idx=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return idx;
    }
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int idx=partition(n,arr);
        int count=0;
        // left part
        int left=binarySearch(0,idx-1,arr,x);
        if (left != -1)count+=left+1;// like j-i+1 but i=0 here left-0+1

        // right part
        int right=binarySearch(idx,n-1,arr,x);
        if (right!=-1)count+=right-idx+1;// like j-i+1 
        return count;
    }
};            