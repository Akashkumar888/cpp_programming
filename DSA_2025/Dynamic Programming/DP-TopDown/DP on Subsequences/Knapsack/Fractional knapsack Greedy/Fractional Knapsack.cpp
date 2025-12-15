
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
         // pair: {value/weight ratio, index}
        vector<pair<double, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({(double)val[i] / wt[i], i});// mujhe max value chahiye
        }
        
        // sort by ratio descending
        sort(vec.begin(), vec.end(), greater<>());
        
        double totalValue = 0.0;
        
        for (int i = 0; i < n && capacity > 0; i++) {
            int idx = vec[i].second;
            if (wt[idx] <= capacity) {
                totalValue += val[idx];
                capacity -= wt[idx];
            } 
            else {
                totalValue += (double)capacity / wt[idx] * val[idx];
                capacity = 0;
            }
        }
        return totalValue;
    }
};
