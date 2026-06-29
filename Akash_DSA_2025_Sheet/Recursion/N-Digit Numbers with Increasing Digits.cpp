
class Solution {
  public:
    void solve(int len, int num, int start, int n, vector<int>& result){
        if(len == n){
            result.push_back(num);
            return;
        }

        for(int d = start; d <= 9; d++){
            solve(len + 1,num * 10 + d,d + 1,n,result);
        }
    }
    vector<int> increasingNumbers(int n) {
        vector<int> result;
        if(n == 1){
            for(int i = 0; i <= 9; i++){
                result.push_back(i);
            }
            return result;
        }
        if(n > 9) return {};
        
        solve(0, 0, 1, n, result);
        return result;
    }
};