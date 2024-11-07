#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(4);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(20);
    cout<<"finding element :"<<binary_search(v.begin(),v.end(),8)<<endl;
    cout<<"lower bound :"<<lower_bound(v.begin(),v.end(),8)-v.begin()<<endl;
    cout<<"upper bound :"<<upper_bound(v.begin(),v.end(),8)-v.begin()<<endl;
    int a=45;
    int b=90;
    cout<<"max  :"<<max(a,b)<<endl;
    cout<<"mini :"<<min(a,b)<<endl;
    swap(a,b);
    cout<<"a :"<<a<<endl<<"b :"<<b<<endl;
    string k="ABCD";
    reverse(k.begin(),k.end());
    cout<<k<<endl;
    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"After rotate :"<<endl;
    for(auto i:v){
        cout<<i<<endl;
    }
    cout<<endl;
    cout<<"After sort:"<<endl;
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<endl;
    }
    cout<<endl;
    return 0;
}