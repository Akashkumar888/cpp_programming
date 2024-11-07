#include <bits/stdc++.h>
using namespace std; 
int main()
{
    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 4, 5, 6 };
    for (int i = 0; i < 3; i++) {
        swap(v1[i], v2[i]);
    }
    cout << "Vector v1 = ";
    for (int i = 0; i < 3; i++) {
        cout << v1[i] << " ";
    }
    cout << "\nVector v2 = ";
    // for (int i = 0; i < 3; i++) {
    //     cout << v2[i] << " ";
    // }
    for(auto i:v2){
        cout<<i<<" ";
    }
    return 0;
}