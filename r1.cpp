
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 3;
    vector<string> merge[n];

    merge[0].push_back("apple");
    merge[1].push_back("banana");
    merge[2].push_back("cherry");

    for (int i = 0; i < n; i++) {
        for (const string& str : merge[i]) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
