// 🔹 Real meaning

// In t minutes, how many donuts can a chef of rank r make?

// 🔹 Time pattern for a chef (VERY IMPORTANT)

// Chef with rank r takes:

// 1st donut → r

// 2nd donut → 2r

// 3rd donut → 3r

// …

// k-th donut → k × r

// So total time for k donuts:

// 𝑟
// (
// 1
// +
// 2
// +
// 3
// +
// ⋯
// +
// 𝑘
// )
// r(1+2+3+⋯+k)
// 🔹 Use sum formula
// 1
// +
// 2
// +
// 3
// +
// ⋯
// +
// 𝑘
// =
// 𝑘
// (
// 𝑘
// +
// 1
// )
// 2
// 1+2+3+⋯+k=
// 2
// k(k+1)
// 	​


// So:

// time
// =
// 𝑟
// ⋅
// 𝑘
// (
// 𝑘
// +
// 1
// )
// 2
// time=r⋅
// 2
// k(k+1)
// 	​

// 🔹 Reverse the problem (IMPORTANT STEP)

// We know time t, want to find max k such that:

// 𝑟
// ⋅
// 𝑘
// (
// 𝑘
// +
// 1
// )
// 2
// ≤
// 𝑡
// r⋅
// 2
// k(k+1)
// 	​

// ≤t

// Multiply both sides by 2:

// 𝑘
// 2
// +
// 𝑘
// ≤
// 2
// 𝑡
// 𝑟
// k
// 2
// +k≤
// r
// 2t
// 	​


// Bring all to one side:

// 𝑘
// 2
// +
// 𝑘
// −
// 2
// 𝑡
// 𝑟
// ≤
// 0
// k
// 2
// +k−
// r
// 2t
// 	​

// ≤0
// 🔹 Apply Dharacharya Formula 🧠

// Standard quadratic:

// 𝑎
// 𝑥
// 2
// +
// 𝑏
// 𝑥
// +
// 𝑐
// =
// 0
// ax
// 2
// +bx+c=0

// Here:

// a = 1

// b = 1

// c = -2t/r

// 𝑘
// =
// −
// 𝑏
// +
// 𝑏
// 2
// −
// 4
// 𝑎
// 𝑐
// 2
// 𝑎
// k=
// 2a
// −b+
// b
// 2
// −4ac

// 𝑘
// =
// −
// 1
// +
// 1
// +
// 8
// 𝑡
// /
// 𝑟
// 2
// k=
// 2
// −1+
// 1+8t/r
// That’s exactly what you coded 👇
// (-1 + sqrt(1 + 8*t/r)) / 2
// ✔ Take positive root only
// ✔ Convert to int → donuts must be integer



class Solution {
public:
  // returns number of donuts a chef with
// rank r can make in time t
int donutsByChef(int t, int r) {
     /*
            Time taken by a chef of rank r:
            1st donut  -> r
            2nd donut  -> 2r
            3rd donut  -> 3r
            ...
            k-th donut -> k*r

            Total time = r * (1 + 2 + ... + k)
                       = r * (k * (k + 1)) / 2

            We know time t, find maximum k such that:
            r * k * (k + 1) / 2 <= t

            => k^2 + k - (2t / r) <= 0

            Using quadratic formula:
            k = (-1 + sqrt(1 + 8*t/r)) / 2
        */

    double D = 1.0 + 8.0 * t / r;
    return int((-1.0 + sqrt(D)) / 2.0);// shri dharacharya -b+-sqrt(b^2-4ac)/2a
}
// Checks if all chefs can make
// at least n donuts in time t
bool isPossible(vector<int>& ranks, int n, int mid) {
    int total=0;
    for (auto &r : ranks){
        total += donutsByChef(mid, r);
        if (total >= n)return true;
    }
    return false;
}
    int minTime(vector<int>& ranks, int n) {
        // code here
        int rmin = *min_element(ranks.begin(),ranks.end());
        int l= 0;
        int r = rmin * n * (n + 1) / 2;
        int minMinutes=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(ranks,n,mid)){
                minMinutes=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return minMinutes;
    }
};