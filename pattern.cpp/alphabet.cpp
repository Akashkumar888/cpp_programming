#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            char ch=int(64+j);
            cout<< ch<<" " ;
        }
        cout<<endl;
    }
    return 0;
}