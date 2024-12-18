
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> nse(n, 0); // Vector to store next smaller element
        stack<int> st;

        // Initialize for the last element
        nse[n - 1] = 0;
        st.push(prices[n - 1]);

        // Calculate the next smaller element for each price
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && prices[i] < st.top()) {
                st.pop();
            }
            if (st.empty()) nse[i] = 0;
            else nse[i] = st.top();
            st.push(prices[i]);
        }

        // Update prices by subtracting the next smaller element
        for (int i = 0; i < n; i++) {
            prices[i] = prices[i] - nse[i];
        }
        return prices;
    }
};

int main() {
    // Input handling
    int n;
    cout << "Enter the number of prices: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution obj;
    vector<int> result = obj.finalPrices(prices);

    cout << "Final discounted prices: ";
    for (int price : result) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}
