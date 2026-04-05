🧾 Problem Description
An integer n = 1000 representing number of people initially happy
Number of iterations t = 4
🟢 Initial State
Happy = 1000
Sad = 0
🔁 Transition Rules (Each Iteration)
70% of happy → become sad
30% of happy → remain happy
50% of sad → remain sad
50% of sad → become happy
🎯 Task
Simulate for t = 4 iterations
Print final values:
Happy Sad
⚠️ Important Requirement
Output must be integer values
Final expected:
412 582
💡 Logic (Integer Based)
At each iteration:
new_happy = (30% of happy) + (50% of sad)
new_sad   = (70% of happy) + (50% of sad)
Convert percentages into integer math:
new_happy = (30 * happy) / 100 + (50 * sad) / 100
new_sad   = (70 * happy) / 100 + (50 * sad) / 100

  
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1000;
    int t = 4;

    int happy = n;
    int sad = 0;

    while (t--) {
        int new_happy = (30 * happy) / 100 + (50 * sad) / 100;
        int new_sad   = (70 * happy) / 100 + (50 * sad) / 100;

        happy = new_happy;
        sad = new_sad;
    }

    cout << happy << " " << sad << endl;

    return 0;
}
