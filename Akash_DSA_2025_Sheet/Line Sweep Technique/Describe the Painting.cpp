
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>>result;
        map<long long,long long>mp;
        for(auto &seg:segments){
            long long start=seg[0];
            long long end=seg[1];//represents the half-closed segment [starti, endi) with colori as the color.
            long long color=seg[2];
            mp[start]+=color;
            mp[end]-=color;
        }
        // for(auto &it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        long long sum=0;
        long long start=-1;
        long long end=-1;
        long long count=0;
        for(auto &it:mp){
            if(count==0)start=it.first;
            count++;
            if(count>1){
                end=it.first;
                if(sum!=0)result.push_back({start,end,sum});
                start=end;
            }
            sum+=it.second;
        }
        return result;
    }
};



class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> result;
        map<long long, long long> mp;

        // build difference map
        for (auto &seg : segments) {
            long long start = seg[0];
            long long end   = seg[1];
            long long color = seg[2];

            mp[start] += color;
            mp[end]   -= color;
        }

        long long sum = 0;
        
        if (mp.empty()) return result;
        auto it = mp.begin();
        long long start = it->first;

        // apply first event
        sum += it->second;
        it++;

        // sweep remaining points
        while (it != mp.end()) {
            long long end = it->first;
            if (sum != 0)result.push_back({start, end, sum});
            sum += it->second;
            start = end;
            it++;
        }
        return result;
    }
};



class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> result;
        map<long long, long long> mp;
        for (auto& seg : segments) {
            long long start = seg[0];
            long long end = seg[1]; // represents the half-closed segment
                                    // [starti, endi) with colori as the color.
            long long color = seg[2];
            mp[start] += color;
            mp[end] -= color;
        }
        // for(auto &it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        long long sum = 0;
        long long start = -1;
        long long end = -1;
        long long count = 0;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (count == 0) {
                start = it->first;
            } 
            else {
                end = it->first;
                if (sum != 0) {
                    result.push_back({start, end, sum});
                }
                start = end;
            }

            sum += it->second; // apply event AFTER closing previous segment
            count++;
        }

        return result;
    }
};