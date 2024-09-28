#include<iostream>
using namespace std;
int main(){
    int a[5][5]={{0,0,0,1,1},{0,0,1,1,1},{0,0,0,0,0},{0,0,0,0,1},{0,1,1,1,1}};
    int m=5;
    int n=5;
    int row=-1;
    int maxones=0;
   
    for(int i=0;i<m;i++){
     int count=0;
    int l=0;
    int h=n-1;
    int index=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(a[i][mid]==1){
            if(mid==0){
              index=mid;
             break; 
            }
            else if(a[i][mid-1]==1) h=mid-1;
            else{
             index=mid;
             break;
            }
        }
        else if(a[i][mid]<1) l=mid+1;
        else if(a[i][mid]>1) h=mid-1;
    }
    if(index==-1) count=0;
    else count=n-index;
    cout<<count<<endl;
    if(maxones<count){
        maxones=count;
        row=i;
    }
    
    }
    cout<<endl<<row<<" "<<maxones;
    return 0; 
}