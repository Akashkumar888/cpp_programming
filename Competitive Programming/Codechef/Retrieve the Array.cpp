
#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    
    vector<long long>arr(n);
    for(int i =0; i<n; i++){
        cin>> arr[i];
    }
    
    long long totalSum = 0;
    for(auto &num : arr){
        totalSum += num;
    }
    // 7 8 9 -> b[0]=7 , 7 8 9->extra 7
    // 7 8 9 -> b[1]=7 8 , 8 9-> extra 8
    // 7 8 9 -> b[2]=7 8 9 , 9-> extra 9
    
    long long x = totalSum/(n+1);
    vector<long long>brr(n);
    for(int i=0;i<n;i++){
        brr[i] = (arr[i]-x);
    }
    for(int i =0; i<n; i++){
        cout<< brr[i]<<" ";
    }
    cout <<endl;
}

int main() {
  int t;
  cin >> t;
  while(t--){
      solve();
  }
}
// always use this format for all problems 
