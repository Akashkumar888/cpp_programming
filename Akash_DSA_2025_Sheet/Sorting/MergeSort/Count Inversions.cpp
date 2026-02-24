

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j])count++;
            }
        }
        return count;
    }
};

class Solution {
  public:
  int merge(int l,int mid,int r,vector<int>&arr){
      int n1=mid-(l)+1; // left part l to mid like substring length j-i+1
      int n2=r-(mid+1)+1;// right part mid+1 to r like substring length j-i+1
      vector<int>nums1(n1),nums2(n2);
      int count=0;
      int k=l;
      for(int i=0;i<n1;i++){
          nums1[i]=arr[k++];
      }
      for(int j=0;j<n2;j++){
          nums2[j]=arr[k++];
      }
      k=l;
      int i=0,j=0;
      while(i<n1 && j<n2){
          if(nums1[i]<=nums2[j]){
              arr[k++]=nums1[i++];
          }
          else{
              arr[k++]=nums2[j++];
              //pairs of elements (i, j) such that i < j and arr[i] > arr[j].
              count+=(n1-i);//nums1 array is sorted and it's length n1 
          }
      }
      while(i<n1){
          arr[k++]=nums1[i++];
      }
      while(j<n2){
          arr[k++]=nums2[j++];
      }
      return count;
  }
  int mergeSort(int l,int r,vector<int>&arr){
      if(l>=r)return 0;
      int mid=l+(r-l)/2;
      int left=mergeSort(l,mid,arr);
      int right=mergeSort(mid+1,r,arr);
      int result=merge(l,mid,r,arr);
      return left+right+result;
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return mergeSort(0,n-1,arr);
    }
};



class Solution {
  public:
  int merge(int l,int mid,int r,vector<int>&arr){
      vector<int> temp(r - l + 1);

        int i = l;        // left pointer
        int j = mid + 1;  // right pointer
        
        int k = 0;        // temp pointer
        int count = 0;

        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                count += (mid - i + 1);  // remaining left elements
            }
        }

        while(i <= mid) temp[k++] = arr[i++];

        while(j <= r) temp[k++] = arr[j++];

        // copy back to original array
        k = 0;
        while (l <= r) {
            arr[l++] = temp[k++];
        }

        return count;
  }
  int mergeSort(int l,int r,vector<int>&arr){
      if(l>=r)return 0;
      int mid=l+(r-l)/2;
      int left=mergeSort(l,mid,arr);
      int right=mergeSort(mid+1,r,arr);
      int result=merge(l,mid,r,arr);
      return left+right+result;
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return mergeSort(0,n-1,arr);
    }
};


class Solution {
  public:
     // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void  mergesort(int l,int mid,int r,vector<int> &arr){
        int n1=mid-l+1;//  l se mid tk
        int n2=r-(mid+1)+1;// mid+1 se r tk
        int k=l;
        vector<int>nums1(n1),nums2(n2);
        for(int i=0;i<n1;i++){
            nums1[i]=arr[k++];
        }
        for(int j=0;j<n2;j++){
            nums2[j]=arr[k++];
        }
         k=l;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                arr[k]=nums1[i];
                i++,k++;
            }
            else{
                arr[k]=nums2[j];
                k++,j++;
            }
        }
        while(i<n1){
            arr[k]=nums1[i];
            i++,k++;
        }
        while(j<n2){
            arr[k]=nums2[j];
            j++,k++;
        }
    }
    int inversion(int low,int mid,int high,vector<int> &arr){
        int cnt=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && arr[i]>arr[right])right++;
            cnt+=(right-(mid+1));
        }
        return cnt;
    }
   int merge(int l,int r,vector<int> &arr){
        int cnt=0;
        if(l>=r)return cnt;
        int mid=l+(r-l)/2;
        cnt+=merge(l,mid,arr);
        cnt+=merge(mid+1,r,arr);
        cnt+=inversion(l,mid,r,arr);
        mergesort(l,mid,r,arr);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return merge(0,n-1,arr);
    }
};

// Time: O(n log n)
// Space: O(n)

