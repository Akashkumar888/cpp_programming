
class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        vector<int> inc(n);
        vector<int> dec(n);
        inc[0]=1;

        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) inc[i]=inc[i-1]+1;
            else inc[i]=1;
        }
        dec[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]) dec[i]=dec[i+1]+1;
            else dec[i]=1;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,inc[i]+dec[i]-1);
        }
        return ans;
    }
};


// Correct Approach

// Think of a mountain.

//           Peak
//            ▲
//           / \
//          /   \
//         /     \

// Every bitonic subarray has

// increasing part
// decreasing part

// Suppose we know
// inc[i] = length of increasing subarray ending at i

// and

// dec[i] = length of decreasing subarray starting from i

// Then if i is the peak,
// answer = inc[i] + dec[i] - 1
// Why -1?
// Because peak is counted twice.

// Step 1
// Compute increasing lengths.
// Example

// 1 2 3 2 1
// inc

// 1
// 2
// 3
// 1
// 1


// inc[0]=1;

// for(i=1;i<n;i++){
//     if(arr[i]>=arr[i-1]) inc[i]=inc[i-1]+1;
//     else inc[i]=1;
// }

// Notice
// Problem says
// <=
// so increasing is non-decreasing
// Hence
// arr[i]>=arr[i-1]

// Step 2
// Compute decreasing lengths from right.
// Example
// 1 2 3 2 1
// dec

// 1
// 1
// 3
// 2
// 1


// dec[n-1]=1;

// for(i=n-2;i>=0;i--){
//     if(arr[i]>=arr[i+1]) dec[i]=dec[i+1]+1;
//     else dec[i]=1;
// }

// Again
// Problem says
// >=
// so decreasing is non-increasing.

// Step 3
// Every index is a possible peak.
// ans=max(ans, inc[i]+dec[i]-1);

// Example
// 12 4 78 90 45 23

// Increasing
// 1 1 2 3 1 1

// Decreasing
// 2 1 1 4 2 1

// Now
// i=0
// 1+2-1=2
// i=1
// 1+1-1=1
// i=2
// 2+1-1=2
// i=3
// 3+4-1=6
// Oops!
// Let's recompute.
// dec
// 23 ->1
// 45 ->2
// 90 ->3
// 78 ->1
// 4 ->1
// 12 ->2

// So
// dec
// 2 1 1 3 2 1
// Now
// peak=90
// 3+3-1 = 5


class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        inc[0]=1;

        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) inc[i]=inc[i-1]+1;
        }
        dec[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]) dec[i]=dec[i+1]+1;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,inc[i]+dec[i]-1);
        }
        return ans;
    }
};


class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) inc[i]=inc[i-1]+1;
        }
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]) dec[i]=dec[i+1]+1;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,inc[i]+dec[i]-1);
        }
        return ans;
    }
};