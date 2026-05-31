
class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_map<long long,long long> mp;
        for(auto &num:arr){
            mp[num]++;
        }
        for(auto &num:arr){
            // target = 0 case
            if(target==0){
                if(num==0 && arr.size()>=2){
                    return true;
                }
                if(num!=0 && mp.find(0)!=mp.end()){
                    return true;
                }
            }
            else{
                if(num==0) continue;
                if(target%num!=0) continue;
                long long need=target/num;
                if(need==num){
                    if(mp[need]>=2)return true;
                }
                else{
                    if(mp.find(need)!=mp.end())return true;
                }
            }
        }
        return false;
    }
};

class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> st;
        for(auto &num:arr){
            // handle zero separately
            if(num==0){
                if(target==0)return true;
                continue;
            }
            if(target%num==0){
                long long need=target/num;
                if(st.find(need)!=st.end())return true;
            }
            st.insert(num);
        }
        return false;
    }
};