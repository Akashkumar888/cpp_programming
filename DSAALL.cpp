#include <bits/stdc++.h>
using namespace std;

// Type definitions
#define                  ll long long int
#define                  ld double
#define                  ull unsigned long long
#define                  vi vector<ll>
#define                  vs vector<string>
#define                  pii pair<ll,ll>
#define                  mii map<ll,ll>
#define                  ump unordered_map<ll,ll>
#define                  si set<ll>
#define                  usi unordered_set<ll>
#define                  pq_max priority_queue<ll>
#define                  pq_min priority_queue<ll, vi, greater<ll>>
#define                  dq deque<ll>
#define                  li list<ll>

// Utility macros

#define                  endl "\n"
#define                  pb push_back
#define                  mp make_pair
#define                  ff first
#define                  ss second
#define                  mid(l,r) (l+(r-l)/2)

// Loop macros
#define                  loop(i,a,b) for(ll i=(a);i<=(b);i++)
#define                  looprev(i,a,b) for(ll i=(a);i>=(b);i--)

// Constants
#define                  mod 1000000007
#define                  intf 1e18
#define                  f   float
#define                  c   char







































int main() {
    // Example usage of the defined macros and data structures
    vi v = {1, 2, 3, 4, 5};
    pq_max max_heap;
    pq_min min_heap;

    loop(i, 0, v.size()-1) {
        max_heap.push(v[i]);
        min_heap.push(v[i]);
    }

    cout << "Max element: " << max_heap.top() << endl;
    cout << "Min element: " << min_heap.top() << endl;

    return 0;
}
