
class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        unordered_set<int>st(arr.begin(),arr.end());
        for(int i=start;i<=end;i++){
            if(st.find(i)==st.end())return false;
        }
        return true;
    }
};

class Solution {
  public:
    bool checkElements(int start,
                       int end,
                       vector<int> &arr) {

        vector<bool>present(100001,false);

        for(auto &num : arr){
            present[num]=true;
        }

        for(int i=start;i<=end;i++){

            if(!present[i]){
                return false;
            }
        }

        return true;
    }
};


class Solution {
  public:

    bool binarySearch(vector<int>&arr,
                      int target){

        int l=0;
        int r=arr.size()-1;

        while(l<=r){

            int mid=l+(r-l)/2;

            if(arr[mid]==target){
                return true;
            }

            if(arr[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return false;
    }

    bool checkElements(int start,
                       int end,
                       vector<int> &arr) {

        sort(arr.begin(),arr.end());

        for(int i=start;i<=end;i++){

            if(!binarySearch(arr,i)){
                return false;
            }
        }

        return true;
    }
};


class Solution {
  public:
    bool checkElements(int start,
                       int end,
                       vector<int> &arr) {

        sort(arr.begin(),arr.end());

        int need=start;

        for(auto &num : arr){

            if(num==need){
                need++;
            }

            if(need>end){
                return true;
            }
        }

        return false;
    }
};
