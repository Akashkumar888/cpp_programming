#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int profit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main() {
    // Example input
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};

    // Call the function
    int result = maximumProfit(prices);

    // Output the result
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
