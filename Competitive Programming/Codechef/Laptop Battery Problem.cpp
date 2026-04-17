🧾 Problem Description
An integer levels representing the minimum battery charge required for a laptop to work.
A list of battery charges of laptops.
⚠️ Constraints
Number of laptops is fixed to 1000
So we take:
int n = 1000;
vector<int> arr(n, 0);
🎯 Task
Count how many laptops have battery charge greater than or equal to levels.
📥 Input Format
First input: integer levels
Next: 1000 integers representing battery levels
📤 Output Format
Print a single integer → number of laptops that can work
💡 Logic
Traverse all 1000 values
Check:
if(arr[i] >= levels) → count++

  
#include <bits/stdc++.h>
using namespace std;

int main() {
    int levels;
    cin >> levels;

    int n = 1000;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= levels) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
