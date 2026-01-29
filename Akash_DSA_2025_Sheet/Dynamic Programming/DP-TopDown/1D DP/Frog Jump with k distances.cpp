

// Problem Statement
// There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h i.

// There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

// If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of |hi−hj∣ is incurred, where j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.


#include<bits/stdc++.h>
using namespace std;
int solve(int i,int k,vector<int>&arr,vector<int>&dp){
  if(i==0)return 0;
  //   DP Initialization & Base Case Cheatsheet (Top-Down / Memoization Style)
        // ✅ When to use what in recursion + memoization
        // min-chahiye       -> return INT_MAX  (ya large number like 1e9 when not possible)
        // max-chahiye       -> return INT_MIN
        // count-chahiye     -> return 0
        // true-chahiye      -> return false  (base invalid case)
        // false-chahiye     -> return true   (base valid case if needed)
        // sum-chahiye       -> return 0
        // product-chahiye   -> return 1
        // length-chahiye    -> return 0
        // ways-chahiye      -> return 0
        // possible-chahiye  -> return false
        // not-possible-chahiye -> return true
        // string answer chahiye -> return "" (empty string)
        // pair (min,max) chahiye -> return {INT_MAX, INT_MIN}
        // dp state me invalid ka matlab ho -> return -1
        // prefix/suffix dp ke liye base case -> i==0 ya tr==0 -> return 0 ya 1 as per problem
        // invalid state (like tr<0 ya i<0) -> return 1e9 (for min) / 0 (for count) / false (for bool)
  if(dp[i]!=-1)return dp[i];
  int minEnery=INT_MAX;
   // ✅ When to use what in recursion + memoization
        // min-chahiye       -> return INT_MAX  (ya large number like 1e9 when not possible)
        // max-chahiye       -> return INT_MIN
        // count-chahiye     -> return 0
        // true-chahiye      -> return false  (base invalid case)
        // false-chahiye     -> return true   (base valid case if needed)
        // sum-chahiye       -> return 0
        // product-chahiye   -> return 1
        // length-chahiye    -> return 0
        // ways-chahiye      -> return 0
        // possible-chahiye  -> return false
        // not-possible-chahiye -> return true
        // string answer chahiye -> return "" (empty string)
        // pair (min,max) chahiye -> return {INT_MAX, INT_MIN}
        // dp state me invalid ka matlab ho -> return -1
        // prefix/suffix dp ke liye base case -> i==0 ya tr==0 -> return 0 ya 1 as per problem
        // invalid state (like tr<0 ya i<0) -> return 1e9 (for min) / 0 (for count) / false (for bool)
  for(int j=1;j<=k;j++){
   if(i-j>=0) minEnery=min(minEnery,abs(arr[i]-arr[i-j]) + solve(i-j,k,arr,dp));
  }
  return dp[i]=minEnery;
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  vector<int>dp(n+1,-1);
  cout<<solve(n-1,k,arr,dp)<<endl;
  return 0;
}


