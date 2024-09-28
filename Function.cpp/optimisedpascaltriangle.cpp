#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    for(int i=0;i<=n;i++){
        int prev=1;
        for(int j=0;j<=i;j++){
            cout<<prev<<" ";
        prev=prev*(i-j)/(j+1);
        }
        cout<<endl;
    }
    return 0;
}