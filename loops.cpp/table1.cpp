#include<iostream>
using namespace std;
int main(){
    int n,table;
    cout<<"Enter the number: ";
    cin>>n;
    for(int i=1;i<=10;i++){
        for(int j=2;j<=n;j++){
            table=i*j;
            cout<<table<<"\t";
        }
        cout<<endl;
    }
    return 0;
}