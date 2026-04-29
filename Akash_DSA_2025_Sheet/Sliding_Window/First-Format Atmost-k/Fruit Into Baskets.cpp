
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxLen=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxLen=0;
        unordered_map<int,int>mp;
        int baskets=0;
        int i=0,j=0;
        while(j<n){
            if(mp[fruits[j]]==0)baskets++;
            mp[fruits[j]]++;
            while(baskets>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)baskets--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};