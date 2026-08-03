
class Solution {
  public:
    int find(vector<int>& arr) {

        long long need = 0;

        for(int i = arr.size() - 1; i >= 0; i--){

            need = (need + arr[i] + 1) / 2;
        }

        return need;
    }
};



// The intended solution

// This problem is not solved using binary search.

// The intended solution works backwards from the last element.

// Suppose after processing arr[i] we have value y.

// Before processing arr[i],

// y = 2*x - arr[i]

// y + arr[i] = 2*x 
// So

// x = (y + arr[i]) / 2

// Since x must be an integer and never become negative,

// we compute

// x = ceil((y + arr[i]) / 2)

// Starting from

// y = 0

// and moving from right to left.

// Algorithm
// need = 0

// for i = n-1 ... 0

//     need = ceil((need + arr[i]) / 2)

// answer = need

// To compute ceil division:

// need = (need + arr[i] + 1) / 2;



class Solution {
  public:

    bool isPossible(vector<int>& arr, long long mid){

        long long x = mid;

        for(int i = 0; i < arr.size(); i++){

            if(x > arr[i]){
                x += (x - arr[i]);      // x = 2*x - arr[i]
            }
            else{
                x -= (arr[i] - x);      // x = 2*x - arr[i]
            }

            if(x < 0) return false;
        }

        return true;
    }

    int find(vector<int>& arr) {

        long long l = 1;
        long long r = 1e15;
        long long ans = r;

        while(l <= r){

            long long mid = l + (r - l) / 2;

            if(isPossible(arr, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return (int)ans;
    }
};