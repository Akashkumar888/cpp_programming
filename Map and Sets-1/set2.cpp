

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
    int tr=4;
    // element exist or not in set 
    if(s.find(tr)!=s.end()){
        
    }
    // for each loop // range based loop
    for(int num:s){
        cout<<num<<" ";
    }
    return 0;
}