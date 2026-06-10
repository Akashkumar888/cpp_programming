



class Solution {
  public:
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
            int left=lower_bound(positions.begin(),positions.end(),l)-positions.begin();
            int right=upper_bound(positions.begin(),positions.end(),r)-positions.begin();
            result.push_back(right-left);
        }
        return result;
    }
};