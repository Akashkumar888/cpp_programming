
#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(4);
    s.insert(5);
    s.insert(4);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    // for(auto &it:s){
    //     cout<<it<<" ";
    // }
    // for each loop
    for(int num:s){
        cout<<num<<" ";
    }
    return 0;
}