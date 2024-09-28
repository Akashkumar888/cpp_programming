
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void countSort(vector<int>&v){
	int n=v.size();
	int k=v[0];
	for(int i=1;i<n;i++){
		k=max(k,v[i]);
	}
	vector<int>count(k+1,0);
	for(int i=0;i<n;i++){
		count[v[i]]++;
	}
    for(int i=1;i<=k;i++){
    count[i]=count[i]+count[i-1];
	}
	vector<int>output(n);
	for(int i=n-1;i>=0;i--){
		output[-- count [ v[i] ] ]=v[i];
	}
	for(int i=0;i<n;i++){
		v[i]=output[i];
	}
}
int main()
{
	vector<int>arr={1,3,2,3,4,1,6,4,3};
	countSort(arr);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
return 0;
}

// Worst-case: O(N+M)
// Average-case: O(N+M)
// Best-case: O(N+M)