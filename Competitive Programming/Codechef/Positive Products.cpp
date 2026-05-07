#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        long long pos=0;
        long long neg=0;
        for(int i=0;i<n;i++){
            if(arr[i]<0)neg++;
            else if(arr[i]>0)pos++;
        }
        cout<<(neg*(neg-1))/2 + (pos*(pos-1))/2<<"\n";
    }
}
