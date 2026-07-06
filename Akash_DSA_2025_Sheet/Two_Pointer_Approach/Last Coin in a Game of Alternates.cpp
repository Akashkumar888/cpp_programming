
class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]<arr[j])j--;
            else i++;
        }
        return arr[i];
    }
};

class Solution {
  public:
    int coin(vector<int>& arr) {

        deque<int>dq;

        for(auto &num : arr){
            dq.push_back(num);
        }

        while(dq.size()>1){

            if(dq.front() > dq.back()){
                dq.pop_front();
            }
            else{
                dq.pop_back();
            }
        }

        return dq.front();
    }
};

class Solution {
  public:

    int solve(int i,int j,
              vector<int>&arr){

        if(i==j){
            return arr[i];
        }

        if(arr[i] > arr[j]){
            return solve(i+1,j,arr);
        }

        return solve(i,j-1,arr);
    }

    int coin(vector<int>& arr) {

        int n=arr.size();

        return solve(0,n-1,arr);
    }
};


class Solution {
  public:
    int coin(vector<int>& arr) {

        int left=0;
        int right=arr.size()-1;

        while(left!=right){

            if(arr[left] > arr[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return arr[left];
    }
};

