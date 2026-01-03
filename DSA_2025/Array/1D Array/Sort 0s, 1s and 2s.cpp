// Dutch National Flag Algorithm 
class Solution {
public:
    void sort012(vector<int>& arr) {
      int n=arr.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;   // only move mid
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};



// 🧠 Easy way to remember
// 0 → send to left (low++)
// 1 → already correct (mid++)
// 2 → send to right (high--)
// No extra space, one pass only.


class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        // Dutch National Flag Algorithm 
        // i for 0
        // j for 1
        // k for 2
        // i mid k
        int n=arr.size();
        int i=0,mid=0,k=n-1;
        while(mid<=k){
            if(arr[mid]==0){
                swap(arr[mid],arr[i]);
                i++,mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[k]);
                k--;
            }
        }
    }
};

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        // Dutch National Flag Algorithm 
        // i for 0
        // j for 1
        // k for 2
        // i mid k
        int n=arr.size();
        int i=0,j=0,k=n-1;
        while(j<=k){
            if(arr[j]==0){
                swap(arr[j],arr[i]);
                i++,j++;
            }
            else if(arr[j]==1){
                j++;
            }
            else if(arr[j]==2){
                swap(arr[j],arr[k]);
                k--;
            }
        }
    }
};

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0, k = n - 1;

        while (j <= k) {
            if (arr[j] == 0) {
                swap(arr[j], arr[i]);
                i++;
                j++;
            }
            else if (arr[j] == 1) {
                j++;
            }
            else { // arr[j] == 2
                swap(arr[j], arr[k]);
                k--;
            }
        }
    }
};
