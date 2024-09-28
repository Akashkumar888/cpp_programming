

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    int arr[]={3,1,2,5,4,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int ngi[n];
    stack<int>st;
    ngi[n-1]=n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.size()==0) ngi[i]=n;
        else ngi[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ngi[i]<<" ";
    }
    return 0;
}