#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    map<int,int>mp;
    for(int i=0;i<n;i++)mp[arr[i]]++;
    int maxNumber=0;
    int maxCount=0;
    for(auto &it:mp){
        if(maxCount<it.second){
            maxCount=it.second;
            maxNumber=it.first;
        }
    }
    int count=0;
    for(auto &it:mp){
        if(maxCount==it.second)count++;
    }
    if(count==1)cout<<maxNumber<<endl;
    else cout<<"CONFUSED"<<endl;
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> freq(11, 0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    int maxCount = 0;
    int answer = -1;
    int countMax = 0;

    for(int i = 0; i <= 10; i++){
        if(freq[i] > maxCount){
            maxCount = freq[i];
            answer = i;
            countMax = 1;
        }
        else if(freq[i] == maxCount && maxCount != 0){
            countMax++;
        }
    }

    if(countMax == 1) cout << answer << endl;
    else cout << "CONFUSED"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
