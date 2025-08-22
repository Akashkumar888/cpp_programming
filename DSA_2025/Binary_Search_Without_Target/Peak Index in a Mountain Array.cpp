// jb bhi l or r ko mid pe le ja ya jay to while loop me while(l<r) hi rahta hai
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[mid+1]){
                r=mid;
            }
            else l=mid+1;
        }
        return r;
    }
};

