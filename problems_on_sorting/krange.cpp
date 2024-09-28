#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
float max(float a,float b){
    if(a>=b) return a;
    else return b;
}
float min(float a,float b){
    if(a<b) return a;
    else return b;
}
int main(){
int a[]={5,3,10,3};
int n=sizeof(a)/4;
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
float Kmin=(float)(INT_MIN);
float Kmax=(float)(INT_MAX);
bool flag=true;
for(int i=0;i<n-1;i++){
    if(a[i]>=a[i+1]){
        Kmin = max(Kmin,(a[i]+a[i+1])/2.0 );
    }
    else{
        Kmax = min(Kmax,(a[i]+a[i+1])/2.0);
    }
    if(Kmax<Kmin){
    flag=false;
    break;
    } 
}
if(flag==false) cout<<-1;
else if(Kmin==Kmax){
    if(Kmin-(int)Kmin==0){
        cout<<Kmin;
    }
    else cout<<-1;
}
else{
    if(Kmin-(int)Kmin>0){
        Kmin=(int)Kmin+1;
    }
    cout<<"Range of k is: ["<<Kmin<<","<<(int)Kmax<<"]";
}
    return 0;
}