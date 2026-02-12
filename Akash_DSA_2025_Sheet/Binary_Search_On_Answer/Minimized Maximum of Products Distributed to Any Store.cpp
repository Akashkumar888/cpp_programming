
class Solution {
public:
bool isPossible(int n,vector<int>&arr,int k,int mid){
    int count=0;
    for(int i=0;i<n;i++){
        count+=(arr[i]+mid-1)/mid;
        if(count>k)return false;
    }
    return true;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int l=1;
        int r=*max_element(quantities.begin(),quantities.end());
        int minProducts=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(m,quantities,n,mid)){
                minProducts=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return minProducts;
    }
};


// 🧠 Universal Rule for Choosing l and r
// 🔥 RULE 1: l = Minimum possible answer
// 🔥 RULE 2: r = Maximum possible answer
// That’s it.
// Now apply it to ANY problem.

// 🧠 Universal Method to Find l and r
// Whenever stuck:
// Ask:
// 1️⃣ What is the smallest answer possible?
// 2️⃣ What is the largest answer possible?
// That becomes your search range.

// 🔥 Universal Examples
// 🟢 Example 1: Minimize Maximum Pages (Book Allocation)
// We minimize max pages.
// Smallest possible max pages:
// l = max(arr)

// Because one book must be assigned.
// Largest possible max pages:
// r = sum(arr)

// Because one student can take all.
// 🟢 Example 2: Aggressive Cows (Maximize Minimum Distance)
// We maximize minimum distance.
// Smallest possible distance:
// l = 1

// Largest possible distance:
// r = max(arr) - min(arr)
// 🟢 Example 3: Koko Eating Bananas
// We minimize speed.
// Smallest speed:
// l = 1
// Largest speed:
// r = max(piles)


// 🔥 Now About Your Code
// Your isPossible is perfect:
// count += (arr[i] + mid - 1) / mid;
// This calculates:
// ceil(arr[i] / mid)

// Stores needed for that product type.
// If total stores needed > n → false.
// Correct logic ✅
