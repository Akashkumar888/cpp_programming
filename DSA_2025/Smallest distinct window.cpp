
class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n=str.size();
        int k=0;
        vector<int>mp(26,0);
        for(auto &ch:str){
        if(mp[ch-'a']==0)k++;    
        mp[ch-'a']++;
        }
        fill(mp.begin(), mp.end(), 0);
        int i=0,j=0;
        int cnt=0;
        int minlen=INT_MAX;
        while(j<n){
           if(mp[str[j]-'a']==0)cnt++;
           mp[str[j]-'a']++;
           while(k==cnt){
               minlen=min(minlen,j-i+1);
               mp[str[i]-'a']--;
               if(mp[str[i]-'a']==0)cnt--;
               i++;
           }
           j++;
        }
        return minlen;
    }
  };
  