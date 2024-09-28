
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>seg;
vector<int>lazy;
void build_tree(int arr[],int i,int lo,int hi){
    if(lo==hi){
    seg[i]=arr[lo];
    return;
    } 
    int mid=lo+(hi-lo)/2;
    build_tree(arr,2*i+1,lo,mid);
    build_tree(arr,2*i+2,mid+1,hi);
    seg[i]=(seg[2*i+1]+seg[2*i+2]);
}
int getSum(int i,int lo,int hi,int &l,int &r){
    // check for pending lazy updates
    if(lazy[i]!=0){
        int rangeSize= hi -lo + 1;
        seg[i]+=lazy[i]*rangeSize;
        if(lo!=hi){ // send lazy to left and right
           lazy[2*i+1] += lazy[i];
           lazy[2*i+2] += lazy[i];
        }
        lazy[i]=0;
    }
if(r<lo || l>hi) return 0;
if(l<=lo && hi<=r) return seg[i];
int mid=lo+(hi-lo)/2;
int leftMax=getSum(2*i+1,lo,mid,l,r);
int rightMax=getSum(2*i+2,mid+1,hi,l,r);
return (leftMax+rightMax);
}
void updateRange(int i,int lo,int hi,int l,int r,int val){
// check for pending lazy updates
    if(lazy[i]!=0){
        int rangeSize= hi -lo + 1;
        seg[i]+=lazy[i]*rangeSize;
        if(lo!=hi){ // send lazy to left and right
           lazy[2*i+1] += lazy[i];
           lazy[2*i+2] += lazy[i];
        }
        lazy[i]=0;
    }
    if(r<lo || l>hi) return ;
    if(l<=lo && hi<=r){ // update entire low to high
    int rangeSize= hi -lo + 1;
    seg[i] +=  val*rangeSize;
        if(lo!=hi){ // send lazy to left and right
           lazy[2*i+1] += val;
           lazy[2*i+2] += val;
        }
        return;
    }
    int mid=lo+(hi-lo)/2;
    updateRange(2*i+1,lo,mid,l,r,val);
    updateRange(2*i+2,mid+1,hi,l,r,val);
    seg[i]= seg[2*i+1]+seg[2*i+2];
}
int main()
{
int arr[]={1,4,2,8,6,4,9,3};
int n=sizeof(arr)/sizeof(arr[0]);
seg.resize(4*n);
lazy.resize(4*n,0);
build_tree(arr,0,0,n-1);
int l,r;
cout<<endl<<"Enter range of Segment tree:"<<endl;
cin>>l>>r;
cout<<getSum(0,0,n-1,l,r)<<endl;
updateRange(0,0,n-1,2,5,10);
cout<<getSum(0,0,n-1,l,r)<<endl;
return 0;
}
