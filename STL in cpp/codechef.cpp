#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k,l;
	    cin >> n >>k >>l;
	    long long sum=0;
	    vector<int>v;
	    for(int i=0; i<n; i++){
	        int a;
	        cin >> a;
	        v.push_back(a);
	    }
	    sort(v.begin(),v.end());
	    int p=n+1;
	    int tl=0;
	    for(int i=0; i<p; i++){
	        tl++;
	        if(tl==l){
	            sum+=v[n-1];
	        }
	        if(tl==k){
	            tl=0;
	        }
	        v.pop_back();
	        n--;
	    }
	    cout<< sum <<endl;
	}
	return 0;
}
