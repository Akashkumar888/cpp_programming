#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size :";
    cin>>n;
    int a;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>()); // revers sort
    // sort(v.rbegin(), v.rend());
    // sort(v.begin(),v.end());
    // reverse(v.begin(), v.end());
    for(auto x:v){
        cout<<x<<" ";
    }
     cout << endl <<"max: " << v[0] << " " << v[1] <<endl;

     cout<<endl;
     cout<<"Max :"<< *max_element(v.begin(),v.end());
    
     cout<<endl;
     cout<<"Min :"<< *min_element(v.begin(),v.end());
    
    return 0;
}