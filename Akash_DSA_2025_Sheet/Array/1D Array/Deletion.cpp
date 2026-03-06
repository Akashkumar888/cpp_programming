
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int user_logic(int N, int K) {
    vector<int> arr;
    
    // Initialize arr with 1 to N
    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
    }

    // Perform K operations
    for (int op = 0; op < K; op++) {
        if (arr.empty()) break;

        vector<int> new_arr;

        for (int i = 0; i < arr.size(); i++) {
            // Remove elements at positions 1,4,7,... (1-based)
            // In 0-based indexing: remove when i % 3 == 0
            if (i % 3 != 0) {
                new_arr.push_back(arr[i]);
            }
        }

        arr = new_arr;
    }

    // Compute sum modulo MOD
    long long sum = 0;
    for (int num : arr) {
        sum = (sum + num) % MOD;
    }

    return sum;
}

int main() {
    int N, K;
    cin >> N >> K;
    int result = user_logic(N, K);
    cout << result << endl;
    return 0;
}