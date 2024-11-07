#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int *p=new int[n];
    for (int i=0;i<n;i++)p[i]=i+1;
    for(int i=0;i<n;i++)cout<<p[i]<<" ";
    delete [] p; // heap memory delete 
return 0;
}