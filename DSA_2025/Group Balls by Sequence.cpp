


class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n%k)return false;
        map<int,int>mp;
        for(int &num:arr)mp[num]++;
        for (auto &it:mp){
            int start=it.first;
            int count=it.second;
            if (count>0){
                // Try to build k consecutive numbers starting from 'start'
                for(int i=0;i<k;i++){
                    int curr=start+i;
                    if(mp[curr]<count)return false;
                    mp[curr]-=count;
                }
            }
        }
        return true;
    }
};



class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n%k)return false;
        multiset<int>ms;
        for(int &num:arr)ms.insert(num);
        while(!ms.empty()){
            int start = *ms.begin();
            int cnt = 0;
            while(cnt < k){
                if(ms.find(start)==ms.end()) return false;
                else{
                    ms.erase(ms.find(start));
                    start++,cnt++;
                }
            }
        }
        
        return true;
    }
};

