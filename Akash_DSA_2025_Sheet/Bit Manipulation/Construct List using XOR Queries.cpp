
class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        int q=queries.size();
        vector<int>result;
        int curXor=0;
        for(int i=q-1;i>=0;i--){
            int u=queries[i][0];
            int v=queries[i][1];
            if(u==0){
                result.push_back(curXor^v);
            }
            else if(u==1){
                curXor=(curXor^v);
            }
        }
        result.push_back(curXor);
        sort(result.begin(),result.end());
        return result;
    }
};


class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {

        int q = queries.size();

        vector<int> result;

        // stores XOR of all future type-1 queries
        int curXor = 0;

        // process from back because future XORs
        // affect previously inserted elements
        for(int i = q - 1; i >= 0; i--) {

            int type = queries[i][0];
            int val  = queries[i][1];

            // insertion query
            if(type == 0) {

                // final value after all future XOR updates
                result.push_back(val ^ curXor);
            }

            // XOR query
            else {

                // accumulate future XOR operations
                curXor ^= val;
            }
        }

        // initial array contains 0
        result.push_back(curXor);

        sort(result.begin(), result.end());

        return result;
    }
};