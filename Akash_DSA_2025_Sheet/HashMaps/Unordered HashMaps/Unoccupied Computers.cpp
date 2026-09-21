
class Solution {
  public:
    int solve(int n, string s) {
        // 0 = customer has not arrived
        // 1 = customer has a computer
        // 2 = customer was rejected
        vector<int> mp(26, 0);
        // Number of available computers
        int total = n;
        // Number of rejected customers
        int count = 0;
        for(char &ch : s){
            int idx = ch - 'A';
            // ------------------------------------------------
            // First occurrence
            // Customer ARRIVES
            // ------------------------------------------------
            if(mp[idx] == 0){
                if(total > 0){
                    // Computer available
                    total--;
                    mp[idx] = 1;
                }
                else{
                    // No computer available
                    count++;
                    mp[idx] = 2;
                }
            }
            // ------------------------------------------------
            // Second occurrence
            // ------------------------------------------------
            else if(mp[idx] == 1){
                // Customer had a computer,
                // so now they leave.
                total++;
                mp[idx] = 0;
            }
            else{
                // Customer was rejected earlier.
                // They never occupied a computer.
                mp[idx] = 0;
            }
        }
        return count;
    }
};