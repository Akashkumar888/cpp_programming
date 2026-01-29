
class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int>ans;
        vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        // cost sqrt > i*i ok 
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(isPrime[i]==true)ans.push_back(i);
        }
        return ans;
    }
};