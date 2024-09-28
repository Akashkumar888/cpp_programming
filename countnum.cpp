
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double num = 12246754778976;
    
    // Handle case where num is 0
    double count = (num == 0) ? 1 : floor(log10(num) + 1);
    
    cout << "Number of digits: " << count << endl;
    return 0;
}
