#include <stdio.h>
#define ll long long 
ll getxor(ll n){
    switch(n%4){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
}
int main() {
	// your code goes here
ll t,n; scanf("%ll",&t);
while(t--){
    scanf("%ll",&n);
printf("%ll\n",getxor(n));
}
}