
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)return {};
        vector<int>result=arr;
        sort(result.begin(),result.end());
        vector<int>rank(n);
        unordered_map<int,int>mp;
        int temp=1;
        mp[result[0]]=temp;
        for(int i=1;i<n;i++){
            if(result[i-1]!=result[i]){
                mp[result[i]]=++temp;
            }
            else mp[result[i]]=temp;
        }
        for(int i=0;i<n;i++){
            rank[i]=mp[arr[i]];
        }
        return rank;
    }
};