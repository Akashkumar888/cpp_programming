
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    unordered_set<int> s(a.begin(), a.end()); // Step 1: Insert elements of 'a' into the set

    // Step 2: Iterate over elements of 'b'
    for (int &num : b) {
        if (s.find(num) != s.end()) { // Check if the element is in the set
            ans.push_back(num);      // Add to the result
            s.erase(num);            // Remove from the set to avoid duplicates
        }
    }

    return ans;
}

int main() {
    // Input arrays
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 4, 6};

    // Find intersection
    vector<int> result = intersectionWithDuplicates(a, b);

    // Output result
    cout << "Intersection of the arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
