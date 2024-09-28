
#include <iostream>
#include <vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int main() {
    vector<int> arr = {1, 2, 3, 4, 56};
    // Insert 45 at the 0th index
    arr.insert(arr.begin()+0 , 45);
    arr.insert(arr.end(),89);
    arr.insert(arr.begin()+2, 67);
    arr.erase(arr.begin()+0); 
    arr.erase(arr.begin()+3); 
    // Print the vector to see the result
    for (int i : arr) {
        std::cout << i << " ";
    }
    cout<<endl;
    // unordered_set<int>st={5,4,6,8,9};
    // st.insert(st.begin(),78);
    // st.insert(st.end(),68);
    // for(auto &it:st){
    //     cout<<it<<" ";
    // }
    return 0;
}

