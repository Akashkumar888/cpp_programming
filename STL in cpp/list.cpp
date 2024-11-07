#include<iostream>
#include<list>
using namespace std;
int main(){

    list<int>l;
    l.push_back(8);
    l.push_front(56);
    l.push_back(85);
    l.push_back(45);
    l.push_back(545);
    for(int i:l){
        cout<<i<<"  ";
    }
    cout<<endl;
    cout<<"Before erase size :"<<l.size()<<endl;
    l.erase(l.begin());
    cout<<"After  erase size  :"<<l.size()<<endl;
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.pop_back();
    l.pop_front();
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}