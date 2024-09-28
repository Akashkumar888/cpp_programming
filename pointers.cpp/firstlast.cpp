#include<iostream>
using namespace std;
void find(int m,int *p1 ,int *p2){
    *p2=m%10;
    while(m>9){
        m=m/10;
    }
    *p1=m;
}
int main(){
    int n;
    cin>>n;
    int firstdigit;
    int lastdigit;
    int *ptr1=&firstdigit;
    int *ptr2=&lastdigit;
    find(n,ptr1,ptr2);
    cout<<firstdigit<<" "<<lastdigit<<endl;
    return 0;
}