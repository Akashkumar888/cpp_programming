#include<iostream>
using namespace std;
int main(){
   int arr[]={1,2,3,4,5};
   int *ptr=arr;
  for(int i=0;i<5;i++){
    cout<<*ptr<<" ";
    ptr++;
  }
  ptr=arr;
  *ptr=8;
  ptr++;
  *ptr=9;
  ptr--;
  cout<<endl;
   for(int i=0;i<5;i++){
    cout<<*ptr<<" ";
    ptr++;
  }
    return 0;
}