
class Solution {
public:
void merge(vector<int>&arr,int l,int mid, int r)
    {
         // Your code here
         int n1=mid-l+1; // j-i+1 ki tarah hi length nikalna hai left mid
         int n2=r-(mid+1)+1; // right mid+1
         
         int arr1[n1];
         int arr2[n2];
         int k=l;
         
         for(int i=0;i<n1;i++){
             arr1[i]=arr[k];
             k++;
         }
         
         for(int i=0;i<n2;i++){
             arr2[i]=arr[k];
             k++;
         }
         k=l;
         int i=0,j=0;
         while(i<n1 && j<n2){
             if(arr1[i]<=arr2[j]){
                 arr[k]=arr1[i];
                 k++,i++;
             }
             else{
                 arr[k]=arr2[j];
                 k++,j++;
             }
         }
         
         while(i<n1){
             arr[k]=arr1[i];
             i++,k++;
         }
         while(j<n2){
             arr[k]=arr2[j];
             k++,j++;
         }
        //  delete [] arr1;
        //  delete [] arr2;
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    vector<int> sortArray(vector<int>& arr) {
       int n=arr.size();
       mergeSort(arr,0,n-1);
       return arr;   
    }
};



class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    vector<int> sortArray(vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
        return arr;
    }
};


