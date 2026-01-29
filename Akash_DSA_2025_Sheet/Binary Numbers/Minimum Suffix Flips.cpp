
class Solution {
public:
    int minFlips(string target) {
        int n=target.size();
       // 1 ko 0 banana target hai start to end tk 
       int times=0;
       for(int i=0;i<n;i++){
        if((target[i]=='1' && times%2==0) || (target[i]=='0' && times%2==1))times++;
       }
       return times;
    }
};

