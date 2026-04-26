class Solution {
  public:
    vector<int> commonElements(vector<int> &arr, vector<int> &brr, vector<int> &crr) {
        // code here
        vector<int>result;
        int i=0,j=0,k=0;
        while(i<arr.size() && j<brr.size() && k<crr.size()){
            if(arr[i]==brr[j] && brr[j]==crr[k]){
                if(result.empty() )result.push_back(arr[i]);
                else if(!result.empty() && arr[i]!=result.back())result.push_back(arr[i]);
                i++,j++,k++;
            }
            else if(arr[i]<crr[k] && brr[j]<crr[k])i++,j++;
            else if(brr[j]<arr[i] && crr[k]<arr[i])j++,k++;
            else if(arr[i]<brr[j] && crr[k]<brr[j])i++,k++;
            else if(arr[i]<brr[j] && arr[i]<crr[k])i++;
            else if(brr[j]<crr[k] && brr[j]<arr[i])j++;
            else k++;
        }
        return result;
    }
};


class Solution {
  public:
    vector<int> commonElements(vector<int> &arr, vector<int> &brr, vector<int> &crr) {
        vector<int> result;
        int i = 0, j = 0, k = 0;

        while(i < arr.size() && j < brr.size() && k < crr.size()){
            
            if(arr[i] == brr[j] && brr[j] == crr[k]){
                if(result.empty() || arr[i] != result.back())
                    result.push_back(arr[i]);
                i++; j++; k++;
            }
            else if(arr[i] < brr[j]){
                i++;
            }
            else if(brr[j] < crr[k]){
                j++;
            }
            else{
                k++;
            }
        }
        return result;
    }
};
