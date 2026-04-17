
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> temp;
        int i = 0, j = n - 1;

        // alternate small and large
        while (i < j) {
            temp.push_back(arr[i++]);
            temp.push_back(arr[j--]);
        }

        // if odd elements
        if (i == j) temp.push_back(arr[i]);

        long long sum = 0;

        // calculate circular sum
        for (int k = 0; k < n - 1; k++) {
            sum += abs(temp[k] - temp[k + 1]);
        }

        // last + first (circular)
        sum += abs(temp[n - 1] - temp[0]);

        return sum;
    }
};

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long sum=0;
        //  [1, 2, 4, 8]
        sort(arr.begin(),arr.end());
        for(int i=0;i<n/2;i++){
            int last=arr[n-1-i];
            int first=arr[i];
            sum+=abs(last-first);
        }
        return 2*sum;
    }
};
