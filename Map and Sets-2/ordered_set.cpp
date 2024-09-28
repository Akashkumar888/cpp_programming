
#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
set<int>s;
s.insert(5);
s.insert(1);
s.insert(2);
s.insert(3);
for(auto &num:s){
    cout<<num<<" ";
}
    return 0;
}