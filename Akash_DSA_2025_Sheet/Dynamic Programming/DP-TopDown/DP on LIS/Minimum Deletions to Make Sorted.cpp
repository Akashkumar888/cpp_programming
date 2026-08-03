
class Solution {
  public:

    int lowerBound(vector<int> &lis, int target){

        int low = 0;
        int high = lis.size() - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(lis[mid] >= target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        // First index where lis[index] >= target
        return low;
    }

    int minDeletions(vector<int>& arr) {

        vector<int> lis;

        for(int &num : arr){

            if(lis.empty() || lis.back() < num){

                // Extend LIS
                lis.push_back(num);
            }
            else{

                // Replace first element >= num
                int idx = lowerBound(lis, num);
                lis[idx] = num;
            }
        }

        return arr.size() - lis.size();
    }
};