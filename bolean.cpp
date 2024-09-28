#include<iostream>
using namespace std;
int main(){
    bool p=false;
    bool q=false;
    bool r=true;
    cout<<(p==q)<<endl;
    cout<<(q==r)<<endl;
    cout<<(p==q==r); // left to right (p==q) then (q==r)
}