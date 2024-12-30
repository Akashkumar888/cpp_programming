
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findUnion(vector<int>& a, vector<int>& b) {
    unordered_set<int> s(a.begin(), a.end()); // Insert elements of array a
    for (int &num : b) {
        s.insert(num); // Insert elements of array b
    }
    return s.size(); // Return the size of the set
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {3, 4, 5, 6};
    cout << "Union size: " << findUnion(a, b) << endl;
    return 0;
}
