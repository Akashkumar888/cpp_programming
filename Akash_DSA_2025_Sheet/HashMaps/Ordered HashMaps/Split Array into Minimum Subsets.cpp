
class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int prev=arr[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(prev+1!=arr[i])count++;
            prev=arr[i];
        }
        return count;
    }
};




class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        map<int,int> mp;
        for(int &num : arr) mp[num]++;
        auto it = mp.begin();
        int prev = it->first;
        it++;
        int count = 1;
        for(; it != mp.end(); it++) {
            if(prev + 1 != it->first)count++;
            prev = it->first;
        }
        return count;
    }
};



class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        map<int,int> mp;
        for(int &num : arr) mp[num]++;
        auto it = mp.begin();
        int prev = it->first;
        it++;
        int count = 1;
        while(it != mp.end()) {
            if(prev + 1 != it->first)count++;
            prev = it->first;
            it++;
        }
        return count;
    }
};