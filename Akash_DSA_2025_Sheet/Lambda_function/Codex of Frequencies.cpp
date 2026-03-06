
#include <bits/stdc++.h>
using namespace std;

typedef pair<char,long long> P;

void user_logic(const string& s) {

    vector<long long> freq(26,0);

    // count frequency
    for(char ch : s){
        if(ch >= 'a' && ch <= 'z')
            freq[ch-'a']++;
    }

    vector<P> odd;

    // collect odd frequencies
    for(int i=0;i<26;i++){
        if(freq[i] % 2 == 1)
            odd.push_back({'a'+i, freq[i]});
    }

    if(odd.size() == 0){
        cout << -1;
        return;
    }

    // comparator
    auto cmp = [&](const P &a, const P &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    };

    // sort
    sort(odd.begin(), odd.end(), cmp);

    if(odd.size() >= 3){

        long long product = 1;

        for(int i=0;i<3;i++){
            cout << odd[i].first << " " << odd[i].second << endl;
            product *= odd[i].second;
        }

        cout << product;
    }
    else{

        char ch = 'z'+1;
        long long val = 0;

        for(auto &p : odd){
            if(p.first < ch){
                ch = p.first;
                val = p.second;
            }
        }

        cout << ch << " " << val;
    }
}

int main() {
    string s;
    getline(cin, s);
    user_logic(s);
    return 0;
}