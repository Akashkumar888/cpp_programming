#include<iostream>
using namespace std;
int main(){
    int x=45;
    int *ptr1=&x;
    int **ptr2=&ptr1;
    int ***ptr3=&ptr2;
    cout<<x<<endl;
    cout<<*ptr1<<endl;
    cout<<**ptr2<<endl;
    cout<<***ptr3<<endl;
    return 0;
}