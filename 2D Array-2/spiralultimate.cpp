#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter first matrix rows: ";
    cin>>m;
    int n;
    cout<<"Enter first matrix column: ";
    cin>>n;
    int arr[m][n];
        cout<<"Enter elements of first matrix:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
int minr=0,minc=0;
int maxr=m-1,maxc=n-1;
int tne=m*n;
int count=0;
while(minr<=maxr && minc<=maxc ){
for(int j=minc;j<=maxc && count<tne;j++){
    cout<<arr[minr][j]<<" ";
    count++;
}
minr++;

for(int i=minr;i<=maxr && count<tne;i++){
    cout<<arr[i][maxc]<<" ";
     count++;
}
maxc--;

for(int j=maxc;j>=minc && count<tne;j--){
    cout<<arr[maxr][j]<<" ";
     count++;
}
maxr--;

for(int i=maxr;i>=minr && count<tne;i--){
    cout<<arr[i][minc]<<" ";
     count++;
}
minc++;
}
    return 0;
}