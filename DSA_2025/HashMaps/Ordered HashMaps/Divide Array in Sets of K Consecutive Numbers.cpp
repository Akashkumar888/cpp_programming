
class Solution {
public:
    bool isPossibleDivide(vector<int>& arr, int k) {
        int n=arr.size();
        if(n%k)return false; // check whether it is possible to divide this array into sets of k consecutive numbers.
        map<int,int>mp;
        for(int &num:arr)mp[num]++;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int start = it->first;
            int count = it->second;

            if (count > 0) {
                // Try to build k consecutive numbers starting from 'start'
                for (int i = 0; i < k; i++) {
                    int curr = start + i;
                    if (mp[curr] < count)
                        return false;
                    mp[curr] -= count;
                }
            }
        }
        return true;
    }
};

