#include <bits/stdc++.h>
using namespace std;

int digitSum(int n){
    int digits=0;
    while(n>0){
        int rem=n%10;
        digits+=rem;
        n=n/10;
    }
    return digits;
}
void solve(){
    int n;
    cin>>n;
    int a,b;
    int count1=0;
    int count2=0;
    while(n--){
    cin>>a>>b;
    int first=digitSum(a);    
    int second=digitSum(b);   
    if(first>second){
        count1++;
    }
    else if(first<second)count2++;
    else {
    count1++;
    count2++;
    }
    }
    if(count1>count2){
        cout<<"0"<<" "<<count1<<endl;
    }
    else if(count1<count2) {
        cout<<"1"<<" "<<count2<<endl;
    }
    else cout<<"2"<<" "<<max(count2,count1)<<endl;
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
