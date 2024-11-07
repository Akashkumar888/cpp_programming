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
cout<<"Element at first index :"<<d.at(1)<<endl;
cout<<"Element at forth index :"<<d.at(4)<<endl;
cout<<"First  element :"<<d.front()<<endl;
cout<<"last   element :"<<d.back()<<endl;

cout<<"Empty or not :"<<d.empty()<<endl;
cout<<"Before erase size:"<<d.size()<<endl;
d.erase(d.begin(),d.begin()+1);
cout<<"After erase size:"<<d.size()<<endl;
for(int i:d){
    cout<<i<<endl;
}
    return 0;
}