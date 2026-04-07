class Solution {
public:
    void solve(vector<vector<int>> &men, vector<vector<int>> &women, vector<int> &result) {
        int n = men.size();
        vector<int> womanPartner(n, -1);   
        vector<int> manPartner(n, -1);     
        vector<int> nextProposal(n, 0);    

        vector<vector<int>> womenRank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                womenRank[w][women[w][i]] = i;
            }
        }
        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }
        while (!freeMen.empty()) {
            int man = freeMen.front();
            freeMen.pop();
            int woman = men[man][nextProposal[man]];
            nextProposal[man]++;

            if (womanPartner[woman] == -1) {
                womanPartner[woman] = man;
                manPartner[man] = woman;
            } 
            else {
                int currentMan = womanPartner[woman];
                if (womenRank[woman][man] < womenRank[woman][currentMan]) {
                    womanPartner[woman] = man;
                    manPartner[man] = woman;
                    manPartner[currentMan] = -1;
                    freeMen.push(currentMan);
                } 
                else {
                    freeMen.push(man);
                }
            }
        }
        result = manPartner;
    }
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        vector<int> result;
        solve(men, women, result);
        return result;
    }
};
