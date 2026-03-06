
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n,vector<int>& arr, int k, int mid) {
    int currentSum = 0;
    int trips = 1;

    for(int i=0;i<n;i++) {
        currentSum += arr[i];
        if(currentSum  > mid) {
            currentSum = arr[i];
            trips++;
        } 
        if(trips>k)return false;
    }
    return true;
}

int minimum_diamond_boxes_required(vector<int> arr, int T) {
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);
    int n=arr.size();

    int ans = r;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(isPossible(n,arr, T, mid)) {
            ans = mid;
            r = mid - 1;  // try smaller
        } 
        else {
            l = mid + 1;   // increase capacity
        }
    }
    return ans;
}

int main() {
    int N, T;
    cin >> N;
    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> T;

    cout << minimum_diamond_boxes_required(arr, T) << endl;
}