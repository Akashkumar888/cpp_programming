#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
            bool flag = true;
    for(int i=2;i<n;i++){
        if(n%i==0){
            flag=false;
            break;
        }
    }
    if(n==1) cout<<"Neither prime nor composite";
   else if(flag==true){
        cout<<"Prime number"<<endl;
    }
    else{
        cout<<"Composite number"<<endl;
    }
    return 0;
}