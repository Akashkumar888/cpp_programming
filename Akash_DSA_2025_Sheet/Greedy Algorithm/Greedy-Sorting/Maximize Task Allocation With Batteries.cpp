
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximizeTasks(vector<int>& energy, vector<int>& power);

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }

    vector<int> power(m);
    for (int i = 0; i < m; i++) {
        cin >> power[i];
    }

    int maxTasks = maximizeTasks(energy, power);
    cout << maxTasks << endl;

    return 0;
}

int maximizeTasks(vector<int>& energy, vector<int>& power) {
    // User will write the logic here
    // Sort both arrays
    sort(energy.begin(), energy.end());
    sort(power.begin(), power.end());
    
    int i = 0, j = 0;
    int count = 0;
    
    // Two pointer approach
    while (i < energy.size() && j < power.size()) {
        if (power[j] >= energy[i]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    
    return count;
}
