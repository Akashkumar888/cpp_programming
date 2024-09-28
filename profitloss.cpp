#include<iostream>
using namespace std;
int main(){
    int cp,sp;
    cout<<"Enter cost price: ";
    cin>>cp;
    cout<<"Enter selling price: ";
    cin>>sp;
    if(sp>cp){
        cout<<"Profit money is = "<<sp-cp<<endl;
    }
    if(sp==cp){
        cout<<"Not profit not loss is = "<<sp-cp<<endl;
    }
    if(sp<cp){
        cout<<"Loss money is = "<<cp-sp<<endl;
    }
    return 0;
} 