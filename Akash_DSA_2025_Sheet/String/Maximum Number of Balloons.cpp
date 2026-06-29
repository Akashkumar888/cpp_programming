
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>mp(26,0);
        for(char &ch:text)mp[ch-'a']++;
        if(mp['a'-'a']>=1 && mp['b'-'a']>=1 && mp['l'-'a']>=2 && mp['o'-'a']>=2 && mp['n'-'a']>=1){
            return min({mp['a'-'a'] , mp['b'-'a'] , mp['l'-'a']/2 , mp['o'-'a']/2 , mp['n'-'a']});
        }
        return 0;
    }
};