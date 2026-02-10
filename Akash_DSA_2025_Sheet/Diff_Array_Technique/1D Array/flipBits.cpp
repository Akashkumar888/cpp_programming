#include <bits/stdc++.h>
using namespace std;

vector<int> flipBits(int n, vector<pair<int, int>>& queries) {
    vector<int> diff(n + 1, 0);

    // Apply range flips using difference array
    for (auto &q : queries) {
        int l = q.first;
        int r = q.second;
        diff[l] += 1;
        if (r + 1 < n) diff[r + 1] -= 1;
    }

    // Build final array using prefix sum
    vector<int> result(n, 0);
    int runningSum = 0;
    for (int i = 0; i < n; i++) {
        runningSum += diff[i];
        result[i] = runningSum % 2; // flip if odd
    }

    return result;
}

// Example usage
int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }

    vector<int> result = flipBits(n, queries);

    for (int &bit : result) {
        cout << bit << " ";
    }

    return 0;
}





#include <bits/stdc++.h>
using namespace std;

// Function to perform range flip queries on a binary string
string toggleQuery(string str, vector<pair<int,int>>& queries)
{
    int n = str.length();
    vector<int> prefixCnt(n + 1, 0);

    // Apply range updates
    for (auto &q : queries) {
        int l = q.first;
        int r = q.second;
        prefixCnt[l] += 1;
        if (r + 1 < n)
            prefixCnt[r + 1] -= 1;
    }

    // Prefix sum
    for (int i = 1; i < n; i++) {
        prefixCnt[i] += prefixCnt[i - 1];
    }

    // Toggle characters
    for (int i = 0; i < n; i++) {
        if (prefixCnt[i] % 2) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }

    return str;
}

// Driver Code
int main()
{
    string str;
    cin >> str;

    int q;
    cin >> q;

    vector<pair<int,int>> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }

    cout << toggleQuery(str, queries);
    return 0;
}

