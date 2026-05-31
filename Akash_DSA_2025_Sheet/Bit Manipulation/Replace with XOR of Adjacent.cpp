
class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n=arr.size();
        int first=arr[0]^arr[1];
        int last=arr[n-1]^arr[n-2];
        int second=arr[0]^arr[2];
        for(int i=2;i<n-1;i++){
            int newXor=arr[i-1]^arr[i+1];
            arr[i-1]=second;
            second=newXor;
        }
        arr[n-2]=second;
        arr[0]=first;
        arr[n-1]=last;
    }
};


class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n=arr.size();
        int prev=arr[0];
        for(int i=0;i<n-1;i++){
            int curr=arr[i];
            arr[i]=prev^arr[i+1];
            prev=curr;
        }
        arr[n-1]=prev^arr[n-1];
    }
};



class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp(n);
        temp[0]=arr[0]^arr[1];
        temp[n-1]=arr[n-2]^arr[n-1];
        for(int i=1;i<n-1;i++){
            temp[i]=arr[i-1]^arr[i+1];
        }
        arr=temp;
    }
};



class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>copy=arr;
        arr[0]=copy[0]^copy[1];
        for(int i=1;i<n-1;i++){
            arr[i]=copy[i-1]^copy[i+1];
        }
        arr[n-1]=copy[n-2]^copy[n-1];
    }
};



class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>copy=arr;
        arr[0]=copy[0]^copy[1];
        for(int i=1;i<n-1;i++){
            arr[i]=copy[i-1]^copy[i+1];
        }
        arr[n-1]=copy[n-2]^copy[n-1];
    }
};