#include<bits/stdc++.h>
using namespace std;
int solve(int i,int k,vector<int>&arr,vector<int>&dp){
  if(i==0)return 0;
  if(dp[i]!=-1)return dp[i];
  int minEnery=INT_MAX;
  for(int j=1;j<=k;j++){
   if(i-j>=0) minEnery=min(minEnery,abs(arr[i]-arr[i-j]) + solve(i-j,k,arr,dp));
  }
  return dp[i]=minEnery;
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  vector<int>dp(n,0);
  // DP Initialization & Base Case Cheatsheet (Top-Down / Memoization Style)
        // min-chahiye       -> INT_MAX bhr do
        // max-chahiye       -> INT_MIN bhr do
        // count-chahiye     -> 0 bhr do
        // true-chahiye      -> false bhr do
        // false-chahiye     -> true bhr do
        // sum-chahiye       -> 0 bhr do
        // product-chahiye   -> 1 bhr do
        // length-chahiye    -> 0 bhr do
        // ways-chahiye      -> 0 bhr do
        // possible-chahiye  -> false bhr do
        // not-possible-chahiye -> true bhr do
        // string answer chahiye -> "" bhr do (empty string)
        // pair (min,max) chahiye -> {INT_MAX, INT_MIN} bhr do
        // dp state me invalid ka matlab ho -> -1 bhr do
        // prefix/suffix dp ke liye base case -> dp[0] = 0 ya dp[0] = 1 depending on problem
  dp[0]=0;
  //is 100% the correct and golden rule of converting recursion → bottom-up DP.
        //"jitna number of states change ho utna hi loops lagao aur jo pahle se loop hai use rahne do in bottom-up"
        // 🌟 Golden Rules for Converting Recursion → Bottom-Up DP 🌟
        // 1️⃣ No. of changing states → "Jitna number of states change ho utna hi loops lagao"
        //     👉 Here, 2 states → loop for i (index) and sum (target)
        // 2️⃣ Base initialization → "Jo chahiye uske opposite bharo"
        //     👉 We need min → fill with large number (INF)
        // 3️⃣ Transition logic → "Jo pahle se loop hai use rehne do"
        //     👉 pick/notPick same as recursion
        // 4️⃣ Base case → "Starting point aur initial state manually set karo"
        //     👉 dp[i][0] = 0
        // 5️⃣ Final check → "End tak pohchne wale sab possible states check karo"
        //     👉 return dp[m-1][n];
        // fill rest rows
  for(int i=1;i<n;i++){
    int minEnery=INT_MAX;
    for(int j=1;j<=k;j++){
     if(i-j>=0) minEnery=min(minEnery,abs(arr[i]-arr[i-j]) + dp[i-j]);
    }
    dp[i]=minEnery;
  }
  cout<<dp[n-1]<<endl;
  return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int n,k;
  cin>>n>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>dp(n+1);
  dp[0]=0;
  for(int i=1;i<n;i++){
  int step=INT_MAX;
  for(int j=1;j<=k;j++){
    if(i-j>=0){
      int jump= dp[i-j] + abs(arr[i]-arr[i-j]);
      step=min(step,jump);
    }
  }
  dp[i]=step;
  }
  cout<<dp[n-1]<<endl;
  return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // dp[i] only depends on last k values -> use deque to store last k dp values
    deque<int> dq; // stores dp[i-k ... i-1] window
    dq.push_back(0); // base case: dp[0] = 0

    // initial frog energy at position 0
    int currEnergy = 0;

    for (int i = 1; i < n; i++) {
        int minEnergy = INT_MAX;

        // ✅ compute dp[i] using last k dp values stored in dq
        // we simulate dp[i-j] using dq[j] (where j <= k)
        int limit = min(i, k); // don’t go out of bounds

        // we can’t directly use dq[j] because abs(arr[i]-arr[i-j]) changes per jump,
        // so we’ll compute dynamically using indices
        for (int j = 1; j <= limit; j++) {
            int jumpEnergy = dq[dq.size() - j]; // last j-th value corresponds to dp[i-j]
            minEnergy = min(minEnergy, abs(arr[i] - arr[i - j]) + jumpEnergy);
        }

        currEnergy = minEnergy;

        // ✅ maintain deque of last k dp values
        dq.push_back(currEnergy);
        if ((int)dq.size() > k) dq.pop_front();
    }

    cout << currEnergy << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // ✅ dp[i] depends only on last k values → use list to keep last k dp values
    list<int> lastK;   // stores last k dp values
    lastK.push_back(0); // base case → dp[0] = 0

    int currEnergy = 0; // stores dp[i]

    for (int i = 1; i < n; i++) {
        int minEnergy = INT_MAX;
        int j = 1;

        // ✅ compute dp[i] using last k dp values stored in list
        // move from back (latest) to front (oldest)
        for (auto it = lastK.rbegin(); it != lastK.rend() && j <= k; ++it, ++j) {
            // *it = dp[i-j]
            minEnergy = min(minEnergy, abs(arr[i] - arr[i - j]) + *it);
        }

        currEnergy = minEnergy; // dp[i] mil gaya

        // ✅ maintain last k dp values
        lastK.push_back(currEnergy);
        if ((int)lastK.size() > k) lastK.pop_front(); // remove oldest (dp[i-k])
    }

    cout << currEnergy << endl;
    return 0;
}
