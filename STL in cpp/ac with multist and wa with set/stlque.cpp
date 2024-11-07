#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        multiset<long long>bags;
        for(int i=1;i<=n;i++){
            int candy;
            cin>>candy;
            bags.insert(candy);
        }
        long long total=0;
        for(int i=1;i<=k;i++){
            auto last_it=(bags.end());
            last_it--;
            int candy=*last_it;
            total+=candy;
           bags.erase(last_it);
           bags.insert(candy/2);
        }
        cout<<total<<endl;
    }
    return 0;
}