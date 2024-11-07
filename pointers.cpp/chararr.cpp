#include<iostream>
using namespace std;
int main()
{
    char arr[5]="1234";
    char *ptr=arr;
    cout<<arr<<endl;
    cout<<ptr<<endl;
    cout<<(void*)arr<<endl;
    cout<<static_cast<void*>(arr)<<endl;
    cout<<(void*)ptr<<endl;
return 0;
}