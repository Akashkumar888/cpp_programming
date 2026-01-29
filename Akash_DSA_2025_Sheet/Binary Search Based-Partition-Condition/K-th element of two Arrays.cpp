
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int m=a.size();
        int n=b.size();
        int cnt=0;
        int i=0,j=0;
        int ans;
        while(i<m && j<n){
            if(a[i]<=b[j]){
                ans=a[i];
                i++;
            }
            else {
                ans=b[j];
                j++;
            }
                cnt++;
            if(cnt==k)return ans;
        }
        while(i<m){
            ans=a[i];
            cnt++;
            i++;
            if(cnt==k)return ans;
        }
        while(j<n){
            ans=b[j];
            cnt++;
            j++;
            if(cnt==k)return ans;
        }
        return -1;
    }
};


class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size(), m = b.size();

        // array to store the merged sorted array
        vector<int> arr(n + m);
        int i = 0, j = 0, d = 0;
        while (i < n && j < m) {
    
            // if the element of a[] is smaller, insert 
            // the element to the sorted array
            if (a[i] < b[j])
                arr[d++] = a[i++];
            
            // if the element of b[] is smaller, insert 
            // the element to the sorted array
            else
                arr[d++] = b[j++];
        }
    
        // push the remaining elements of a[]
        while (i < n)
            arr[d++] = a[i++];
    
        // push the remaining elements of b[]
        while (j < m)
            arr[d++] = b[j++];
    
        return arr[k - 1];
    }
};


class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size(), m = b.size();
        // if a[] has more elements, then call 
        // kthElement with reversed parameters
        if (n > m)return kthElement(b, a, k);
        // binary Search on the number of elements we can
        // include in the first set from a[]
        int lo = max(0, k - m), hi = min(k, n);
        while (lo <= hi) {
            int mid1 = lo + (hi - lo) / 2;
            int mid2 = k - mid1;
            // find elements to the left and right of 
            // partition in a[]
            int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);
            // find elements to the left and right of 
            // partition in b[]
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);
    
            // if it is a valid partition
            if (l1 <= r2 && l2 <= r1) {
              	// find and return the maximum of l1 and l2
                return max(l1, l2);
            }
            // check if we need to take lesser elements from a[]
            if (l1 > r2)hi = mid1 - 1;
    
            // check if we need to take more elements from a[]
            else lo = mid1 + 1;
        }
        return 0;
    }
};

