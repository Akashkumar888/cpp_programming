
class Solution {
public:
// Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& nums, int start, int end) {
        // code here
        int pivotElement=nums[end];
        int pos=start;
        for(int i=start;i<end;i++){
              if(nums[i]<=pivotElement){
               swap(nums[pos],nums[i]);
                 pos++;
                }
               }
            swap(nums[pos],nums[end]);
            return pos;
    }
        // Function to sort an array using quick sort algorithm.
     void quickSort(vector<int>& nums, int start, int end) {
        // code here
        if(start>=end)return;
        int pivotIdx=partition(nums,start,end);
        quickSort(nums,start,pivotIdx-1);// smaller part left side 
        quickSort(nums,pivotIdx+1,end);// larger part right side
    }
    vector<int> sortArray(vector<int>& nums) {
       int n=nums.size();
       quickSort(nums,0,n-1);
       return nums;   
    }
};



class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
     void quickSort(vector<int>& nums, int start, int end) {
        // code here
        if(start>=end)return;
        int pivotIdx=partition(nums,start,end);
        quickSort(nums,start,pivotIdx-1);
        quickSort(nums,pivotIdx+1,end);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& nums, int start, int end) {
        // code here
        int pivotElement=nums[end];
        int pos=start;
        for(int i=start;i<end;i++){
              if(nums[i]<=pivotElement){
               swap(nums[pos],nums[i]);
                 pos++;
                    }
               }
               swap(nums[pos],nums[end]);
             return pos;
        }
};


class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& nums, int start, int end) {
        // code here
        if(start>=end)return;
        int pivotIdx=partition(nums,start,end);
        quickSort(nums,start,pivotIdx-1);
        quickSort(nums,pivotIdx+1,end);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& nums, int start, int end) {
        // code here
        int pivotElement=nums[end];
        int pos=start;
        for(int i=start;i<=end;i++){
              if(nums[i]<=pivotElement){
               swap(nums[pos],nums[i]);
                 pos++;
                    }
               }
             return pos-1;
        }
};

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high) return;
            int pivotIndex=partition(arr,low,high);
            quickSort(arr,low,pivotIndex-1);
            quickSort(arr,pivotIndex+1,high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[low];
       int i=low,j=high;
       while(i<j){
           while(arr[i]<=pivot && i<=high){
               i++;
           }
           while(arr[j]>pivot && j>=low){
               j--;
           }
           if(i<j) swap(arr[i],arr[j]);
       }
       swap(arr[low],arr[j]);
       return j;
    }
};

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high) return;
            int pivotIndex=partition(arr,low,high);
            quickSort(arr,low,pivotIndex-1);
            quickSort(arr,pivotIndex+1,high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[low];
       int i=low,j=high;
       while(i<j){
           while(arr[i]<=pivot && i<=high-1){
               i++;
           }
           while(arr[j]>pivot && j>=low+1){
               j--;
           }
           if(i<j) swap(arr[i],arr[j]);
       }
       swap(arr[low],arr[j]);
       return j;
    }
};

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high)return;
        
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[high];
       int pi=low;
       for(int i=low;i<high;i++){
           if(arr[i]<=pivot){
               swap(arr[i],arr[pi]);
               pi++;
           }
       }
       swap(arr[pi],arr[high]);
       return pi;
    }
};


class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        // Randomized pivot to avoid worst case
        int randomIndex = low + rand() % (high - low + 1);
        swap(nums[randomIndex], nums[high]);

        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));   // Seed randomness
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
