

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize)return false;//  wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
        map<int,int>mp;
        for(int &num:hand)mp[num]++;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int start = it->first;
            int count = it->second;

            if (count > 0) {
                // Try to build groupSize consecutive numbers starting from 'start'
                for (int i = 0; i < groupSize; i++) {
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
