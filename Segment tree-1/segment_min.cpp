
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>seg;
void build_tree(int arr[],int i,int lo,int hi){
    if(lo==hi){
    seg[i]=arr[lo];
    return;
    } 
    int mid=lo+(hi-lo)/2;
    build_tree(arr,2*i+1,lo,mid);
    build_tree(arr,2*i+2,mid+1,hi);
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
}
int getMin(int i,int lo,int hi,int &l,int &r){
if(r<lo || l>hi) return INT_MAX;
if(l<=lo && hi<=r) return seg[i];
int mid=lo+(hi-lo)/2;

int leftMax=getMin(2*i+1,lo,mid,l,r);
int rightMax=getMin(2*i+2,mid+1,hi,l,r);
return min(leftMax,rightMax);
}
int main()
{
int arr[]={1,4,2,8,6,4,9,3};
int n=sizeof(arr)/sizeof(arr[0]);
seg.resize(4*n);
build_tree(arr,0,0,n-1);
int q;
cin>>q;
while(q--){
int l,r;
cout<<endl<<"Enter range of Segment tree:"<<endl;
cin>>l>>r;
cout<<getMin(0,0,n-1,l,r)<<endl;
}
return 0;
}
