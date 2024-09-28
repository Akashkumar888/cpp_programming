
#include <iostream>
#include <numeric>
using namespace std;
int main()
{
    int num[16];
    int val;
    cin >> val;
    iota(num,num+16,val);
    cout<<"Elements are: ";
    for(auto i:num)
    {
        cout<<' '<<i;
    }
    return 0;
    
}