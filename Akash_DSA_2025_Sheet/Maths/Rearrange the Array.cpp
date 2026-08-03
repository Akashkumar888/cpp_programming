
class Solution {
  public:
    const int MOD = 1e9 + 7;
    long long power(long long a,long long b){
        long long ans = 1;
        while(b){
            if(b & 1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<bool> vis(n,false);
        unordered_map<int,int> mp;

        // Find cycle lengths
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int cnt = 0;
            int node = i;
            while(!vis[node]){
                vis[node] = true;
                node = b[node] - 1;
                cnt++;
            }
            // Prime factorization of cycle length
            int x = cnt;

            for(int p=2;p*p<=x;p++){
                if(x % p == 0){
                    int freq = 0;
                    while(x % p == 0){
                        x /= p;
                        freq++;
                    }
                    mp[p] = max(mp[p],freq);
                }
            }
            if(x > 1){
                mp[x] = max(mp[x],1);
            }
        }
        long long ans = 1;
        // LCM = product(prime^maximum exponent)
        for(auto &it : mp){
            ans = (ans * power(it.first,it.second)) % MOD;
        }
        return ans;
    }
};