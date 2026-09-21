
class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {

        int n = l.size();

        // prefix[i] = total number of valid marks
        // from interval 0 to i
        vector<long long> prefix(n);

        for(int i = 0; i < n; i++){

            int count = r[i] - l[i] + 1;

            if(i == 0){
                prefix[i] = count;
            }
            else{
                prefix[i] = prefix[i - 1] + count;
            }
        }


        vector<int> ans;


        for(int x : rank){

            // Find first interval whose
            // prefix count >= rank
            int low = 0;
            int high = n - 1;

            while(low < high){

                int mid = low + (high - low) / 2;

                if(prefix[mid] >= x){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }


            int i = low;


            // Number of valid marks before this interval
            long long before = (i == 0 ? 0 : prefix[i - 1]);


            // Position inside current interval
            long long position = x - before;


            // Convert rank to actual mark
            int mark = l[i] + position - 1;

            ans.push_back(mark);
        }


        return ans;
    }
};