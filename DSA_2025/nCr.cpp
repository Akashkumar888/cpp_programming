
class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(n<r )return 0;
        if(r==0 || n==r)return 1;
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans*=(n-i+1);
            ans/=i;
        }
        return (int)ans;
    }
  };
  