
class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>freq(26,0);
        for(char &ch:s)freq[ch-'a']++;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],char(i+'a')});
            }
        }
        int count=0;
        while(!pq.empty() && count<k){
            int f=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            f--; // remove 1 occurrence
            k--; // count 1 removal
            if(f!=0)pq.push({f,ch});
        }
        int sum=0;
        while(!pq.empty()){
            int f=pq.top().first;
            pq.pop();
            sum+=(f*f);
        }
        return sum;
    }
};

