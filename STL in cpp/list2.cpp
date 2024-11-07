#include<iostream>
#include<list>
using namespace std;
int main(){

    list<int>l;
    list<int>n(5,100);
    cout<<"printing n"<<endl;
    for(int i:n){
        cout<<i<<"  ";
    }
    cout<<endl;
    l.push_back(8);
    l.push_front(56);
    l.push_back(85);
    l.push_back(45);
    l.push_back(545);
    cout<<"Printing element"<<endl;
    for(int i:l){
        cout<<i<<"  ";
    }
    cout<<endl;
    
    return 0;
}