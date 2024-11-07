
#include<iostream>
using namespace std;
int main()
{
    int num=10;
    int &temp=num;
    cout<<temp<<endl;
    temp++;
    cout<<temp<<endl;
    cout<<&temp<<endl;
    cout<<&num<<endl;
return 0;
}