
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto &num:arr)mp[num*num]++;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
            if(mp.find(arr[i]*arr[i]+arr[j]*arr[j])!=mp.end())return true;
            }
        }
        return false;
    }
};



class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto &num:arr)mp[num*num]++;
        for(int i=0;i<n-1;i++){
            int a=arr[i];
            for(int j=i+1;j<n;j++){
                int b=arr[j];
            if(mp.find(a*a+b*b)!=mp.end())return true;
            }
        }
        return false;
    }
};

