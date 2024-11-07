#include<iostream>
#include<deque>
using namespace std;
int main(){
deque<int>d;
d.push_front(84);
d.push_front(34);
d.push_back(67);
d.push_back(89);
d.push_back(122);
for(int i:d){
    cout<<i<<" ";
}
cout<<endl;
d.pop_back();
for(int i:d){
    cout<<i<<" ";
}
cout<<endl;
d.pop_front();
for(int i:d){
    cout<<i<<" ";
}
    return 0;
}