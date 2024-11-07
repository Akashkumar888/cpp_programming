#include<iostream>
#include<array>
using namespace std;
int main(){
  // int basic [3]={1,2,3};

    array<int,4>a={1,2,4,6};
    int size=a.size();
     // cout<<sizeof(a);
    for(int i=0;i<size;i++){
      cout<<a[i]<<endl;
    }

    cout<<"Element at second index :"<<a.at(1)<<endl;
    cout<<"Element at third  index :"<<a.at(2)<<endl;
    cout<<"Array empty or not :"<<a.empty()<<endl; // answer is boolean

    cout<<"First element :"<<a.front()<<endl;
    cout<<"last  element :"<<a.back()<<endl;
    return 0;
}