class Solution {
  public:
    int merge(int l, int mid, int r, vector<int>& arr) {
    vector<int> nums(r - l + 1);
    int i = l, j = mid + 1, idx = 0;
    int count = 0; 

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            nums[idx++] = arr[i++];
        } else {
            nums[idx++] = arr[j++];
            count += (mid - i + 1); 
        }
    }

    while (i <= mid) {
        nums[idx++] = arr[i++];
    }
    while (j <= r) {
        nums[idx++] = arr[j++];
    }
    idx = 0;
    while (l <= r) {
        arr[l++] = nums[idx++];
    }

    return count;
}


int mergeSort(int l, int r, vector<int>& arr) {
    int count = 0;
    if (l >= r) return count;

    int mid = l + (r - l) / 2;

    count += mergeSort(l, mid, arr);      
    count += mergeSort(mid + 1, r, arr); 
    count += merge(l, mid, r, arr);      

    return count; 
}

int inversionCount(vector<int>& arr) {
    int n = arr.size();
    return mergeSort(0, n - 1, arr);
}

};


class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long  mergesort(int l,int mid,int r,long long arr[]){
        int n1=mid-l+1;//  l se mid tk
        int n2=r-(mid+1)+1;// mid+1 se r tk
        long long cnt=0;
        int k=l;
        long long nums1[n1],nums2[n2];
        for(int i=0;i<n1;i++){
            nums1[i]=arr[k++];
        }
        for(int j=0;j<n2;j++){
            nums2[j]=arr[k++];
        }
         k=l;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                arr[k]=nums1[i];
                i++,k++;
            }
            else{
                arr[k]=nums2[j];
                k++,j++;
                cnt+=(n1-i);
            }
        }
        while(i<n1){
            arr[k]=nums1[i];
            i++,k++;
        }
        while(j<n2){
            arr[k]=nums2[j];
            j++,k++;
        }
        return cnt;
    }
   long long merge(int l,int r,long long arr[]){
        long long cnt=0;
        if(l>=r)return cnt;
        int mid=l+(r-l)/2;
        cnt+=merge(l,mid,arr);
        cnt+=merge(mid+1,r,arr);
        
        cnt+=mergesort(l,mid,r,arr);
        return cnt;
    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        return merge(0,n-1,arr);
    }
};


// 🎯 First Understand What We Are Counting
// Standard Inversion Definition:
// Count pairs (i, j) such that:
// i < j  AND  arr[i] > arr[j]

// This is the classic inversion problem.
// 🧠 Why We Use count += (n1 - i) ?
// During merge:
// Left  = nums1 (sorted)
// Right = nums2 (sorted)

// When:
// nums1[i] > nums2[j]

// Because left array is sorted:
// nums1[i] > nums2[j]
// nums1[i+1] > nums2[j]
// nums1[i+2] > nums2[j]
// ...
// nums1[n1-1] > nums2[j]
// 👉 So ALL remaining elements in left are greater.
// Total elements remaining in left =
// n1 - i
// So we do:
// count += (n1 - i)

// ✔ This works for condition:
// arr[i] > arr[j]
// 🔴 Now Your Question
// If question says arr[i] < arr[j], then should we use count += (n2 - j)?
// YES ✅
// But depends on what problem is asking.
// 🧩 Case 1: Count arr[i] > arr[j] (Standard Inversion)
// Condition inside merge:
// if(nums1[i] <= nums2[j])
// Else means:
// nums1[i] > nums2[j]
// So count:
// count += (n1 - i)
// ✔ Because left remaining elements are greater.
// 🧩 Case 2: Count arr[i] < arr[j]
// Now suppose problem asks:
// Count pairs such that:
// i < j AND arr[i] < arr[j]

// Now think carefully:
// During merge:
// If:
// nums1[i] < nums2[j]
// Because right array is sorted:

// nums1[i] < nums2[j]
// nums1[i] < nums2[j+1]
// nums1[i] < nums2[j+2]
// ...
// nums1[i] < nums2[n2-1]

// So all remaining elements in right satisfy condition.
// Remaining in right =
// n2 - j
// So:

// count += (n2 - j)
// 🧠 How To Identify Which Formula To Use?
// Ask yourself ONE question:
// 👉 "When condition becomes true, which side's remaining elements will also satisfy it automatically?"
// If condition is:
// nums1[i] > nums2[j]

// Then all remaining in LEFT are greater
// → use (n1 - i)
// If condition is:
// nums1[i] < nums2[j]

// Then all remaining in RIGHT are greater
// → use (n2 - j)
