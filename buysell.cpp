#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int ans = 0;
    int minbuy = INT_MAX; // Track the minimum buying price
    
    for (int i = 0; i < n; i++) {
        minbuy = min(minbuy, prices[i]);      // Update minimum price
        ans = max(ans, prices[i] - minbuy);  // Calculate maximum profit
    }
    return ans;
}

int main() {
    // Example test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    int profit = maximumProfit(prices);
    cout << "Maximum Profit: " << profit << endl;

    return 0;
}
 