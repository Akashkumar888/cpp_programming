#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<int,string>p;
//    p= make_pair(2,"Akash");
p={20,"Akash kumar"};
    cout<<p.first<<" "<<p.second;
    cout<<endl;
    pair<int,string>&p1=p;
    p1.first=3;
    cout<<p.first<<" "<<p.second;
    cout<<endl;
    int a[]={1,2,3};
    int b[]={4,5,6};
    pair<int,int>p_array[3];
    p_array[0]={1,2};
    p_array[1]={3,4};
    p_array[2]={5,6};
    swap(p_array[0],p_array[2]);
    for(int i=0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
return 0;
}