
class Solution {
  public:
    int lowerBound(vector<int> &lis, int x){
        int n=lis.size();
        int low = 0;
        int high = n - 1;
        int idx = n;
        while(low <= high){

            int mid = low + (high - low) / 2;

            if(lis[mid] >= x){
                idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return idx;
    }
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n=a.size();
        int m=b.size();
        unordered_map<int,int> mp;
        // Store index of every element in b
        for(int i = 0; i < b.size(); i++){
            mp[b[i]] = i;
        }
        vector<int> arr;
        // Convert a into indices of b
        for(int &x : a){
            if(mp.find(x)!=mp.end()){
                arr.push_back(mp[x]);
            }
        }
        vector<int> lis;
        for(int x : arr){
            int idx = lowerBound(lis, x);
            if(idx == lis.size()){
                lis.push_back(x);
            }
            else{
                lis[idx] = x;
            }
        }
        int lcs = lis.size();
        return (n - lcs) + (m - lcs);
    }
};